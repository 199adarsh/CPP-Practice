#include <iostream>
#include<string>
using namespace std;

class cylinder {
private:
    int height , radius;
    const double pi = 3.147;

public:
    cylinder (){
        cout << "\nParameterless constructor is called "<< endl;

    }
    cylinder (int height1 ,  int radius1 ){
        cout << "Parametered constructor is called \n" ;
        height = height1;
        radius = radius1;

    }
     pi = 3.7;
    

    void input(){
            setHeight();
            setRadius();
   
    }

    void display(){
        cout << "The height of cylinder : "<< height<< endl;
        cout << "The radius of cylinder : "<<radius<< endl;
        cout <<"Volume of cylinder is :"<<calVol();
   ~
    }        
    
    int  getRadius(){
        return radius ;
    }
    int  getHeight(){
        return height ;
    }


    void setRadius(){
        cout<< "Enter the radius of cylinder :";
        cin>> radius ;
    }

    void setHeight(){

        cout<< "Enter the height of cylinder :";
        cin>> height ;
    }

    double calVol (){
        return (pi * radius * radius * height);

    }

    ~cylinder(){

        cout << "\nDestructor called " << endl;
    }
};


int main()
{
   cylinder c1(15, 18 );
    cout << "Default values are : \n "<< endl;
    c1.display();
    
    
    
    cylinder c2;
    cout << "Give user input values  : \n "<< endl;
    c2.input();
    c2.display();

    

    

    cout<< "\nParameterd Constructor is called :" << endl;
    c2.display();

    return 0;
}