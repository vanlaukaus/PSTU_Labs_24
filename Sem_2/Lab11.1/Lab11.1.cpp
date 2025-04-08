#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    Node* next;
    Node(const string& k) : key(k), next(nullptr) {}
};

class linklist {
    Node* head;
public:
    linklist() : head(nullptr) {}

    void append(const string& key) {
        Node* newNode = new Node(key);
        if (!head) {
            head = newNode;
            return;
        }
        Node* t = head;
        while (t->next) {
            t = t->next;
        }
        t->next = newNode;
    }

    void dellas(int k) {
        if (!head) return;
        int count = 0;
        Node* t = head;
        while (t) {
            count++;
            t = t->next;
        }
        if (k >= count) {
            while (head) {
                Node* del = head;
                head = head->next;
                delete del;
            }
            return;
        }
        int target = count - k;
        t = head;
        for (int i = 1; i < target; ++i) {
            t = t->next;
        }
        while (k--) {
            Node* del = t->next;
            t->next = del ? del->next : nullptr;
            delete del;
        }
    }

    void insaft(const string& afterKey, const string& newKey) {
        Node* t = head;
        while (t) {
            if (t->key == afterKey) {
                Node* newNode = new Node(newKey);
                newNode->next = t->next;
                t->next = newNode;
                return;
            }
            t = t->next;
        }
        append(newKey);
    }

    void print() const {
        Node* t = head;
        cout << "List: ";
        while (t) {
            cout << t->key << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }

    ~linklist() {
        while (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
    }
};

int main() {
    linklist list;
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