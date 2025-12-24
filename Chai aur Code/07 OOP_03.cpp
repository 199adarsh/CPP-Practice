#include <iostream>
using namespace std;

class Student {
public:
    static int count;   // static data member

    Student() {
        count++;
    }
    
};

class Math {
public:
    static int add(int a, int b) { // if we use static we dont need to create a object 
        return a + b;
    }
};


// Definition of static data member
int Student::count = 0;

int main() {
    Student s1;// this calls constructor and const.. increses the count
    Student s2;
    Student s3;
    
    cout << Math::add(5, 3)<< endl;

    
    cout << "\nNumber of students: " << Student::count << endl;

    return 0;
}
