#include <iostream>
#include <algorithm>
using namespace std;

class Rational {
private:
    int num, den;

public:

    Rational(int n = 0, int d = 1) {
        if (d == 0) {
            cout << "Denominator cannot be zero. Setting to 1.\n";
            d = 1;
        }
        num = n;
        den = d;
    }

    Rational add(const Rational& r) const {
        Rational result(num * r.den + r.num * den, den * r.den);
        return result;
    }

    Rational subtract(const Rational& r) const {
        Rational result(num * r.den - r.num * den, den * r.den);
        return result;
    }

    Rational multiply(const Rational& r) const {
        Rational result(num * r.num, den * r.den);
        return result;
    }


    Rational& operator++() {
        num += den;
        return *this;
    }

    Rational operator++(int) {
        Rational temp(*this);
        ++(*this);
        return temp;
    }



    void display() const {
        cout << num << "/" << den << endl;
    }
};

int main() {
    Rational r1(4, 5);
    Rational r2(8, 7);

    cout << "r1: ";
    r1.display();
    cout << "r2: ";
    r2.display();

    
    Rational sum = r1.add(r2);
    cout << "ADD (r1 + r2) = ";
    sum.display();

    
    Rational diff = r1.subtract(r2);
    cout << "SUB (r1 - r2) = ";
    diff.display();


    Rational prod = r1.multiply(r2);
    cout << "r1 * r2 = ";
    prod.display();

    
    cout << "Prefix ++r1: ";
    ++(++r1);
    r1.display();

    cout << "Postfix r1++: ";
    (r1++)++;
    r1.display();

    return 0;


}

