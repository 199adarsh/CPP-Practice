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
    Rational r1(1,2);

    cout << "Original: ";
    r1.display();

    cout << "Prefix ++ : ";
    ++r1;
    r1.display();

    cout << "Postfix ++ : ";
    r1++;
    r1.display();

    return 0;
}
