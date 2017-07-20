#ifndef MYCOMPLEX
#define MYCOMPLEX

#include <iostream>

class MyComplex {
public:
//Member-Functions and Friends//

    /**
     * @brief MyComplex MyComplex object Default Constructor
     */
    MyComplex();

    /**
     * @brief MyComplex MyComplex object Constructor with specified real value
     * @param realValue Real number value to be set
     */
    MyComplex(const double realValue);

    /**
     * @brief MyComplex MyComplex object Constructor with specified real and imaginary values
     * @param realValue Real number value to be set
     * @param imaginaryValue Imaginary number value to be set
     */
    MyComplex(const double realValue, const double imaginaryValue);

    /**
     * @brief MyComplex MyComplex object Deep Copy Constructor
     * @param other MyComplex object to be copied
     */
    MyComplex(const MyComplex& other);

    /**
     * @brief MyComplex MyComplex Object Destructor
     */
    ~MyComplex(){}

    /**
     * @brief operator = MyComplex member Assignment operator
     * @param number Specified MyComplex object to assign to
     * @returns Returns MyComplex by reference
     */
    MyComplex& operator=(const MyComplex& number);

    /**
     * @brief getRealNumber Gets real number value
     * @return Returns real
     */
    double getRealPart() const;

    /**
     * @brief getImaginaryNumber Gets imaginary number value
     * @return Returns imaginary
     */
    double getComplexPart() const;

    /**
     * @brief operator[] MyComplex index operator
     * @param index Index of 0 returns real part, Index 1 returns imaginary part
     * @return Returns value by index number 1 or 0
     */
    double& operator[](int index);

    /**
     * @brief operator+= MyComplex member addition augmented assignment operator
     * @param secondComplex Specifed MyComplex object to add to *this
     * @return Returns *this
     */
    MyComplex& operator+=(const MyComplex& secondComplex);

    /**
     * @brief operator-= MyComplex member subtraction augmented assignment operator
     * @param secondComplex Specifed MyComplex object to subtract from *this
     * @return Returns *this
     */
    MyComplex& operator-=(const MyComplex& secondComplex);

    /**
     * @brief operator*= MyComplex member multiplication augmented assignment operator
     * @param secondComplex Specifed MyComplex object to multiply with *this
     * @return Returns *this
     */
    MyComplex& operator*=(const MyComplex& secondComplex);

    /**
     * @brief operator/= MyComplex member division augmented assignment operator
     * @param secondComplex Specifed MyComplex object to divide *this by
     * @return Returns *this
     */
    MyComplex& operator/=(const MyComplex& secondComplex);

    /**
     * @brief operator++ MyComplex member Pre-Increment
     * @return Returns *this
     */
    MyComplex& operator++();

    /**
     * @brief operator-- MyComplex member Pre-Decrement
     * @return Returns *this
     */
    MyComplex& operator--();

    /**
     * @brief operator++ MyComplex member Post-Increment
     * @param dummy Dummy value - Not typically used
     * @return Returns *this
     */
    MyComplex operator++(int dummy);

    /**
     * @brief operator-- MyComplex member Post-Decrement
     * @param dummy Dummy value - Not typically used
     * @return Returns *this
     */
    MyComplex operator--(int dummy);

    /**
     * @brief operator+ MyComplex Unary Negation
     * @return Returns *this
     */
    MyComplex operator+() const;

    /**
     * @brief operator- MyComplx Unary Negation
     * @return Returns *this
     */
    MyComplex operator-() const;

    /**
     * @brief operator<< Friend ostream operator
     * @param out Stream to print out
     * @param number MyComplex object to stream in and print out
     * @return Prints MyComplex value to console
     */
    friend std::ostream& operator<<(std::ostream& out, const MyComplex& number);

    /**
     * @brief operator>> Friend istream operator
     * @param get Gets streamed string
     * @param number MyComplex object to stream in
     * @return Returns get
     */
    friend std::istream& operator>>(std::istream& get, MyComplex& number);

    /**
     * @brief addTo Adds a double value to the real part of a MyComplex object
     * @param n The double value to be added to the real part
     * @return Returns *this
     */
    MyComplex addToReal(double n);

private:
    double real;
    double imaginary;
};

//Non-Member Functions//

/**
 * @brief operator+ MyComplex non-member addition operator
 * @param secondComplex MyComplex value to add to
 * @return Returns new MyComplex
 */
MyComplex operator+(const MyComplex& firstComplex, const MyComplex& secondComplex);

/**
 * @brief operator- MyComplex non-member subtraction operator
 * @param secondComplex MyComplex value to subtract from
 * @return Returns new MyComplex
 */
MyComplex operator-(const MyComplex& firstComplex, const MyComplex& secondComplex);

/**
 * @brief operator* MyComplex non-member multiplication operator
 * @param secondComplex MyComplex value to multiply with
 * @return Returns new MyComplex
 */
MyComplex operator*(const MyComplex& firstComplex, const MyComplex& secondComplex);

/**
 * @brief operator/ MyComplex non-member division operator
 * @param secondComplex MyComplex value to divide with
 * @return Returns new MyComplex
 */
MyComplex operator/(const MyComplex& firstComplex, const MyComplex& secondComplex);

/**
 * @brief operator== MyComplex non-member "is equal" boolean
 * @param secondComplex MyComplex object to compare with
 * @return Returns true if equal, false otherwise
 */
bool operator==(const MyComplex& firstComplex, const MyComplex& secondComplex);

/**
 * @brief operator != MyComplex non-member "is not equal" boolean
 * @param secondComplex MyComplex object to compare with
 * @return Returns true if not equal, false otherwise
 */
bool operator!=(const MyComplex& firstComplex, const MyComplex& secondComplex);

#endif // MYCOMPLEX

