#include <iostream>
#include <stdexcept>

class List {
private:
    struct Node {
        int key;
        Node* next;
        Node(int k) : key(k), next(nullptr) {}
    };
    Node* head;
    int size;

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

public:
    List() : head(nullptr), size(0) {}

    List(const List& other) : head(nullptr), size(0) {
        Node** current = &head;
        for (Node* node = other.head; node != nullptr; node = node->next) {
            *current = new Node(node->key);
            size++;
            current = &((*current)->next);
        }
    }

    ~List() {
        clear();
    }

    List& operator=(const List& other) {
        if (this != &other) {
            List temp(other);
            std::swap(head, temp.head);
            std::swap(size, temp.size);
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list) {
        Node* current = list.head;
        while (current != nullptr) {
            os << current->key << " ";
            current = current->next;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, List& list) {
        list.clear();
        int value;
        Node** current = &list.head;
        while (is >> value && value != -1) {
            *current = new Node(value);
            list.size++;
            current = &((*current)->next);
        }
        return is;
    }

    int operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->key;
    }

    operator int() const {
        return size;
    }

    List operator*(const List& other) const {
        List result;
        Node* a = head;
        Node* b = other.head;
        Node** current = &result.head;
        while (a != nullptr && b != nullptr) {
            *current = new Node(a->key * b->key);
            result.size++;
            current = &((*current)->next);
            a = a->next;
            b = b->next;
        }
        return result;
    }

    class iterator {
    private:
        Node* current;
    public:
        iterator(Node* node = nullptr) : current(node) {}
        iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }
        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        int operator*() const {
            return current->key;
        }
        bool operator==(const iterator& other) const {
            return current == other.current;
        }
        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }
        iterator operator+(int n) {
            iterator temp = *this;
            for (int i = 0; i < n && temp.current != nullptr; ++i) {
                temp.current = temp.current->next;
            }
            return temp;
        }
    };

    iterator begin() const {
        return iterator(head);
    }

    iterator end() const {
        return iterator(nullptr);
    }
};

int main() {
    List list1, list2;

    std::cout << "Enter elements for list1 (end with -1): ";
    std::cin >> list1;
    std::cout << "Enter elements for list2 (end with -1): ";
    std::cin >> list2;

    std::cout << "List1: " << list1 << std::endl;
    std::cout << "List2: " << list2 << std::endl;

    List list3 = list1 * list2;
    std::cout << "List1 * List2: " << list3 << std::endl;

    std::cout << "Size of list1: " << static_cast<int>(list1) << std::endl;

    try {
        std::cout << "Element at index 2 in list1: " << list1[2] << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    List::iterator it = list1.begin();
    it = it + 2;
    if (it != list1.end()) {
        std::cout << "Element at position 2: " << *it << std::endl;
    }
    else {
        std::cout << "Position 2 is out of bounds." << std::endl;
    }

    return 0;
}