#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

class Intlist {
private:
    std::vector<int> data;
public:
    Intlist(const std::vector<int>& input = {}) : data(input) {}

    int& operator[](size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    operator int() const {
        return data.size();
    }
    Intlist operator*(const Intlist& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Lists must be of the same length");
        }
        std::vector<int> result;
        for (size_t i = 0; i < data.size(); ++i) {
            result.push_back(data[i] * other.data[i]);
        }
        return Intlist(result);
    }

    int operator+(int n) const {
        if (n < 0 || static_cast<size_t>(n) >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[n];
    }
};
int getInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error: enter an integer!\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}
int main() {
    try {
        Intlist list({ 1, 2, 3, 4, 5 });
        int index = getInput("Enter index to access the list element (0-4): ");
        std::cout << "list[" << index << "] = " << list[index] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Intlist list({ 10, 20, 30, 40 });
        int n = getInput("Enter index for operator + (0-3): ");
        std::cout << "list + " << n << " = " << (list + n) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}