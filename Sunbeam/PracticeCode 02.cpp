#include <iostream>
using namespace std;
class Point {
public:
    int x;
    int y;
};

int main() {
    Point a{10, 20};
    Point b = a;   // copies values

    b.x = 99;

    cout << a.x<< a.y;   // prints 10 (independent)
    cout << b.x << b.y;
}
