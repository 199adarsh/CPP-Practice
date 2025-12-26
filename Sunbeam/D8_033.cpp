#include<iostream>
using namespace std;

class cylinder
{

 private:
  int r;
  int h;
  static double pi;

 public:
cylinder()
{
  r=25;
  h=15;
  cout<<"inside the constructor of class"<<endl;
}

cylinder(int radius,int height)// hya constructor la value pass karych ahe // 
{
  r=radius;
  h=height;
  cout<<"inside the parameterised constructor of class"<<endl;
}

void setRadius(){
  cout<<"enter radius"<<endl;
  cin >>r;

}

void setHeight(){
  cout<<"enter height"<<endl;
  cin >>h; 

}

int getHeight(){ 
return h;

}

int getRadius()
{
  return r;
}

void accept()
{
 
setHeight();
setRadius(); 
}

void display()
{
cout<<"Radius"<<getRadius()<<endl; 
cout<<"Height"<< getHeight()<<endl; 
calculate();   
}      

void calculate() 
{
   
   cout<<"volume of cylinder="<<(pi*r*r*h)<<endl; // aapn direct calculate karn print karu shaktoy !

}

~cylinder()
{
    cout<<"inside the destructor of class cylinder"<<endl;
}

};

double cylinder::pi=3.14; 

int main()                             
{
cylinder c1;

c1.accept();
c1.display();


return 0;

}

