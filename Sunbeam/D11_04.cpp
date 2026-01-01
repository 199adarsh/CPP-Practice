#include <iostream>
#include <string>
using namespace std;


class employee {

        int id;
        double salary;

    public:
        employee(){
            cout << "Employee : Parameterless constructor called\n" ;
        }
        employee(int i , int s): id(i), salary(s){
            cout << "Employee ID : " << i << " Employee Salary : " << s << endl;           
        }

        double getSalary(){
            return salary;
        }
};

int main()
{
    
    return 0;
}