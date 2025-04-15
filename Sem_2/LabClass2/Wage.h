#define wage_h

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

    std::string getfullname() const;
    double getsalary() const;
    int getbonus() const;

    void setfullname(const std::string& name);
    void setsalary(double sal);
    void setbonus(int bonus);

    double total() const;
};

#endif
