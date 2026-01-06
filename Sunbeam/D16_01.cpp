#include <iostream>
#include <string>
using namespace std;

template<typename T>

class Temprature {
    private : 
        T celcius;

    public :

        Temprature(T celc){
            celcius = celc;

        }

        T show (){
            cout << "Celcius  :" << celcius << endl;	
            cout << "Celcius to Frenheit :" << (celcius*(9/5))+32 << endl;
            return 0;

        } 
};



int main()
{
    Temprature <int> t (30);
    t.show();
    
    Temprature<float> t2(30.5);
    t2.show();
    
    Temprature <double> t3(30.75);
    t3.show();
    return 0;
}