#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "tree.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_buildTreeButton_clicked();
    void on_convertButton_clicked();
    void on_countButton_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* scene;
    TreeNode* balancedRoot;
    TreeNode* searchRoot;

    void visualizeTree(TreeNode* root);
};

#endif
