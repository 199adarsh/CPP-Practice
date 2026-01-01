#include <iostream>
#include<string>
using namespace std;

class student {
private:
    int marks;
    string name;

public:
    student(string n , int v) : name(n), marks(v) {}
    
    friend void compareValues(student a, student b);
};


void compareValues(student a, student b) {
    if(a.marks > b.marks) {
        cout << a.name<<"'s marks are greater" << endl;

    } else if(a.marks < b.marks) {
        cout << b.name<<"'s marks are greater" << endl;
        

    } else {
        cout << "Both are equal" << endl;
    }
}

int main() {
    student objA("Pranav",50);
    student objB("Ayushman",30);
    
    compareValues(objA, objB);
    
    return 0;
}