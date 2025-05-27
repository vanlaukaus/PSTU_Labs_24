#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class PRINT {
protected:
    string title;
    string author;
public:
    virtual ~PRINT() {}
    virtual void input() = 0;
    virtual void print() const = 0;
    string getTitle() const { return title; }
};

class magazine : public PRINT {
private:
    int pageCount;
public:
    void input() override {
        cout << "Enter magazine title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter number of pages: ";
        cin >> pageCount;
        cin.ignore();
    }

    void print() const override {
        cout << "magazine: " << title << ", Author: " << author
            << ", Pages: " << pageCount << endl;
    }
};

class Tree {
protected:
    vector<PRINT*> elements;
public:
    void addElement(PRINT* elem) {
        elements.push_back(elem);
    }

    void removeElement() {
        if (!elements.empty()) {
            delete elements.back();
            elements.pop_back();
        }
    }

    void printAll() const {
        for (const auto& elem : elements) {
            elem->print();
        }
    }

    void printTitles() const {
        for (const auto& elem : elements) {
            cout << elem->getTitle() << endl;
        }
    }

    size_t getSize() const {
        return elements.size();
    }

    void clear() {
        for (auto elem : elements) {
            delete elem;
        }
        elements.clear();
    }

    virtual ~Tree() {
        clear();
    }
};

class dialogue : public Tree {
public:
    void handleCommand(const string& command) {
        if (command.empty()) return;

        try {
            switch (command[0]) {
            case 'm': {
                int count = stoi(command.substr(2));
                if (count <= 0) throw invalid_argument("");
                clear();
                for (int i = 0; i < count; ++i) {
                    magazine* mag = new magazine();
                    mag->input();
                    addElement(mag);
                }
                break;
            }
            case '+': {
                magazine* mag = new magazine();
                mag->input();
                addElement(mag);
                break;
            }
            case '-': {
                removeElement();
                break;
            }
            case 's': {
                printAll();
                break;
            }
            case 'z': {
                printTitles();
                break;
            }
            case 'q': {
                exit(0);
            }
            default:
                cout << "Unknown command" << endl;
            }
        }
        catch (...) {
            cout << "Input error" << endl;
        }
    }
};

int main() {
    dialogue dialog;
    string command;
    while (true) {
        cout << "Enter command (m, +, -, s, z, q): ";
        getline(cin, command);
        dialog.handleCommand(command);
    }
    return 0;
}