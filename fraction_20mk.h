/*
    Maahum Khan (20232476) CMPE 320 Assignment 2
    .h Header File
*/

#pragma once

#include <iostream>

using namespace std;

/* Create the class for a fraction exception where the denominator is zero */
class FractionException {
public:
    string what();
private:
    string message;
};

/* Create a class for the fractions and necessary methods */
class Fraction {
public:
    Fraction();                                    //No parameter constructor for numerator 0, denominator 1
    Fraction(int);                                 //Single parameter constructor with specified numerator, denominator 1
    Fraction(int n, int d);                        //Two parameter constructor with specified 
    int numerator() const;                         //Accessor class that returns the numerator
    int denominator() const;                       //Accessor class that returns the operator
    Fraction &operator+=(const Fraction &f2);      //Overload of += operator
    Fraction &operator++();                        //Pre-crement operator
    Fraction operator++(int rand);                 //Post-crement operator
    int compare(const Fraction& fraction) const;   //Compare two fractions

private: 
    int numer;                      //Numerator variable
    int denom;                      //Denominator variable
    void normalize();               //Function that converts fraction to its simplest form, i.e. 2/4 to 1/2
    int gcd(int a, int b) const;    //Function that returns the greatest common denominator between two specified integers
};

//Non-member overload of arithmetic operators
Fraction operator+(const Fraction &f1, const Fraction &f2);
Fraction operator-(const Fraction &f1, const Fraction &f2);
Fraction operator-(const Fraction &number);
Fraction operator*(const Fraction &f1, const Fraction &f2);
Fraction operator/(const Fraction &f1, const Fraction &f2);

//Non-member overload of boolean operators
bool operator<(const Fraction &f1, const Fraction &f2);
bool operator>(const Fraction &f1, const Fraction &f2);
bool operator<=(const Fraction &f1, const Fraction &f2);
bool operator>=(const Fraction &f1, const Fraction &f2);
bool operator==(const Fraction &f1, const Fraction &f2);
bool operator!=(const Fraction &f1, const Fraction &f2);

//Non-member overload of stream operators
ostream &operator<<(ostream &output, const Fraction &fraction);
istream &operator>>(istream &input, Fraction &fraction);