#include "Wage.h"
#include <iostream>

Wage::Wage() : fullName("Unknown"), salary(0.0), bonusPercent(0) {}

Wage::Wage(const std::string& name, double sal, int bonus) 
    : fullName(name), salary(sal), bonusPercent(bonus) {}

Wage::Wage(const Wage& other) {
    fullname = other.fullname;
    salary = other.salary;
    bonuspercent = other.bonuspercent;
}

Wage::~Wage() {
    std::cout << "Destructor called for " << fullName << std::endl;
}

std::string Wage::getfullname() const {
    return fullname;
}

double Wage::getsalary() const {
    return salary;
}

int Wage::getbonus() const {
    return bonuspercent;
}

void Wage::setfullname(const std::string& name) {
    fullname = name;
}

void Wage::setSalary(double sal) {
    salary = sal;
}

void Wage::setbonus(int bonus) {
    bonuspercent = bonus;
}

double Wage::total() const {
    return salary + (salary * bonuspercent / 100.0);
}
