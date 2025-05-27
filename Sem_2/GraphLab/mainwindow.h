#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QVector>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class Graph {
public:
    static const int INF = 1e9;
    int size;
    QVector<QVector<int>> dist;
    QVector<QVector<int>> next;

    Graph(int n);
    void addEdge(int from, int to, int weight);
    void floydWarshall();
};

class EdgeItem : public QGraphicsItem {
public:
    EdgeItem(QPointF source, QPointF dest, int weight, bool directed = true);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPointF src, dst;
    int weight;
    bool directed;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_runFloydButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Graph *graph;

    void setupGraph();
    void displayMatrix(const QVector<QVector<int>> &matrix, QTableWidget *table);
};

#endif // MAINWINDOW_H
