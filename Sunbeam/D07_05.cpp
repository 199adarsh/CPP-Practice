#include <iostream>
using namespace std;

class box{
public:
    float height = 5.06; 
    float width = 4.05;
    float length;

box(){
    cout << "Constructor called \n" ;
}

    int acceptdate() {
        cout << "Enter height: ";
        cin >> height;
        cout << "Enter width: ";
        cin >> width;
        cout << "Enter length : ";
        cin >> length;
        calculatevol(height, width, length);
        return 0;
    }
    void calculatevol(float height, float width,float length){
        cout<< "The volume is " << (height*width*length) << endl;
        
    }
};

int main()
{
    box b1;
    b1.acceptdate();

    return 0;
}