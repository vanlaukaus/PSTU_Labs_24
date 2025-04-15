#ifndef WAGE_H
#define WAGE_H

#include <string>

class Wage {
private:
    std::string fullName;
    double salary;
    int bonusPercent;

public:
    Wage();
    Wage(const std::string& name, double sal, int bonus);
    Wage(const Wage& other);

    ~Wage();

    std::string getFullName() const;
    double getSalary() const;
    int getBonusPercent() const;

    void setFullName(const std::string& name);
    void setSalary(double sal);
    void setBonusPercent(int bonus);

    double calculateTotal() const;
};

#endif