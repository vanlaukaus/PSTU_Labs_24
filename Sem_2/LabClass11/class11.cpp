#include <iostream>
#include <list>
#include <numeric>

using namespace std;

void processTask1() {
    list<double> container = { 1.5, 2.5, 3.5, 4.5 };
    double sum = accumulate(container.begin(), container.end(), 0.0);
    container.push_back(sum / container.size());
    cout << "Task 1 Result: ";
    for (const auto& val : container) cout << val << " ";
    cout << endl;
}
class Pair {
private:
    int first;
    double second;
public:
    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}
    int getFirst() const { return first; }
    double getSecond() const { return second; }
    void setFirst(int f) { first = f; }
    void setSecond(double s) { second = s; }
    Pair operator-(const Pair& other) const {
        return Pair(first - other.first, second - other.second);
    }

    friend ostream& operator<<(ostream& os, const Pair& p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
};

void processTask2() {
    list<Pair> container = { Pair(1, 1.1), Pair(2, 2.2), Pair(3, 3.3) };
    container.push_back(Pair(4, 4.4));
    container.pop_front();
    cout << "Task 2 Result: ";
    for (const auto& val : container) cout << val << " ";
    cout << endl;
}
#include <stdexcept>
template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };
    Node* head = nullptr;
    int size = 0;
public:
    void push_back(T val) {
        Node** current = &head;
        while (*current) current = &((*current)->next);
        *current = new Node(val);
        size++;
    }
    void addAverage() {
        if (size == 0) throw logic_error("Empty list");
        T sum = T();
        Node* current = head;
        while (current) {
            sum += current->data;
            current = current->next;
        }
        push_back(sum / size);
    }
    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
void processTask3() {
    List<double> container;
    for (double val : {1.0, 2.0, 3.0, 4.0}) container.push_back(val);

    container.addAverage();

    cout << "Task 3 Result: ";
    container.print();
}
#include <queue>
#include <vector>
#include <utility>
void processTask4() {
    using Element = pair<int, double>;
    priority_queue<Element, vector<Element>, greater<Element>> container;
    vector<Element> initializer = {
        make_pair(5, 1.1),
        make_pair(2, 2.2),
        make_pair(7, 3.3)
    };
    for (const Element& elem : initializer) {
        container.push(elem);
    }
    vector<Element> temp;
    while (!container.empty()) {
        Element elem = container.top();
        if (elem.first < 3 || elem.first > 6) {
            temp.push_back(elem);
        }
        container.pop();
    }
    for (const Element& elem : temp) {
        container.push(elem);
    }
    cout << "Task 4 Result: ";
    while (!container.empty()) {
        cout << "(" << container.top().first << "," << container.top().second << ") ";
        container.pop();
    }
    cout << endl;
}
template <typename T>
class PriorityQueueProcessor {
private:
    std::priority_queue<T> container;
public:
    void fill(const std::initializer_list<T>& elements) {
        for (const auto& e : elements) container.push(e);
    }
    void addMinMaxSum() {
        if (container.empty()) return;
        std::vector<T> temp;
        T min_val = container.top();
        T max_val = container.top();
        while (!container.empty()) {
            T val = container.top();
            if (val < min_val) min_val = val;
            if (val > max_val) max_val = val;
            temp.push_back(val);
            container.pop();
        }
        T sum = min_val + max_val;
        for (auto& val : temp) {
            container.push(val + sum);
        }
    }
    void print() {
        std::priority_queue<T> temp = container;
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
};
void processTask5() {
    PriorityQueueProcessor<double> processor;
    processor.fill({ 5.5, 2.2, 7.7, 1.1 });

    processor.addMinMaxSum();

    cout << "Task 5 Result: ";
    processor.print();
}
int main() {
    processTask1();
    processTask2();
    processTask3();
    processTask4();
    processTask5();
    return 0;
}