#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <queue>
#include <climits>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Node {
    std::vector<std::vector<int>> matrix;
    std::vector<int> path;
    long long lower_bound;
    bool operator>(const Node& other) const {
        return lower_bound > other.lower_bound;
    }
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_solveButton_clicked();
    void on_nextStepButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<int>> initialMatrix;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    long long bestCost;
    std::vector<int> bestPath;

    void displayMatrix(const std::vector<std::vector<int>>& matrix);
    long long reduceMatrix(std::vector<std::vector<int>>& mat);
    std::pair<int, int> selectEdge(const std::vector<std::vector<int>>& mat);
};

#endif // MAINWINDOW_H
