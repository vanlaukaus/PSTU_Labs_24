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

    int getFirst() const;
    void setFirst(int f);
    double getSecond() const;
    void setSecond(double s);

    Pair& operator=(const Pair& other);
    Pair operator-(const Pair& other) const;
    Pair operator+(int value) const;
    Pair operator+(double value) const;
    bool operator==(const Pair& other) const;
    bool operator<(const Pair& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Pair& p);
    friend std::istream& operator>>(std::istream& is, Pair& p);
};

#endif // PAIR_H
