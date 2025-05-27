#include "Pair.h"

Pair::Pair() : first(0), second(0.0) {}

Pair::Pair(int f, double s) : first(f), second(s) {}

Pair::Pair(const Pair& other) : first(other.first), second(other.second) {}

int Pair::getfirst() const { return first; }
void Pair::setfirst(int f) { first = f; }
double Pair::getsecond() const { return second; }
void Pair::setsecond(double s) { second = s; }

Pair& Pair::operator=(const Pair& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Pair Pair::operator-(const Pair& other) const {
    return Pair(first - other.first, second - other.second);
}

Pair Pair::operator+(int value) const {
    return Pair(first + value, second);
}

Pair Pair::operator+(double value) const {
    return Pair(first, second + value);
}

std::ostream& operator<<(std::ostream& os, const Pair& p) {
    os << p.first << ":" << p.second;
    return os;
}

std::istream& operator>>(std::istream& is, Pair& p) {
    is >> p.first >> p.second;
    return is;
}