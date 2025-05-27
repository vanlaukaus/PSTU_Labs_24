#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QGraphicsTextItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene(this)),
    balancedRoot(nullptr), searchRoot(nullptr) {
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow() {
    delete balancedRoot;
    delete searchRoot;
    delete ui;
}

void MainWindow::on_buildTreeButton_clicked() {
    int n = QInputDialog::getInt(this, "Nodes", "Enter number of nodes:");
    std::vector<char*> data;
    for (int i = 0; i < n; ++i) {
        QString str = QInputDialog::getText(this, "Node", "Enter node data:");
        data.push_back(strdup(str.toLocal8Bit().data()));
    }
    delete balancedRoot;
    balancedRoot = buildBalancedTree(data.data(), 0, n-1);
    visualizeTree(balancedRoot);
    for (auto ptr : data) delete[] ptr;
}

void MainWindow::visualizeTree(TreeNode* root) {
    scene->clear();
    if (!root) return;

    struct DrawParams { int x; int y; int hSpacing; int vSpacing; };
    std::function<void(TreeNode*, DrawParams)> drawNode = [&](TreeNode* node, DrawParams p) {
        QGraphicsTextItem* text = scene->addText(node->data);
        text->setPos(p.x - text->boundingRect().width()/2, p.y);
        if (node->left) {
            int leftX = p.x - p.hSpacing;
            int leftY = p.y + p.vSpacing;
            scene->addLine(p.x, p.y + 20, leftX, leftY);
            drawNode(node->left, {leftX, leftY, p.hSpacing/2, p.vSpacing});
        }
        if (node->right) {
            int rightX = p.x + p.hSpacing;
            int rightY = p.y + p.vSpacing;
            scene->addLine(p.x, p.y + 20, rightX, rightY);
            drawNode(node->right, {rightX, rightY, p.hSpacing/2, p.vSpacing});
        }
    };

    drawNode(root, {400, 50, 200, 100});
}

void MainWindow::on_convertButton_clicked() {
    delete searchRoot;
    searchRoot = convertToSearchTree(balancedRoot);
    visualizeTree(searchRoot);
}

void MainWindow::on_countButton_clicked() {
    QString target = QInputDialog::getText(this, "Input", "Enter target character:");
    if (target.isEmpty()) return;
    int count = countStartingWith(balancedRoot, target.at(0).toLatin1());
    QMessageBox::information(this, "Result", QString("Count: %1").arg(count));
}
