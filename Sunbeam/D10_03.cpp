#include<iostream>

using namespace std;

class Student {
public:
    int* real ;
    int* imag;

    Student(int r , int i) { 
        real= new int(r);
        imag = new int (i); 
    }
    
    /*Student(const Student &s) {
        real = new int(*s.real);
        imag= new int(*s.imag);   

    }*/

    void display() {
        cout << "Real Number :"<< *real << endl;
        cout << "Imaginary Number :"<< *imag << endl;
    }
};

int main() {
    Student s1(90, 100);
    Student s2 = s1;   

    *s2.real = 95; 
       
    s1.display();      
    s2.display();  
    
    return 0;
}