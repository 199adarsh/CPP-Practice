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
            cout << "\n" << endl;
            return 0;

        } 
};



int main()
{
    cout << "Celcius (Int Data Type : ) " ;
    Temprature <int> t (50);
    t.show();
    
    cout << "Celcius (Float Data Type : ) " ;
    Temprature<float> t2(40.5);
    t2.show();

    
    cout << "Celcius (Double Data Type : )  " ;
    Temprature <double> t3(20.75);
    t3.show();
    return 0;
}