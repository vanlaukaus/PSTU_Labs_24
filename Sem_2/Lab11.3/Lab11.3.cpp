#include <iostream>
#include <string>
using namespace std;

struct stackn {
    string key;
    stackn* next;
    stackn(const string& k) : key(k), next(nullptr) {}
};

class Stack {
    stackn* top;
public:
    Stack() : top(nullptr) {}

    void push(const string& key) {
        stackn* newNode = new stackn(key);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (!top) return "";
        stackn* temp = top;
        string key = temp->key;
        top = top->next;
        delete temp;
        return key;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void print() const {
        stackn* temp = top;
        cout << "Stack (top to bottom): ";
        while (temp) {
            cout << temp->key << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~Stack() {
        while (top) {
            stackn* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;
    stack.push("A");
    stack.push("B");
    stack.push("C");
    stack.push("D");
    stack.print();

    cout << "Popping 2 elements\n";
    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}