#include<iostream>

using namespace std;

class Complex {
public:
    int* real ;
    int* imag;

    Complex(int r , int i) { 
        real= new int(r);
        imag = new int (i); 
    }
    
    Complex(const Complex &s) {
        real = new int(*s.real);
        imag= new int(*s.imag);   

    }

    void display() {
        cout << "Real Number :"<< *real << endl;
        cout << "Imaginary Number :"<< *imag << endl;
    }
};

int main() {
    Complex s1(90, 100);
    Complex s2 (s1);   

    s2.display();
    cout << "After changing :" << endl;
    *s2.real = 95; 
    cout << "S1 Object \n" << endl;
    s1.display();      
    cout << "S2 Object \n" << endl;
    s2.display();  
    
    return 0;
}