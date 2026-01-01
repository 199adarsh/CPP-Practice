#include <iostream>
#include<string>
using namespace std;

class chair {
private:
    int height , width;
    static double price;
    string colour;

public:
    chair (){
        cout << "Parameterless constructor is called "<< endl;

    }
    chair (int height1 ,  int width1,  string colour1 ){
        height = height1;
        width = width1;
        colour = colour1;

    }

    void input(){

        cout << "Enter height of chair : ";
        cin>> height;
        cout << "Enter width of chair : ";
        cin>> width;

        cout << "Enter colour of chair : ";
        cin>> colour;    
    }

    void display(){
        cout << "The height of chair : "<< height<< endl;
        cout << "The width of chair : "<<width<< endl;
        cout << "The price of chair : "<<price<< endl;
        cout << "The colour of chair : "<<colour << endl;    
    }        
    
    static void setPrice (double p1){
    price = p1;
    }

    ~chair(){

        cout << "\nDestructor called " << endl;
    }
};

 double chair::price = 2000;

int main()
{
    chair c1;
    chair c2(100,200,"Red");

    
    c1.input();
    c1.display();

    cout<< "\nParameterd Constructor is called :" << endl;
    c2.display();

    return 0;
}