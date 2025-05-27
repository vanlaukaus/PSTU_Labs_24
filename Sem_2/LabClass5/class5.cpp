#include <iostream>
#include <vector>
#include <string>

using namespace std;

class person {
protected:
    string name;
    int age;
public:
    person(const string& n, int a) : name(n), age(a) {}
    virtual ~person() = default;
    virtual void print(ostream& os) const = 0;
    void setName(const string& n) { name = n; }
    void setAge(int a) { age = a; }
};

ostream& operator<<(ostream& os, const person& p) {
    p.print(os);
    return os;
}

class Student : public person {
    string subject;
    int grade;
public:
    Student(const string& n, int a, const string& s, int g)
        : person(n, a), subject(s), grade(g) {
    }
    void setSubject(const string& s) { subject = s; }
    void setGrade(int g) { grade = g; }
    void checkGrade() const {
        if (grade < 3) {
            cout << "Unsatisfactory grade in " << subject << endl;
        }
    }
    void print(ostream& os) const override {
        os << "Student: " << name << ", Age: " << age
            << ", Subject: " << subject << ", Grade: " << grade;
    }
};

class Vector {
    vector<person*> elements;
public:
    void add(person* p) {
        elements.push_back(p);
    }

    person* getElement(size_t index) const {
        return (index < elements.size()) ? elements[index] : nullptr;
    }

    friend ostream& operator<<(ostream& os, const Vector& v) {
        for (const auto& elem : v.elements) {
            os << *elem << endl;
        }
        return os;
    }

    ~Vector() {
        for (auto elem : elements) {
            delete elem;
        }
    }
};

int main() {
    Vector vec;
    vec.add(new Student("Anna", 20, "Maths", 5));
    vec.add(new Student("Ivan", 22, "Physics", 2));

    cout << "Vector contents:" << endl;
    cout << vec;

    Student* student = dynamic_cast<Student*>(vec.getElement(1));
    if (student) {
        student->setGrade(3);
        student->setSubject("Chemistry");
        student->checkGrade();
    }

    cout << "\nAfter changes:" << endl;
    Student* student2 = dynamic_cast<Student*>(vec.getElement(0));
    if (student2) {
        student2->setGrade(2);
        student2->checkGrade();
    }

    cout << vec;

    return 0;
}