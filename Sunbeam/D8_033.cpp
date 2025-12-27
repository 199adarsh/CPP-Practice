#include <iostream>
using namespace std;

class Student {
public:
    int* marks;          // pointer that will store address of heap memory


    Student(int m) {
        marks = new int(m);   // new memory created on heap, value stored
    }



    // here we pass the object directly 
    Student(Student &s) {
        marks = new int(*s.marks);   // the passed objects value will be saved in new int 
    }



    void display() {
        cout << *marks << endl;     
    }
};

int main() {
    Student s1(90);      // object created, marks = 90

    Student s2 (s1);     // we dont pass the value we pass the object → s2 gets its own memory
    // Student s2 = s1  - standerd method of copy constructor    


    *s2.marks = 95;      // change only s2's marks

    s1.display();        // prints 90 (unchanged)
    s2.display();        // prints 95 (separate copy)

    return 0;
}

