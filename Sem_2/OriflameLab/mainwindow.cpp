#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <algorithm>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initialMatrix = {
        {INT_MAX, 5, 11, 9},
        {10, INT_MAX, 8, 7},
        {7, 14, INT_MAX, 8},
        {12, 6, 15, INT_MAX}
    };
    displayMatrix(initialMatrix);
    bestCost = LLONG_MAX;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayMatrix(const std::vector<std::vector<int>>& matrix) {
    ui->matrixTable->setRowCount(matrix.size());
    ui->matrixTable->setColumnCount(matrix[0].size());
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem();
            if (matrix[i][j] == INT_MAX) {
                item->setText("∞");
            } else {
                item->setText(QString::number(matrix[i][j]));
            }
            ui->matrixTable->setItem(i, j, item);
        }
    }
}

long long MainWindow::reduceMatrix(std::vector<std::vector<int>>& mat) {
    long long cost = 0;
    // Reduce rows
    for (auto& row : mat) {
        int min_val = INT_MAX;
        for (int val : row) {
            if (val < min_val && val != INT_MAX)
                min_val = val;
        }
        if (min_val != INT_MAX) {
            cost += min_val;
            for (int& val : row) {
                if (val != INT_MAX)
                    val -= min_val;
            }
        }
    }
    // Reduce columns
    for (size_t j = 0; j < mat[0].size(); ++j) {
        int min_val = INT_MAX;
        for (size_t i = 0; i < mat.size(); ++i) {
            if (mat[i][j] < min_val && mat[i][j] != INT_MAX)
                min_val = mat[i][j];
        }
        if (min_val != INT_MAX && min_val > 0) {
            cost += min_val;
            for (size_t i = 0; i < mat.size(); ++i) {
                if (mat[i][j] != INT_MAX)
                    mat[i][j] -= min_val;
            }
        }
    }
    return cost;
}

std::pair<int, int> MainWindow::selectEdge(const std::vector<std::vector<int>>& mat) {
    int max_penalty = -1;
    std::pair<int, int> edge(-1, -1);
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[i].size(); ++j) {
            if (mat[i][j] == 0) {
                int row_min = INT_MAX;
                for (size_t k = 0; k < mat[i].size(); ++k) {
                    if (k != j && mat[i][k] < row_min)
                        row_min = mat[i][k];
                }
                int col_min = INT_MAX;
                for (size_t k = 0; k < mat.size(); ++k) {
                    if (k != i && mat[k][j] < col_min)
                        col_min = mat[k][j];
                }
                int penalty = (row_min == INT_MAX ? 0 : row_min) + (col_min == INT_MAX ? 0 : col_min);
                if (penalty > max_penalty) {
                    max_penalty = penalty;
                    edge = {i, j};
                }
            }
        }
    }
    return edge;
}

void MainWindow::on_solveButton_clicked() {
    Node root;
    root.matrix = initialMatrix;
    root.lower_bound = reduceMatrix(root.matrix);
    root.path = {0};
    pq.push(root);
    bestCost = LLONG_MAX;
    ui->infoText->append("Algorithm started. Root lower bound: " + QString::number(root.lower_bound));
}

void MainWindow::on_nextStepButton_clicked() {
    if (pq.empty()) {
        ui->infoText->append("All nodes processed. Best cost: " + QString::number(bestCost));
        return;
    }

    Node current = pq.top();
    pq.pop();

    displayMatrix(current.matrix);
    ui->infoText->append("\nCurrent node:");
    ui->infoText->append("Lower bound: " + QString::number(current.lower_bound));

    if (current.path.size() == 4) {
        int return_cost = initialMatrix[current.path.back()][0];
        if (return_cost == INT_MAX) {
            ui->infoText->append("Invalid path: no return to start city");
            return;
        }
        long long cost = current.lower_bound + return_cost;
        if (cost < bestCost) {
            bestCost = cost;
            bestPath = current.path;
            bestPath.push_back(0);
            ui->infoText->append("New best path found. Cost: " + QString::number(bestCost));
        }
        return;
    }

    auto edge = selectEdge(current.matrix);
    if (edge.first == -1) return;

    // Include edge
    Node include = current;
    include.matrix[edge.first][edge.second] = INT_MAX;
    include.lower_bound += reduceMatrix(include.matrix);
    if (std::find(include.path.begin(), include.path.end(), edge.second) == include.path.end()) {
        include.path.push_back(edge.second);
        pq.push(include);
    } else {
        ui->infoText->append("Edge (" + QString::number(edge.first) + ", " + QString::number(edge.second) + ") leads to visited city. Skipped.");
    }

    // Exclude edge
    Node exclude = current;
    exclude.matrix[edge.first][edge.second] = INT_MAX;
    exclude.lower_bound += reduceMatrix(exclude.matrix);
    pq.push(exclude);

    ui->infoText->append("Selected edge: (" + QString::number(edge.first) + ", " + QString::number(edge.second) + ")");
}
