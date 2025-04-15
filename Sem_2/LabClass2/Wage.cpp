#include "Wage.h"
#include <iostream>

Wage::Wage() : fullName("Unknown"), salary(0.0), bonusPercent(0) {}

Wage::Wage(const std::string& name, double sal, int bonus) 
    : fullName(name), salary(sal), bonusPercent(bonus) {}

Wage::Wage(const Wage& other) {
    fullName = other.fullName;
    salary = other.salary;
    bonusPercent = other.bonusPercent;
}

Wage::~Wage() {
    std::cout << "Destructor called for " << fullName << std::endl;
}

std::string Wage::getFullName() const {
    return fullName;
}

double Wage::getSalary() const {
    return salary;
}

int Wage::getBonusPercent() const {
    return bonusPercent;
}

void Wage::setFullName(const std::string& name) {
    fullName = name;
}

void Wage::setSalary(double sal) {
    salary = sal;
}

void Wage::setBonusPercent(int bonus) {
    bonusPercent = bonus;
}

double Wage::calculateTotal() const {
    return salary + (salary * bonusPercent / 100.0);
}