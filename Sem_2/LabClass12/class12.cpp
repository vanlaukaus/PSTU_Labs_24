#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Pair {
    int first;
    double second;

public:
    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}
    Pair operator+(const Pair& other) const {
        return Pair(first + other.first, second + other.second);
    }

    Pair operator/(size_t divisor) const {
        return Pair(first, second / divisor);
    }

    bool operator<(const Pair& other) const {
        return first < other.first || 
              (first == other.first && second < other.second);
    }

    friend ostream& operator<<(ostream& os, const Pair& p);
};
ostream& operator<<(ostream& os, const Pair& p) {
    return os << p.first << ":" << p.second;
}
template <typename T>
class List {
    vector<T> data;

public:
    void addAverage() {
        if (data.empty()) return;
        
        T total = accumulate(data.begin(), data.end(), T());
        T avg = total / data.size();
        data.push_back(avg);
    }
    void removeInRange(const T& min_val, const T& max_val) {
        sort(data.begin(), data.end());
        auto lower = lower_bound(data.begin(), data.end(), min_val);
        auto upper = upper_bound(data.begin(), data.end(), max_val);
        data.erase(lower, upper);
    }
    void addMinMaxSum() {
        if (data.empty()) return;
        
        auto min_it = min_element(data.begin(), data.end());
        auto max_it = max_element(data.begin(), data.end());
        T sum = *min_it + *max_it;
        
        for (auto& elem : data) {
            elem = elem + sum;
        }
    }
    void insert(const T& val) {
        data.push_back(val);
    }
    void print() const {
        for (const auto& elem : data) {
            cout << elem << " ";
        }
        cout << endl;
    }
};
int main() {
    List<Pair> list;

    list.insert(Pair(2, 3.5));
    list.insert(Pair(4, 1.2));
    list.insert(Pair(1, 5.0));
    list.insert(Pair(3, 2.8));

    cout << "Original list: ";
    list.print();

    list.addAverage();
    cout << "After adding average: ";
    list.print();

    list.removeInRange(Pair(2, 0), Pair(3, 10));
    cout << "After range removal: ";
    list.print();

    list.addMinMaxSum();
    cout << "After adding min/max sum: ";
    list.print();

    return 0;
}