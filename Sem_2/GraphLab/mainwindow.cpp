#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include <QtMath>

Graph::Graph(int n) : size(n), dist(n, QVector<int>(n, INF)), next(n, QVector<int>(n, -1)) {
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;
    }
}

void Graph::addEdge(int from, int to, int weight) {
    if (from >= 0 && from < size && to >= 0 && to < size && dist[from][to] > weight) {
        dist[from][to] = weight;
        next[from][to] = to;
    }
}

void Graph::floydWarshall() {
    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

EdgeItem::EdgeItem(QPointF source, QPointF dest, int weight, bool directed)
    : src(source), dst(dest), weight(weight), directed(directed) {}

QRectF EdgeItem::boundingRect() const {
    return QRectF(src, dst).normalized().adjusted(-20, -20, 20, 20);
}

void EdgeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::black);
    QLineF line(src, dst);
    painter->drawLine(line);

    if (directed) {
        double angle = std::atan2(-line.dy(), line.dx());
        QPointF arrowP1 = dst - QPointF(sin(angle + M_PI / 3) * 20,
                                        cos(angle + M_PI / 3) * 20);
        QPointF arrowP2 = dst - QPointF(sin(angle + M_PI - M_PI / 3) * 20,
                                        cos(angle + M_PI - M_PI / 3) * 20);
        painter->drawLine(line.p2(), arrowP1);
        painter->drawLine(line.p2(), arrowP2);
    }

    QPointF textPos = (src + dst) / 2 + QPointF(-10, -10);
    painter->drawText(textPos, QString::number(weight));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
    , graph(new Graph(6)) {
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    setupGraph();

    QStringList headers;
    for (int i = 1; i <= 6; ++i)
        headers << QString::number(i);

    ui->initialMatrixTable->setHorizontalHeaderLabels(headers);
    ui->initialMatrixTable->setVerticalHeaderLabels(headers);
    ui->resultMatrixTable->setHorizontalHeaderLabels(headers);
    ui->resultMatrixTable->setVerticalHeaderLabels(headers);

    displayMatrix(graph->dist, ui->initialMatrixTable);
}

MainWindow::~MainWindow() {
    delete ui;
    delete graph;
}

void MainWindow::setupGraph() {
    QVector<QPointF> nodePositions = {
        QPointF(0, 0), QPointF(200, 0), QPointF(200, 200),
        QPointF(0, 200), QPointF(-200, 200), QPointF(-200, 0)
    };

    for (int i = 0; i < 6; ++i) {
        QGraphicsEllipseItem *node = scene->addEllipse(-20, -20, 40, 40, QPen(Qt::black), QBrush(Qt::white));
        node->setPos(nodePositions[i]);
        QGraphicsTextItem *text = scene->addText(QString::number(i + 1));
        text->setPos(nodePositions[i] - QPointF(10, 10));
    }

    struct Edge { int from, to, weight; };
    QVector<Edge> edges = {
        {0, 1, 10}, {0, 3, 28}, {1, 2, 14}, {2, 3, 18},
        {3, 4, 20}, {4, 2, 15}, {4, 5, 30}, {5, 0, 19}
    };

    for (const Edge &e : edges) {
        graph->addEdge(e.from, e.to, e.weight);
        QPointF fromPos = nodePositions[e.from];
        QPointF toPos = nodePositions[e.to];
        scene->addItem(new EdgeItem(fromPos, toPos, e.weight));
    }
}

void MainWindow::displayMatrix(const QVector<QVector<int>> &matrix, QTableWidget *table) {
    table->setRowCount(matrix.size());
    table->setColumnCount(matrix.size());

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            QString text = (matrix[i][j] == Graph::INF) ? "INF" : QString::number(matrix[i][j]);
            QTableWidgetItem *item = new QTableWidgetItem(text);
            item->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, j, item);
        }
    }
}

void MainWindow::on_runFloydButton_clicked() {
    graph->floydWarshall();
    displayMatrix(graph->dist, ui->resultMatrixTable);
}
