#include <iostream>
#include <string>
using namespace std;


double add (double num1 , double num2){
    try{
        if (num1 <= 0 || num2 <= 0) throw string("Numbers must not be Negetive");
        cout << "Addition of " << num1 << " & " << num2 << " is : " << (num1 + num2) << endl;
    }
    catch(const string & e)
    {
        cerr << e << '\n';
    }
    return 0;   
}


double sub (double num1 , double num2){
    try{
        if (num1 < num2 ) throw string("Result must not be Negetive");
        cout << "Subtraction of " << num1 << " & " << num2 << " is : " << (num1 - num2) << endl;
    }
    catch(const string & e)
    {
        cerr << e << '\n';
    }
    return 0;
    
}


double multi  (double num1 , double num2){
    try{
        if (num1 <= 0 || num2 <= 0) throw string("Numbers must not be Negetive");
        cout << "Multiplication of " << num1 << " & " << num2 << " is : " << (num1 * num2) << endl;
    }
    catch(const string & e)
    {
        cerr << e<< '\n';
    }
    return 0;
    
}



double div (double num1 , double num2){
    try{
        if (num2 < 0) throw string("Denominator must not be Negetive");
        cout << "Division of " << num1 << " & " << num2 << " is : " << (num1 / num2) << endl;
    }
    catch(const string & e)
    {
        cout<< e << '\n';
    }
    return 0;
    
}

int main()
{
    int choice;
    double num1, num2;
    cout << "Enter Frist Number :" ;
    cin >> num1;
    cout << "Enter Second Number :" ;
    cin >> num2;

    while(choice != 0){
        try
        {
            
            cout << "Menue :" << endl;
            cout << "1. Addition" << endl;
            cout << "2. Subtraction" << endl;
            cout << "3. Multiplication" << endl;
            cout << "4. Division " << endl;
            cout << "0. Exit " << endl;
            cin >> choice;
            if (choice > 4) throw string ("Invalid Choice !") ;
        }
        catch(string &e)
        {
            cout  << e << '\n';
        }
                


        switch(choice){

            case 1 :
                add(num1, num2);
                break;
            case 2 :
                sub(num1, num2);
                break;
            case 3 :
                multi(num1, num2);
                break;
            case 4 :
                div(num1, num2);
                break;
            case 0 : 
                return 0 ;

            default :
                cout << "Invalid Choice !"<< endl;                
            }

    }


    return 0;
}
