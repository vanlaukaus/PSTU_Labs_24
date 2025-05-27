#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {
private:
    int first;
    double second;

public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}
    Pair(int f) : first(f), second(0.0) {} // For sentinel detection

    // Copy constructor and assignment operator
    Pair(const Pair& other) = default;
    Pair& operator=(const Pair& other) = default;

    // Arithmetic operators
    Pair operator*(const Pair& other) const {
        return Pair(first * other.first, second * other.second);
    }

    // Equality for sentinel check
    bool operator==(const Pair& other) const {
        return (first == other.first) && (second == other.second);
    }

    friend std::ostream& operator<<(std::ostream& os, const Pair& p) {
        os << p.first << ":" << p.second;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Pair& p) {
        char colon;
        is >> p.first >> colon >> p.second;
        if (colon != ':') is.setstate(std::ios::failbit);
        return is;
    }
};

#endif // PAIR_H
