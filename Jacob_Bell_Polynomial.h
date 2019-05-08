#ifndef JACOB_BELL_POLYNOMIAL_H_INCLUDED
#define JACOB_BELL_POLYNOMIAL_H_INCLUDED

#include <vector>

class Polynomial
{
public:
    // Constructor/Destructor
    Polynomial();
    Polynomial(int, int[]);
    ~Polynomial();

    // Member Functions
    void enterTerms();
    void printPolynomial() const;

    // Operators
    void operator=(const Polynomial&);
    Polynomial operator+(const Polynomial&);
    Polynomial operator-(const Polynomial&);
    void operator+=(const Polynomial&);
    void operator-=(const Polynomial&);


private:
    int * terms; // store exponents as dynamic array index
    int degree;


};


#endif // JACOB_BELL_POLYNOMIAL_H_INCLUDED
