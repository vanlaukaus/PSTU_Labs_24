#include <iostream>
#include <string>
using namespace std;

struct qnode {
    string key;
    qnode* next;
    qnode(const string& k) : key(k), next(nullptr) {}
};

class queue {
    qnode* front, * rear;
public:
    queue() : front(nullptr), rear(nullptr) {}

    void enqueue(const string& key) {
        qnode* newNode = new qnode(key);
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    string dequeue() {
        if (!front) return "";
        qnode* temp = front;
        string key = temp->key;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        return key;
    }

    bool ifempty() const {
        return front == nullptr;
    }

    void print() const {
        qnode* temp = front;
        cout << "Queue (front to rear): ";
        while (temp) {
            cout << temp->key << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~queue() {
        while (front) {
            qnode* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    queue queue;
    queue.enqueue("A");
    queue.enqueue("B");
    queue.enqueue("C");
    queue.enqueue("D");
    queue.print();

    cout << "Dequeuing 2 elements\n";
    queue.dequeue();
    queue.dequeue();
    queue.print();

    return 0;
}