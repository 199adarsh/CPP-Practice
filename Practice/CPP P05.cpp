#include<iostream>

using namespace std;

class Student {
public:
    int* marks;

    Student(int m) { 
        marks = new int(m); 
    }

    void display() {
         cout << *marks << endl;
    }
};

int main() {
    Student s1(90);
    Student s2 = s1;   // shallow copy (same pointer)

    *s2.marks = 95;    // modifies BOTH

    s1.display();      // 95  (bad!)
    s2.display();      // 95
}
