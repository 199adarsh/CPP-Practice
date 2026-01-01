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

    void display() const {
        cout << num << "/" << den << endl;
    }
};

int main() {
    Rational r1(1,2), r2(3,4);

    Rational sum = r1.add(r2);
    Rational diff = r1.subtract(r2);
    Rational prod = r1.multiply(r2);

    sum.display();
    diff.display();
    prod.display();

    return 0;
}
