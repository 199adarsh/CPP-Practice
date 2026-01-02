
#include <iostream>
using namespace std;

class Student {
public:


    int a, b;

    Student(int x, int y) {
        a = x; b = y;
    }

    Student operator+(Student &c) {
        cout << "A" << (a + c.a ) <<"B"<< (b + c.b) << endl;
    }





};

int main() {

    Student c1(2, 3), c2(4, 5);
    Student c3 = c1 + c2;
 

     

    return 0;
}

