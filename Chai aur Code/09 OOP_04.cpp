#include <iostream>
using namespace std;

class Student {
private:
    const int rollNo;     // constant data member
    string name;

public:
    // Constructor with initializer list
    Student(int r, string n) : rollNo(r), name(n) {}


    // Const member function
    void display() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }

    // Non-const function (can modify non-const data)
    void changeName(string n) {
        name = n;
        
    }
};

int main() {
    Student s1(101, "Alice");

    s1.display();          // allowed
    s1.changeName("Bob");  // allowed
    s1.display();

    Student s2(102,"alen");

    return 0;
}
