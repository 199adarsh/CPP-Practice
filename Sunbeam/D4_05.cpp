#include<iostream>
#include <string>

using namespace std;
struct employye {
    string emp_name ;
    int emp_id ;
    int emp_salry ;
    
    employye(string name, int id, int salary) {
        emp_name = name;
        emp_id = id;
        emp_salry = salary;
    }
};



int main (){

    employye e1("Ayushman" , 001 , 4500);

    cout << "Enter Employee Name :" <<endl; 
    cin >> e1.emp_name ;
    cout << "Enter Employee Id :" << endl; 
    cin>> e1.emp_id ;
    cout << "Enter Employee Salry :" << endl;
    cin>> e1.emp_salry ;


    cout << "Employee Name :" << e1.emp_name << endl;
    cout << "Employee Id :" << e1.emp_id << endl;
    cout << "Employee Salry :" << e1.emp_salry << endl;

    return 0;
}