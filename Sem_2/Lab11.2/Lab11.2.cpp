#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    Node* prev;
    Node* next;
    Node(const string& k) : key(k), prev(nullptr), next(nullptr) {}
};

class doublist {
    Node* head;
    Node* tail;
public:
    doublist() : head(nullptr), tail(nullptr) {}

    void append(const string& key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void dellas(int k) {
        if (!tail) return;
        Node* current = tail;
        while (k-- && current) {
            Node* toDelete = current;
            current = current->prev;
            delete toDelete;
        }
        if (current) {
            current->next = nullptr;
            tail = current;
        }
        else {
            head = tail = nullptr;
        }
    }

    void insaft(const string& afterKey, const string& newKey) {
        Node* t = head;
        while (t) {
            if (t->key == afterKey) {
                Node* newNode = new Node(newKey);
                newNode->next = t->next;
                newNode->prev = t;
                if (t->next) {
                    t->next->prev = newNode;
                }
                else {
                    tail = newNode;
                }
                t->next = newNode;
                return;
            }
            t = t->next;
        }
        append(newKey);
    }

    void print() const {
        Node* t = head;
        cout << "List forward: ";
        while (t) {
            cout << t->key << " <-> ";
            t = t->next;
        }
        cout << "NULL\n";

        t = tail;
        cout << "List backward: ";
        while (t) {
            cout << t->key << " <-> ";
            t = t->prev;
        }
        cout << "NULL\n";
    }

    ~doublist() {
        while (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
    }
};

int main() {
    doublist list;
    list.append("A");
    list.append("B");
    list.append("C");
    list.append("D");
    list.print();

    cout << "Deleting last 2 elements \n";
    list.dellas(2);
    list.print();

    cout << "Inserting 'X' after 'B' \n";
    list.insaft("B", "X");
    list.print();

    return 0;
}