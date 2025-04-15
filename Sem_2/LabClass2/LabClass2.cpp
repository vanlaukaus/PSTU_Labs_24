#include <iostream>
#include "Wage.h"

void dispwage(Wage w) {
    std::cout << "\nInside displayWage function (copy constructor was called)" << std::endl;
    std::cout << "Employee: " << w.getFullName() << std::endl;
    std::cout << "Salary: " << w.getSalary() << std::endl;
    std::cout << "Bonus %: " << w.getBonusPercent() << std::endl;
    std::cout << "Total wage: " << w.calculateTotal() << std::endl;
}

int main() {
    Wage employee1;
    std::cout << "Default constructor example:" << std::endl;
    std::cout << "Employee: " << employee1.getFullName() << std::endl;
    std::cout << "Salary: " << employee1.getSalary() << std::endl;
    std::cout << "Bonus %: " << employee1.getBonusPercent() << std::endl << std::endl;

    Wage employee2("John Smith", 5000.0, 15);
    std::cout << "Parameterized constructor example:" << std::endl;
    std::cout << "Employee: " << employee2.getFullName() << std::endl;
    std::cout << "Salary: " << employee2.getSalary() << std::endl;
    std::cout << "Bonus %: " << employee2.getBonusPercent() << std::endl;
    std::cout << "Total wage: " << employee2.calculateTotal() << std::endl << std::endl;

    Wage employee3 = employee2;
    std::cout << "Copy constructor example (case 1 - explicit copy):" << std::endl;
    std::cout << "Employee: " << employee3.getFullName() << std::endl << std::endl;

    std::cout << "Before calling displayWage function" << std::endl;
    dispWage(employee2);

    Wage employee4(employee2);
    std::cout << "\nCopy constructor example (case 3 - direct initialization):" << std::endl;
    std::cout << "Employee: " << employee4.getFullName() << std::endl << std::endl;

    employee1.setFullName("Alice Johnson");
    employee1.setSalary(4500.0);
    employee1.setBonusPercent(10);
    std::cout << "After using setters for employee1:" << std::endl;
    std::cout << "Employee: " << employee1.getFullName() << std::endl;
    std::cout << "Salary: " << employee1.getSalary() << std::endl;
    std::cout << "Bonus %: " << employee1.getBonusPercent() << std::endl;
    std::cout << "Total wage: " << employee1.calculateTotal() << std::endl;

    return 0;
}
