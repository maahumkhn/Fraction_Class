Fraction Class Assignment Description: 

For this assignment you will need to write a C++ Fraction class designed to hold fractions. For example 1 / 10 would be stored as two values, 1 and 10, not 0.1. You should store a fraction in a normalized state. For example, instead of storing 5 / 15, you would store 1 / 3. To normalize a fraction it helps to know the greatest common divisor, or GCD, of the two numbers. You can use any GCD algorithm you please, but here is a recursive one:

GCD

Constructors only take int values. One constructor takes a single int and the second takes two ints, the first for the numerator, the second for the denominator. Also, if one of the numbers in a constructor is negative then you should make just the numerator negative. If both numbers are negative, then the numerator should be positive. The default constructor creates a "zero" fraction which would look like 0/1.

You will need to write an interface called fraction_netid.h and the implementation source file, fraction_netid.cpp. (Add your own netid to the filenames...) Attached is a testing file (FractionTest.cpp) that you can use to check the operation of your Fraction class as you develop it. Your TA will check the operation of your class against this file, and may add some tests of their own, - so you can change the existing file, adding more tests for example, but you still need to satisfy the testing code, as supplied.

You can examine the testing file to get more information on how your object must behave. For example, you will see that you will need three constructors and must throw an exception called FractionException if the user attempts to create a Fraction with a zero value denominator. You do not need any mutators but will need accessors. You must overload the following unary operators:

- (negation)
++ (post-increment)
++ (pre-increment)
And the following binary operators:

+ (addition)
- (subtraction)
* (multiplication)
/ (division)
+= (addition and assignment)
The comparison operators: < <= == != >= >
<< (used with cout)
>> (used with cin)
Yes, you could overload other operators, but this is enough. The assignment operator, =, will be created for you so you do not need to overload it. Note that a Fraction object should appear as "2/3" when displayed, and the user can be expected to enter a fraction in the same format or as just a whole number. The binary operators: +, -, *, / and all the comparison operators should work in the case that there is an int value on the LHS or RHS of the operator, or if there are Fraction objects on both sides. += should work with an int or a Fraction on the RHS.
