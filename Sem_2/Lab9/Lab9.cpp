//v15
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countA(const string& str) {
    int count = 0;
    for (char c : str) {
        if (c == 'A' || c == 'a') {
            count++;
        }
    }
    return count;
}

int main() {
    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cerr << "Failed to create file F1.txt" << endl;
        return 1;
    }

    vector<string> lines = {
        "line",
        "lineeee",
        "line, a",
        "quick brown fox",
        "jumped over",
        "line six. a",
        "line seven",
        "zero",
        "moskva",
        "g",
        "AAAAAAAAAAAAAAA",
        "eeeeee"
    };

    for (const auto& line : lines) {
        f1 << line << endl;
    }
    f1.close();

    int N1, N2;
    cout << "Enter first line number (N1): ";
    cin >> N1;
    cout << "Enter last line number (N2): ";
    cin >> N2;

    if (N1 < 1 || N2 > lines.size() || N1 > N2) {
        cerr << "Error: invalid N1 or N2 values." << endl;
        return 1;
    }

    ifstream inF1("F1.txt");
    ofstream f2("F2.txt");
    if (!inF1.is_open() || !f2.is_open()) {
        cerr << "Failed to open one of the files." << endl;
        return 1;
    }

    string line;
    int currentLine = 0;
    vector<string> f2Lines;

    while (getline(inF1, line)) {
        currentLine++;
        if (currentLine >= N1 && currentLine <= N2) {
            if (!line.empty() && (line.back() == 'A' || line.back() == 'a')) {
                f2 << line << endl;
                f2Lines.push_back(line);
            }
        }
    }

    inF1.close();
    f2.close();

    if (f2Lines.empty()) {
        cout << "File F2 contains no lines ending with 'A'." << endl;
        return 0;
    }

    int maxCount = -1;
    int lineNumber = -1;
    for (int i = 0; i < f2Lines.size(); ++i) {
        int count = countA(f2Lines[i]);
        if (count > maxCount) {
            maxCount = count;
            lineNumber = i + 1;
        }
    }
    cout << "Line in F2 with the most 'A' letters: " << lineNumber << endl;
    cout << "Number of 'A' letters in this line: " << maxCount << endl;

    return 0;
}
