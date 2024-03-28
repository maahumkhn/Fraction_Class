/*
    Maahum Khan (20232476) CMPE 320 Assignment 2
    .cpp Implementation File
*/

#include <iostream>
#include <stdio.h>

# include "fraction_20mk.h"

using namespace std;

//Implementation of Fraction Exception class what() function
string FractionException::what() 
{
    return "EXCEPTION: Denominator 0 is illegal";
}

//Implementation of no parameter Fraction constructor. Sets numerator to 0, denominator to 1
Fraction::Fraction()
{
    numer = 0;
    denom = 1;
}

//Implementation of one parameter Fraction constructor. Sets specified numerator, then denominator to 1
Fraction::Fraction(int n)
{
    numer = n;
    denom = 1;
}

//Implementation of two parameter Fraction constructor. Sets specified numerator and denominator
Fraction::Fraction(int n, int d)
{
    if (d == 0) throw FractionException();
    numer = n;
    denom = d;
    normalize();
}

/* Implementation of normalizing function in Fraction class that puts 
    fractions in their simplest form, i.e. 2/4 becomes 1/2. */
void Fraction::normalize()
{
    bool negative = false; //Create boolean variable for whether fraction is negative or not
    //Move negative sign (if existent) to numerator
    if (denom < 0) {
        negative = true;
        denom = -denom;
    }
    if (numer < 0) {
        negative = true;
        numer = -numer;
    }
    
    //Reduce fraction to simplest form
    int greatestcommon = gcd(numer, denom);
    if (negative == true) {
        numer = -numer/greatestcommon;
    } else {
        numer = numer/greatestcommon;
    }
    denom = denom/greatestcommon;
}

/* Implementation of greatest common denominator function in Fraction class
    that returns the greatest common denominator between a and b. */
int Fraction::gcd(int a, int b) const
{
    /* To determine the gcd, we determine the larger value between a and b (int x)
        since their greatest possible denominator is their maximum. The largest
        value that a and b are both divisible by will have modulo 0 with both
        a and b, and will be the greatest common denominator. */
    int x;
    int greatestcommon;
    if (abs(a) > abs(b)) {
        x = abs(a);
    } else {
        x = abs(b);
    }

    for (int i = x; i > 0; i--) {
        if ((b % i == 0) && (a % i == 0)) {
            greatestcommon = i;
            break;
        }
    }
    return greatestcommon;
}

//Implementation of compare function 
int Fraction::compare(const Fraction &fraction) const {
    //Return numerator of subtracted fractions
    return (numer*fraction.denominator() - denom*fraction.numerator());
}

//Implementation of numerator accessor
int Fraction::numerator() const
{
    return numer;
}

//Implementation of denominator accessor
int Fraction::denominator() const
{
    return denom;
}

//Implementation of += operator method
Fraction& Fraction::operator+=(const Fraction &f2)
{
    numer = numer*f2.denominator() + f2.numerator()*denom;
    denom = denom*f2.denominator();
    normalize();
    return *this;
}

/*  Implementation of ++ post-crement operator method. 
    Use rand param to distinguish from pre-crement form */
Fraction Fraction::operator++(int rand)
{
    Fraction temp(numer, denom);
    numer = numer + denom;
    return temp;
}

//Implementation of ++ pre-crement operator method
Fraction& Fraction::operator++()
{
    numer += denom;
    return *this;
}

//Implement non-member overload of arithmetic operators
Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    Fraction add((f1.numerator()*f2.denominator() + f2.numerator()*f1.denominator()), (f1.denominator()*f2.denominator()));
    return add;
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    Fraction subtract((f1.numerator()*f2.denominator() - f1.denominator()*f2.numerator()), (f1.denominator()*f2.denominator()));
    return subtract;
}

Fraction operator-(const Fraction &f)
{
    Fraction negate(-f.numerator(), f.denominator());
    return negate;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    Fraction multiply((f1.numerator()*f2.numerator()),(f1.denominator()*f2.denominator()));
    return multiply;
}

Fraction operator/(const Fraction &f1, const Fraction &f2)
{
    Fraction divide((f1.numerator()*f2.denominator()),(f1.denominator()*f2.numerator()));
    return divide;
}

//Implement non-member overload of boolean operators
bool operator<(const Fraction &f1, const Fraction &f2)
{
    return (f1.compare(f2) < 0);
}

bool operator>(const Fraction &f1, const Fraction &f2)
{
    return (f1.compare(f2) > 0);
}

bool operator<=(const Fraction &f1, const Fraction &f2)
{
    return (f1.compare(f2) <= 0);
}

bool operator>=(const Fraction &f1, const Fraction &f2)
{
    return (f1.compare(f2) >= 0);
}

bool operator==(const Fraction &f1, const Fraction &f2)
{
    return (f1.compare(f2) == 0);
}

bool operator!=(const Fraction &f1, const Fraction &f2)
{
    return (f1.compare(f2) != 0);
}

//Implement non-member overload of stream operators
ostream &operator<<(ostream &o, const Fraction &fraction)
{
    o << fraction.numerator() << "/" << fraction.denominator();
    return o;
}

istream &operator>>(istream &i, Fraction &fraction)
{
    int num, denominator; //Will hold inputted numerator and denominator
    i >> num;       

    /* If character after numerator is enter key, create whole number fraction.
        If character after numerator is slash, check for denominator, and create fraction. */
    if (i.peek() != 10) {
        char character; //Will hold next char
        i >> character;
        if (character == '/') {
            i >> denominator;
        } else {
            denominator = 1;
        }
        fraction = Fraction(num, denominator);
    } else { 
        fraction = Fraction(num);
    }
    return i;
}