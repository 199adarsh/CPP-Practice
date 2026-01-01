#include <iostream>
#include <string>

using namespace std;

struct employee
{
    string name;
    int id;
    int salary;




    void acceptData(){

        cout << "Enter the name of employee :" ;
        cin >> name ;
        cout << "Enter the employee ID :";
        cin >> id;
        cout << "Enter the salary of employee :";
        cin >>  salary;

    }


    void printData (){
        cout << "Name of employee :" << name << endl;
        cout << "Employee ID :"<< id<< endl;
        cout << "Enter the salary of employee :" << salary << endl; 

    }
};



int main (){
    employee e1;
    cout << "Accepting Data from user\n" << endl;
    e1.acceptData();
    cout << "\nPrinting Data of user\n" << endl;
    e1.printData();

    return 0;
}