// pair.h
#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {
private:
    int first;
    double second;

public:
    // Constructors
    Pair();
    Pair(int f, double s);
    Pair(const Pair& other);

    // Getters and setters
    int getFirst() const;
    void setFirst(int f);
    double getSecond() const;
    void setSecond(double s);

    // Operators
    Pair& operator=(const Pair& other);
    Pair operator-(const Pair& other) const;
    Pair operator+(int value) const;
    Pair operator+(double value) const;
    bool operator==(const Pair& other) const;
    bool operator<(const Pair& other) const;

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Pair& p);
    friend std::istream& operator>>(std::istream& is, Pair& p);
};

#endif // PAIR_H
