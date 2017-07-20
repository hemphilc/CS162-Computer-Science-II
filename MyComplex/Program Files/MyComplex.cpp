#include <iostream>
#include <cassert>
#include <cmath>

#include "MyComplex.h"

using namespace std;

//Member Functions and Friends//

MyComplex::MyComplex() {
    real = 0;
    imaginary = 0;
}

MyComplex::MyComplex(const double realValue) {
    real = realValue;
    imaginary = 0;
}

MyComplex::MyComplex(const double realValue, const double imaginaryValue) {
    real = realValue;
    imaginary = imaginaryValue;
}

MyComplex::MyComplex(const MyComplex& other) {
    real = other.real;
    imaginary = other.imaginary;
}

MyComplex& MyComplex::operator=(const MyComplex& number) {
    if(this != &number) {
        real = number.getRealPart();
        imaginary = number.getComplexPart();
    }
    return *this;
}

double MyComplex::getRealPart() const {
    return real;
}

double MyComplex::getComplexPart() const {
    return imaginary;
}

double& MyComplex::operator[](int index) {
    assert(index == 1 || index == 0);
    if (index == 0) {
        return real;
    }
    else {
        return imaginary;
    }
}

MyComplex& MyComplex::operator+=(const MyComplex& secondComplex) {
    this->real += secondComplex.getRealPart();
    this->imaginary += secondComplex.getComplexPart();
    return *this;
}

MyComplex& MyComplex::operator-=(const MyComplex& secondComplex) {
    this->real -= secondComplex.getRealPart();
    this->imaginary -= secondComplex.getComplexPart();
    return *this;
}

MyComplex& MyComplex::operator*=(const MyComplex& secondComplex) {
    double a = (secondComplex.getRealPart() * real) + ((secondComplex.getComplexPart() * imaginary) * -1);
    double b = (secondComplex.getRealPart() * imaginary) + (secondComplex.getComplexPart() * real);
    this->real = a;
    this->imaginary = b;
    return *this;
}

MyComplex& MyComplex::operator/=(const MyComplex& secondComplex) {
    double a = (real * secondComplex.getRealPart()) + ((imaginary * -secondComplex.getComplexPart()) * -1);
    double b = (imaginary * secondComplex.getRealPart()) + (real * -secondComplex.getComplexPart());
    double d = (secondComplex.getRealPart() * secondComplex.getRealPart()) +
            ((secondComplex.getComplexPart() * -secondComplex.getComplexPart()) * -1);
    this->real = (a / d);
    this->imaginary = (b / d);
    return *this;
}

MyComplex& MyComplex::operator++() {
    this->real += 1;
    return *this;
}

MyComplex& MyComplex::operator--() {
    this->real -= 1;
    return *this;
}

MyComplex MyComplex::operator++(int dummy) {
    MyComplex temp(real, imaginary);
    real += 1;
    return temp;
}

MyComplex MyComplex::operator--(int dummy) {
    MyComplex temp(real, imaginary);
    real -= 1;
    return temp;
}

MyComplex MyComplex::operator+() const {
    return *this;
}

MyComplex MyComplex::operator-() const {
    return MyComplex(-real, -imaginary);
}

ostream& operator<<(ostream& out, const MyComplex& number) {
    if (number.getComplexPart() < 0) {
        return out << number.getRealPart() << " - " << -(number.getComplexPart()) << "i";
    }
    else
        return out << number.getRealPart() << " + " << number.getComplexPart() << "i";
}

istream& operator>>(istream& get, MyComplex& number) {
    get >> number.real;
    char op;
    get >> op;
    if (op == '-') {
        get >> number.imaginary;
        number.imaginary *= -1;
    }
    else {
        get >> number.imaginary;
    }
    char i = 'i';
    get >> i;
    if (((op != '+') && (op != '-')) || (!get)) {
        cout << "Input Failure" << endl;
        exit(0);
    }
    return get;
}

MyComplex MyComplex::addToReal(double n) {
    this->real += n;
    return *this;
}

//Non-Member Functions//

MyComplex operator+(const MyComplex& firstComplex, const MyComplex& secondComplex) {
    double r = firstComplex.getRealPart() + secondComplex.getRealPart();
    double i = firstComplex.getComplexPart() + secondComplex.getComplexPart();
    return MyComplex(r, i);
}

MyComplex operator-(const MyComplex& firstComplex, const MyComplex& secondComplex) {
    double r = firstComplex.getRealPart() - secondComplex.getRealPart();
    double i = firstComplex.getComplexPart() - secondComplex.getComplexPart();
    return MyComplex(r, i);
}

MyComplex operator*(const MyComplex& firstComplex, const MyComplex& secondComplex){
    double a = (firstComplex.getRealPart() * secondComplex.getRealPart()) +
            ((firstComplex.getComplexPart() * secondComplex.getComplexPart()) * -1);
    double b = (firstComplex.getComplexPart() * secondComplex.getRealPart()) +
            (firstComplex.getRealPart() * secondComplex.getComplexPart());
    return MyComplex(a, b);
}

MyComplex operator/(const MyComplex& firstComplex, const MyComplex& secondComplex) {
    double a = (firstComplex.getRealPart() * secondComplex.getRealPart()) +
            ((firstComplex.getComplexPart() * -secondComplex.getComplexPart()) * -1);
    double b = (firstComplex.getComplexPart() * secondComplex.getRealPart()) +
            (firstComplex.getRealPart() * -secondComplex.getComplexPart());
    double d = (secondComplex.getRealPart() * secondComplex.getRealPart()) +
            ((secondComplex.getComplexPart() * -secondComplex.getComplexPart()) * -1);
    return MyComplex((a / d), (b / d));
}

bool operator==(const MyComplex& firstComplex, const MyComplex& secondComplex) {
    const double EPSILON = 0.00001;
    if ((abs(firstComplex.getRealPart() - secondComplex.getRealPart()) < EPSILON) &&
            (abs(firstComplex.getComplexPart() - secondComplex.getComplexPart()) < EPSILON))
        return (firstComplex == secondComplex);
    else
        return false;
}

bool operator!=(const MyComplex& firstComplex, const MyComplex& secondComplex) {
    const double EPSILON = 0.00001;
    if ((abs(firstComplex.getRealPart() - secondComplex.getRealPart()) > EPSILON) ||
            (abs(firstComplex.getComplexPart() - secondComplex.getComplexPart()) > EPSILON))
        return (firstComplex != secondComplex);
    else
        return false;
}

