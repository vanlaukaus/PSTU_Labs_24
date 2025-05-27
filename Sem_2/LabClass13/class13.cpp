#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>

class Pair {
private:
    int first;
    double second;
public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}
    int getFirst() const { return first; }
    double getSecond() const { return second; }
    void setFirst(int f) { first = f; }
    void setSecond(double s) { second = s; }

    bool operator<(const Pair& other) const {
        return first < other.first || (first == other.first && second < other.second);
    }

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }
};

std::ostream& operator<<(std::ostream& os, const Pair& p) {
    os << "(" << p.getFirst() << ", " << p.getSecond() << ")";
    return os;
}

void executeTask1() {
    std::list<Pair> container = { {3, 1.5}, {1, 2.7}, {4, 3.2}, {2, 4.8} };
    
    std::replace_if(container.begin(), container.end(),
        [](const Pair& p) { return p.getFirst() > 2; }, Pair(-1, -1.0));

    container.remove_if([](const Pair& p) { return p.getSecond() < 3.0; });

    container.sort([](const Pair& a, const Pair& b) { return a.getFirst() < b.getFirst(); });
    std::cout << "Sorted ascending: ";
    for (const auto& p : container) std::cout << p << " ";

    container.sort([](const Pair& a, const Pair& b) { return a.getFirst() > b.getFirst(); });
    std::cout << "\nSorted descending: ";

    auto it = std::find_if(container.begin(), container.end(),
        [](const Pair& p) { return p.getFirst() == 2; });
    if (it != container.end()) std::cout << "\nFound: " << *it;

    int sum = std::accumulate(container.begin(), container.end(), 0,
        [](int acc, const Pair& p) { return acc + p.getFirst(); });
    container.emplace_back(sum / static_cast<int>(container.size()), 0.0);
    std::cout << "\nAfter average: " << container.back();
}

void executeTask2() {
    std::priority_queue<Pair> container;
    for (const auto& p : { Pair(3, 1.5), Pair(1, 2.7), Pair(4, 3.2), Pair(2, 4.8) }) {
        container.push(p);
    }

    std::priority_queue<Pair> temp;
    while (!container.empty()) {
        if (container.top().getSecond() >= 3.0) temp.push(container.top());
        container.pop();
    }
    container = std::move(temp);

    std::cout << "\nPriority Queue: ";
    while (!container.empty()) {
        std::cout << container.top() << " ";
        container.pop();
    }
}

void executeTask3() {
    std::map<int, Pair> container = {
        {3, Pair(3, 1.5)}, {1, Pair(1, 2.7)}, {4, Pair(4, 3.2)}, {2, Pair(2, 4.8)}
    };

    auto lower = container.lower_bound(2);
    auto upper = container.upper_bound(3);
    container.erase(lower, upper);

    if (!container.empty()) {
        auto [minIt, maxIt] = std::minmax_element(container.begin(), container.end());
        int sum = minIt->second.getFirst() + maxIt->second.getFirst();
        std::for_each(container.begin(), container.end(),
            [sum](auto& pair) { pair.second.setFirst(pair.second.getFirst() + sum); });
    }

    std::cout << "\nMap contents: ";
    for (const auto& [k, v] : container) std::cout << k << "->" << v << " ";
}

int main() {
    std::cout << "Task 1 Results:\n";
    executeTask1();

    std::cout << "\n\nTask 2 Results:\n";
    executeTask2();

    std::cout << "\n\nTask 3 Results:\n";
    executeTask3();

    return 0;
}
