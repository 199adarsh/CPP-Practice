#include <iostream>
using namespace std;
void max (int a , int b){
    if (a>b){cout<< "A is grater then B";}
    else{
        cout << "B is grater than A";
    }
}

void max (int a , int b, int c){
    if (a>b && a> c){cout<< "A is Grater";}
    else if (b>c && b> a){cout<< "B is Grater";}
    else{
        cout << "C is Grater ";
    }
}


void max (int a , int b, int c , int d){
    if (a>b && a> c && a>d){cout<< "A is Grater";}
    else if (b>c && b> a && b>d){cout<< "B is Grater";}
    else if (c>b && b> a && b>d){cout<< "C is Grater";}
    
    else{
        cout << "D is Grater ";
    }
}
int main()
{
    int a,b,c,d;
    cout <<"\n1st Function"<< endl;
    cout << "Enter two values" ;
    cin>> a>>b;
    max(a,b);
    cout <<"\n "<<endl;

    cout <<"\n2nd Function"<< endl;
    cout << "Enter three values" ;
    cin>> a>>b>>c;
    max(a,b,c);
    cout <<"\n "<<endl;

    cout <<"\n3rd Function"<< endl;
    cout << "Enter four values" ;
    cin>> a>>b>>c>>d;
    max(1,2,3,4);    

    
    return 0;
}