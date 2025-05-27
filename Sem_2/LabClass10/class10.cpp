#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Pair {
private:
    int first;
    double second;
public:
    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}

    int getFirst() const { return first; }
    double getSecond() const { return second; }

    Pair operator+(int x) const {
        return Pair(first + x, second);
    }

    Pair operator+(double x) const {
        return Pair(first, second + x);
    }

    Pair operator-(const Pair& other) const {
        return Pair(first - other.first, second - other.second);
    }

    bool operator<(const Pair& other) const {
        if (first != other.first)
            return first < other.first;
        return second < other.second;
    }

    bool operator==(const Pair& other) const {
        return (first == other.first) && (second == other.second);
    }

    friend ostream& operator<<(ostream& os, const Pair& p) {
        os << p.first << ":" << p.second;
        return os;
    }
};
void createObjects() {
    ofstream out("data.txt", ios::app);
    if (!out) {
        cerr << "Error opening file." << endl;
        return;
    }
    char choice;
    do {
        int a;
        double b;
        cout << "Enter integer part: ";
        cin >> a;
        cout << "Enter double part: ";
        cin >> b;
        out << a << " " << b << "\n";
        cout << "Add another? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    out.close();
}
void viewObjects() {
    ifstream in("data.txt");
    if (!in) {
        cerr << "Error opening file." << endl;
        return;
    }
    int a;
    double b;
    while (in >> a >> b) {
        Pair p(a, b);
        cout << p << endl;
    }
    in.close();
}
void deleteLessThan() {
    vector<Pair> pairs;
    ifstream in("data.txt");
    int a; double b;
    while (in >> a >> b) {
        pairs.emplace_back(a, b);
    }
    in.close();

    int ta;
    double tb;
    cout << "Enter target pair (integer and double): ";
    cin >> ta >> tb;
    Pair target(ta, tb);

    vector<Pair> newPairs;
    for (const auto& p : pairs) {
        if (!(p < target)) {
            newPairs.push_back(p);
        }
    }

    ofstream out("data.txt");
    for (const auto& p : newPairs) {
        out << p.getFirst() << " " << p.getSecond() << "\n";
    }
    out.close();
}
void increaseByL() {
    vector<Pair> pairs;
    ifstream in("data.txt");
    int a; double b;
    while (in >> a >> b) {
        pairs.emplace_back(a, b);
    }
    in.close();

    int ta;
    double tb;
    cout << "Enter target pair: ";
    cin >> ta >> tb;
    Pair target(ta, tb);

    char type;
    cout << "Is L an integer (i) or double (d)? ";
    cin >> type;
    if (type != 'i' && type != 'd') {
        cerr << "Invalid type." << endl;
        return;
    }

    if (type == 'i') {
        int L;
        cout << "Enter integer L: ";
        cin >> L;
        for (auto& p : pairs) {
            if (p == target) {
                p = p + L;
            }
        }
    }
    else {
        double L;
        cout << "Enter double L: ";
        cin >> L;
        for (auto& p : pairs) {
            if (p == target) {
                p = p + L;
            }
        }
    }

    ofstream out("data.txt");
    for (const auto& p : pairs) {
        out << p.getFirst() << " " << p.getSecond() << "\n";
    }
    out.close();
}
void addKAfterPosition() {
    vector<Pair> pairs;
    ifstream in("data.txt");
    int a; double b;
    while (in >> a >> b) {
        pairs.emplace_back(a, b);
    }
    in.close();

    int pos, K;
    cout << "Enter position: ";
    cin >> pos;
    if (pos < 0 || pos >= pairs.size()) {
        cerr << "Invalid position." << endl;
        return;
    }
    cout << "Enter K: ";
    cin >> K;
    vector<Pair> newPairs;
    for (int i = 0; i <= pos; ++i) {
        newPairs.push_back(pairs[i]);
    }
    for (int i = 0; i < K; ++i) {
        int a;
        double b;
        cout << "Enter pair " << (i + 1) << ":\n";
        cout << "Integer part: ";
        cin >> a;
        cout << "Double part: ";
        cin >> b;
        newPairs.emplace_back(a, b);
    }
    for (size_t i = pos + 1; i < pairs.size(); ++i) {
        newPairs.push_back(pairs[i]);
    }
    ofstream out("data.txt");
    for (const auto& p : newPairs) {
        out << p.getFirst() << " " << p.getSecond() << "\n";
    }
    out.close();
}
int main() {
    int choice;
    do {
        cout << "Menu:\n"
            << "1. Create pairs\n"
            << "2. View pairs\n"
            << "3. Delete pairs less than target\n"
            << "4. Increase pairs equal to target by L\n"
            << "5. Add K pairs after position\n"
            << "6. Exit\n"
            << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            createObjects();
            break;
        case 2:
            viewObjects();
            break;
        case 3:
            deleteLessThan();
            break;
        case 4:
            increaseByL();
            break;
        case 5:
            addKAfterPosition();
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}