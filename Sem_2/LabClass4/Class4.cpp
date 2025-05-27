#include "Class4.h"
#include <iostream>
using namespace std;

person::person() : name(""), age(0) {}
person::person(std::string n, int a) : name(n), age(a) {}
person::person(const person& other) : name(other.name), age(other.age) {}
person::~person() {}

std::string person::getName() const { return name; }
int person::getAge() const { return age; }
void person::setName(std::string n) { name = n; }
void person::setAge(int a) { age = a; }

person& person::operator=(const person& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const person& p) {
    os << "Name: " << p.name << ", Age: " << p.age;
    return os;
}

std::istream& operator>>(std::istream& is, person& p) {
    std::cout << "Enter name: ";
    is >> p.name;
    std::cout << "Enter age: ";
    is >> p.age;
    return is;
}

student::student() : person(), subject(""), grade(0) {}
student::student(std::string n, int a, std::string s, int g)
    : person(n, a), subject(s), grade(g) {
}
student::student(const student& other)
    : person(other), subject(other.subject), grade(other.grade) {
}
student::~student() {}

std::string student::getSubject() const { return subject; }
int student::getGrade() const { return grade; }
void student::setSubject(std::string s) { subject = s; }
void student::setGrade(int g) { grade = g; }

void student::checkGrade() const {
    if (grade < 3) {
        std::cout << "Unsatisfactory grade!" << std::endl;
    }
}

student& student::operator=(const student& other) {
    if (this != &other) {
        person::operator=(other);
        subject = other.subject;
        grade = other.grade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const student& s) {
    os << static_cast<const person&>(s)
        << ", Subject: " << s.subject << ", Grade: " << s.grade;
    return os;
}

std::istream& operator>>(std::istream& is, student& s) {
    is >> static_cast<person&>(s);
    std::cout << "Enter subject: ";
    is >> s.subject;
    std::cout << "Enter grade: ";
    is >> s.grade;
    return is;
}

void printperson(const person& p) {
    std::cout << p << std::endl;
}

int main() {
    person p1;
    person p2("John", 20);
    person p3 = p2;

    cout << "Enter data for p1:\n";
    cin >> p1;
    cout << "p1: " << p1 << endl;

    p3 = p1;
    cout << "p3 after assignment: " << p3 << endl;

    student s1;
    student s2("Bob", 22, "Math", 4);
    student s3 = s2;

    cout << "Enter data for s1:\n";
    cin >> s1;
    cout << "s1: " << s1 << endl;
    s1.checkGrade();

    s3 = s1;
    cout << "s3 after assignment: " << s3 << endl;

    cout << "student via person function:\n";
    printperson(s2);

    return 0;
}