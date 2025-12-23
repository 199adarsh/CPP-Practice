#include <iostream>
using namespace std;

void addition(int a, int b, int c, float d){
    cout << "1st function called\nAdd: " << a+b+c+d << endl;
}

void addition(int a, int b, float c, float d){
    cout << "2nd function called\nAdd: " << a+b+c+d << endl;
}

void addition(int a, float b, float c, float d){
    cout << "3rd function called\nAdd: " << a+b+c+d << endl;
}

void addition(int a, int b, int c, int d){
    cout << "4th function called\nAdd: " << a+b+c+d << endl;
}

void addition(float a, float b, float c, float d){
    cout << "5th function called\nAdd: " << a+b+c+d << endl;
}

void addition(char a, int b, int c, float d){
    cout << "6th function called\nAdd: " << a+b+c+d << endl;
}


void addition(char a, float b, float c, float d){
    cout << "7th function called\nAdd: " << a+b+c+d << endl;
}

int main(){
addition(int(1), int(2), int(3), float(4.0566));
addition(int(2), int(5), float(1.5), float(2.5));
addition(int(1), float(2.2), float(2.3), float(2.6));
addition(int(1), int(2), int(3), int(4));
addition(float(1.1), float(1.2), float(1.3), float(1.4));
addition(char('a'), float(1.1), float(1.2), float(1.3));

    return 0;
}
