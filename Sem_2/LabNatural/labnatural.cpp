#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void distributeSeries(const vector<int>& input, vector<int>& vec1, vector<int>& vec2) {
    if (input.empty()) return;

    vec1.clear();
    vec2.clear();

    int first = input[0];
    vec1.push_back(first);

    bool flag = true;

    for (size_t i = 1; i < input.size(); ++i) {
        int second = input[i];
        if (second < first) {
            flag = !flag;
        }

        if (flag) {
            vec1.push_back(second);
        }
        else {
            vec2.push_back(second);
        }

        first = second;
    }
}

void mergeSeries(vector<int>& output, const vector<int>& vec1, const vector<int>& vec2) {
    output.clear();
    size_t i = 0, j = 0;

    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] <= vec2[j]) {
            output.push_back(vec1[i]);
            i++;
        }
        else {
            output.push_back(vec2[j]);
            j++;
        }
    }

    while (i < vec1.size()) {
        output.push_back(vec1[i]);
        i++;
    }

    while (j < vec2.size()) {
        output.push_back(vec2[j]);
        j++;
    }
}

void naturalSort(vector<int>& data) {
    bool sorted = false;
    vector<int> vec1, vec2;

    while (!sorted) {
        distributeSeries(data, vec1, vec2);

        if (vec2.empty()) {
            sorted = true;
            data = move(vec1);
        }
        else {
            mergeSeries(data, vec1, vec2);
        }
    }
}

int main() {
    srand(time(0));
    vector<int> data;

    // Генерация случайных данных
    for (int i = 0; i < 10; ++i) {
        data.push_back(rand() % 100);
    }

    cout << "Original data: ";
    for (int val : data) {
        cout << val << ' ';
    }
    cout << '\n';

    naturalSort(data);

    cout << "Sorted data: ";
    for (int val : data) {
        cout << val << ' ';
    }
    cout << '\n';

    return 0;
}