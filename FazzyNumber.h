#pragma once
#include <iostream>

using namespace std;

class FazzyNumber{
    double *x, *e1, *e2;
    double const EPS = 1e-8;

    public:
    FazzyNumber();
    FazzyNumber(double _x, double _e1, double _e2);
    FazzyNumber(const FazzyNumber& other);

    void set_x(double _x);
    void set_e1(double _e1);
    void set_e2(double _e2);

    double get_x();
    double get_e1();
    double get_e2();

    ~FazzyNumber();

    FazzyNumber& operator=(const FazzyNumber& other);

    FazzyNumber operator+(const FazzyNumber& other);
    FazzyNumber operator-(const FazzyNumber& other);
    FazzyNumber operator*(const FazzyNumber& other);
    FazzyNumber operator/(const FazzyNumber& other);

    FazzyNumber& operator+=(FazzyNumber other);
    FazzyNumber& operator-=(FazzyNumber other);
    FazzyNumber& operator*=(FazzyNumber other);
    FazzyNumber& operator/=(FazzyNumber other);

    bool operator==(FazzyNumber other) const;
    bool operator!=(FazzyNumber other) const;

    friend ostream& operator<<(ostream& os, const FazzyNumber& num);
    friend istream& operator>>(istream& is, FazzyNumber& num);
};
