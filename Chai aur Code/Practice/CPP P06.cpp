
#include <iostream>
using namespace std;

class Student {
public:
    int* marks;        

   
    Student(int m) {
        marks = new int(m);   
    }


    Student(Student &s) {
        marks = new int(*s.marks);   // new memory + copy value (not pointer)
    }

    void display() {
        cout << *marks << endl;      
    }
};

int main() {
    Student s1(90);   

    //Student s2 = s1;     // deep copy → s2 gets its own memory
    Student s2 (s1);     // alternate (easy) way for deep copy


    *s2.marks = 95;  

    s1.display();        
    s2.display();       

    return 0;
}