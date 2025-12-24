#include <iostream>
#include<string>
using namespace std;

class employee {
private:
    int emp_id ;
    float emp_sal;
    string name;
    const float bonus = 1000;

public:
        employee (){
        cout << "Parameterless constructor is called\n "<< endl;

    }
    employee (int emp_id1 ,  int emp_sal1,  string name1 ){
        emp_id = emp_id1;
        emp_sal = emp_sal1;
        name = name1;

    }

    void input(){

        cout << "Enter Employee ID  : ";
        cin>> emp_id;
        cout << "Enter Employee Salary : ";
        cin>> emp_sal;
        cout << "Enter name of Employee  : ";
        cin>> name;    
    }

    void display(){
        cout << "Employee ID : "<< emp_id<< endl;
        cout << "Employee Salary : "<<emp_sal<< endl;
        cout << "Employee bounus is : "<<bonus<< endl;  
        cout << "Employee name  : "<<name << endl;    
    }        
    

    void updateSal( float us){
        emp_sal = us;
        cout << "Updated salary is :"<< emp_sal;
    }


    ~employee(){

        cout << "\nDestructor called " << endl;
    }
};



int main()
{

    employee  c1(01, 18000,"Ayushman");
    cout << "Default values are : \n "<< endl;
    c1.display();
    
    
    
    employee c2;
    cout << "Give user input values  : \n "<< endl;
    c2.input();
    c2.display();




    return 0;
}