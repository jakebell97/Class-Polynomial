#include "Jacob_Bell_Polynomial.h"
#include <iostream>
#include <vector>

Polynomial::Polynomial()
{
    terms = nullptr;
}

Polynomial::Polynomial(int deg, int arr[])
{
    degree = deg;

    terms = new int[deg + 1];

    for(int i = 0; i <= deg; i++)
    {
        terms[i] = arr[i];
    }

}

Polynomial::~Polynomial()
{
    delete [] terms;
    terms = nullptr;
}

void Polynomial::enterTerms()
{
    int n, c, e;

    std::cout << "Enter number of polynomial terms: ";
    std::cin >> n;
    std::cout << std::endl;

    std::cout << "Enter coefficient: ";
    std::cin >> c;
    std::cout << "Enter exponent: ";
    std::cin >> e;
    std::cout << std::endl;

    degree = e;
    delete [] terms;
    terms = new int[degree + 1];

    for(int i = 0; i < e; i++)
    {
        terms[i] = 0;
    }

    terms[e] = c;

    for(int i = 1; i < n; i++)
    {
        std::cout << "Enter coefficient: ";
        std::cin >> c;
        std::cout << "Enter exponent: ";
        std::cin >> e;
        std::cout << std::endl;

        terms[e] = c;
    }
}

void Polynomial::printPolynomial() const
{
    bool x0printed, empti = true;

    for(int i = 0; i < degree + 1; i++)
    {
        if(terms[i] != 0)
            empti = false;
    }

    if(empti)
        std::cout << "0";
    else
    {
        if(terms[0] != 0)
        {
            std::cout << terms[0];
            x0printed = true;
        }
        else
            x0printed = false;

        if(x0printed)
        {
            for(int i = degree; i > 1; i--)
            {
                if(terms[i] > 0)
                    std::cout << "+" << terms[i] << "x^" << i;
                else if(terms[i] < 0)
                    std::cout << terms[i] << "x^" << i;
            }

            if(terms[1] > 0)
                std::cout << "+" << terms[1] << "x";
            else if(terms[1] < 0)
                std::cout << terms[1] << "x";
        }

        else
        {
            if(degree != 1)
                std::cout << terms[degree] << "x^" << degree;

            else
                std::cout << terms[degree] << "x";

            for (int i = degree - 1; i > 1; i--)
            {
                if(terms[i] > 0)
                    std::cout << "+" << terms[i] << "x^" << i;
                else if(terms[i] < 0)
                    std::cout << terms[i] << "x^" << i;
            }

            if(terms[1] > 0)
                std::cout << "+" << terms[1] << "x";
            else if(terms[1] < 0)
                std::cout << terms[1] << "x";
        }
    }

    std::cout << std::endl;
}

void Polynomial::operator=(const Polynomial& p)
{
    degree = p.degree;

    delete [] this->terms;

    terms = new int[p.degree + 1];

    for(int i = 0; i < degree + 1; i++)
    {
        this->terms[i] = p.terms[i];
    }
}

Polynomial Polynomial::operator+(const Polynomial& p)
{
    int newSize, termsPlus0;
    bool thisBigger;

    if(p.degree > this->degree)
    {
        newSize = p.degree + 1;
        termsPlus0 = p.degree - this->degree;
        thisBigger = false;
    }
    else
    {
        newSize = this->degree + 1;
        termsPlus0 = this->degree - p.degree;
        thisBigger = true;
    }

    int arr[newSize];

    for(int i = 0; i < newSize - termsPlus0; i++)
    {
        arr[i] = this->terms[i] + p.terms[i];
    }

    for(int i = newSize - termsPlus0; i < newSize; i++)
    {
        if(thisBigger)
            arr[i] = this->terms[i];

        else
            arr[i] = p.terms[i];
    }

    Polynomial temp(newSize - 1, arr);

    return temp;
}

Polynomial Polynomial::operator-(const Polynomial& p)
{
    int newSize, termsPlus0;
    bool thisBigger;

    if(p.degree > this->degree)
    {
        newSize = p.degree + 1;
        termsPlus0 = p.degree - this->degree;
        thisBigger = false;
    }
    else
    {
        newSize = this->degree + 1;
        termsPlus0 = this->degree - p.degree;
        thisBigger = true;
    }

    int arr[newSize];

    for(int i = 0; i < newSize - termsPlus0; i++)
    {
        arr[i] = this->terms[i] - p.terms[i];
    }

    for(int i = newSize - termsPlus0; i < newSize; i++)
    {
        if(thisBigger)
            arr[i] = this->terms[i];

        else
            arr[i] = p.terms[i];
    }

    Polynomial temp(newSize - 1, arr);

    return temp;
}

void Polynomial::operator+=(const Polynomial& p)
{
    *this = *this + p;
}

void Polynomial::operator-=(const Polynomial& p)
{
    *this = *this - p;
}
