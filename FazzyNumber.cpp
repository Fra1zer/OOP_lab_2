#include "FazzyNumber.h"

FazzyNumber::FazzyNumber(){
    x = new double(1);
    e1 = new double(0);
    e2 = new double(2);
}

FazzyNumber::FazzyNumber(double _x, double _e1, double _e2){
    x = new double(_x);
    e1 = new double(_e1);
    e2 = new double(_e2);
}

FazzyNumber::FazzyNumber(const FazzyNumber& other){
    x = new double(*other.x);
    e1 = new double(*other.e1);
    e2 = new double(*other.e2);
}

void FazzyNumber::set_x(double _x){
    *x = _x;
}

void FazzyNumber::set_e1(double _e1){
    *e1 = _e1;
}

void FazzyNumber::set_e2(double _e2){
    *e2 = _e2;
}

double FazzyNumber::get_x(){
    return *x;
}

double FazzyNumber::get_e1(){
    return *e1;
}

double FazzyNumber::get_e2(){
    return *e2;
}

FazzyNumber::~FazzyNumber(){
    delete x;
    delete e1;
    delete e2;
}

FazzyNumber& FazzyNumber::operator=(const FazzyNumber& other){
    if (this != &other){
        *x = *other.x;
        *e1 = *other.e1;
        *e2 = *other.e2;
    }
    return *this;
}

FazzyNumber FazzyNumber::operator+(const FazzyNumber& other){
    FazzyNumber res = FazzyNumber(*x + *other.x, *e1 + *other.e1, *e2 + *other.e2);
    return res;
}

FazzyNumber FazzyNumber::operator-(const FazzyNumber& other){
    FazzyNumber res = FazzyNumber(*x - *other.x, *e1 - *other.e1, *e2 - *other.e2);
    return res;
}

FazzyNumber FazzyNumber::operator*(const FazzyNumber& other){
    FazzyNumber res = FazzyNumber(*x * *other.x, *e1 * *other.e1, *e2 * *other.e2);
    return res;
}

FazzyNumber FazzyNumber::operator/(const FazzyNumber& other){
    if (*other.x > EPS && *other.e1 > EPS && *other.e2 > EPS){
        FazzyNumber res = FazzyNumber(*x / *other.x, *e1 / *other.e1, *e2 / *other.e2);
        return res;
    }
    return FazzyNumber(*x, *e1, *e2);
}

FazzyNumber& FazzyNumber::operator+=(FazzyNumber other){
    *x += *other.x;
    *e1 += *other.e1;
    *e2 += *other.e2;
    return *this;
}

FazzyNumber& FazzyNumber::operator-=(FazzyNumber other){
    *x -= *other.x;
    *e1 -= *other.e1;
    *e2 -= *other.e2;
    return *this;
}

FazzyNumber& FazzyNumber::operator*=(FazzyNumber other){
    *x *= *other.x;
    *e1 *= *other.e1;
    *e2 *= *other.e2;
    return *this;
}

FazzyNumber& FazzyNumber::operator/=(FazzyNumber other){
    if (*other.x > EPS && *other.e1 > EPS && *other.e2 > EPS){
        *x /= *other.x;
        *e1 /= *other.e1;
        *e2 /= *other.e2;
        return *this;
    }
    return *this;
}

bool FazzyNumber::operator==(FazzyNumber other) const{
    return abs(*x - *other.x) < EPS && abs(*e1 - *other.e1) < EPS && abs(*e2 - *other.e2) < EPS;
}

bool FazzyNumber::operator!=(FazzyNumber other) const{
    return abs(*x - *other.x) > EPS && abs(*e1 - *other.e1) > EPS && abs(*e2 - *other.e2) > EPS;
}

ostream& operator<<(ostream& os, const FazzyNumber& num){
    os << '(' << *num.e1 << ',' << *num.x << ',' << *num.e2 << ')';
    return os;
}

istream& operator>>(istream& is, FazzyNumber& num){
    double x, e1, e2;
    char left, right, cm;
    is >> left >> e1 >> cm >> x >> cm >> e2 >> right;
    if (is){
        *num.x = x;
        *num.e1 = e1;
        *num.e2 = e2;
    }
    return is;
}
