#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {
private:
    int first;
    double second;

public:
    Pair();
    Pair(int f, double s);
    Pair(const Pair& other);

    ~Pair() = default;

    int getfirst() const;
    void setfirst(int f);
    double getsecond() const;
    void setsecond(double s);

    Pair& operator=(const Pair& other);

    friend std::ostream& operator<<(std::ostream& os, const Pair& p);
    friend std::istream& operator>>(std::istream& is, Pair& p);

    Pair operator-(const Pair& other) const;

    Pair operator+(int value) const;
    Pair operator+(double value) const;
};

#endif 