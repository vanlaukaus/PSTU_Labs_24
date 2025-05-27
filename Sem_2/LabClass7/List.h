#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
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
            *current = new Node(node->data);
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
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, List& list) {
        list.clear();
        T value;
        Node** current = &list.head;
        while (is >> value && !(value == T(-1))) { // Terminate on -1 sentinel
            *current = new Node(value);
            list.size++;
            current = &((*current)->next);
        }
        return is;
    }

    T operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
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
            *current = new Node(a->data * b->data);
            result.size++;
            current = &((*current)->next);
            a = a->next;
            b = b->next;
        }
        return result;
    }
};

#endif // LIST_H