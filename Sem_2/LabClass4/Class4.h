#ifndef CLASS4_H
#define CLASS4_H

#include <iostream>
#include <string>

class person {
protected:
    std::string name;
    int age;
public:
    person();
    person(std::string n, int a);
    person(const person& other);
    ~person();

    std::string getName() const;
    int getAge() const;

    void setName(std::string n);
    void setAge(int a);

    person& operator=(const person& other);
    friend std::ostream& operator<<(std::ostream& os, const person& p);
    friend std::istream& operator>>(std::istream& is, person& p);
};

class student : public person {
private:
    std::string subject;
    int grade;
public:
    student();
    student(std::string n, int a, std::string s, int g);
    student(const student& other);
    ~student();

    std::string getSubject() const;
    int getGrade() const;
    void setSubject(std::string s);
    void setGrade(int g);

    void checkGrade() const;

    student& operator=(const student& other);
    friend std::ostream& operator<<(std::ostream& os, const student& s);
    friend std::istream& operator>>(std::istream& is, student& s);
};

void printperson(const person& p);

#endif 