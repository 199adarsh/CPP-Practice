#include <iostream>
#include <string>
#include<vector>
using namespace std;

class employee{
private:
    
    string name ;
    double salary;

public:
    int id;

    void accept(){
        cout << "Enter the Employee ID : ";
        cin >>id;
        cout << "Enter the Employee Name : ";
        cin>> name;
        cout << "Enter the Employee Salary : " ;
        cin >> salary;
    };

    void display(){
        cout << "Employee ID : " << id << endl;
        cout << "Employee Name : " << name << endl;
        cout << "Enter the Employee Salary : " <<salary << endl;
    }


    void updateSalary(){
        cout << "Current Salary is : " << salary<< " Enter the Updated Salary :  ";
        cin >> salary;
    }
};


    void searchEmp(vector<employee> &emp){
    int searchId;
    cout << "\nEmployee : Search Employee\n ";
    cout << "Enter the Employee ID to search : ";
    cin >> searchId;


        for (int i = 0; i < 5; i++){
            if (emp[i].id == searchId){
                cout << "Employee Found !!" << endl;
                emp[i].display();
                break;
            }
        }
    }

    void updateSal(vector<employee> &emp){
        int searchId;
        cout << "\nEmployee : Update Employee Salary\n ";
        cout << "Enter the Employee ID to search : ";
        cin >> searchId;


        for (int i = 0; i < 5; i++){
            if (emp[i].id == searchId){
                cout << "Employee Found !!" << endl;
                emp[i].updateSalary();
                break;
            }
        }
    }

    void displayEmp(vector<employee> &emp){
        cout << "\nEmployee : Employee Details\n ";
        for (int i = 0; i < 5; i++){
                emp[i].display();
                cout <<"\n"<<endl;
                
            }
    }

    void acceptEmp(vector<employee> &emp){
        cout << "\nEmployee : Accept Employee Details\n ";
        for (int i = 0; i < 5 ; i++){
                cout <<"\n";
                emp[i].accept();
                
            }
    }
    
    


int main()
{
    int choice = 0;

    employee e1,e2,e3,e4,e5;
    vector<employee> emp = {e1,e2,e3,e4,e5};
       
    while(choice != 5){

        cout << "\nEmployee Details" << endl;
        cout << "1.Accept Employee Details" << endl;
        cout << "2.Search Employee Details" << endl;
        cout << "3.Display Employee Details" << endl;
        cout << "4.Update Employee Salary" << endl;
        cout << "5.Exit Employee Details" << endl;
        cin>> choice;

        switch (choice)
        {
        case 1:
            acceptEmp(emp);
            break;
        case 2: 
            searchEmp(emp);
            break;
        case 3 :
            displayEmp(emp);
            break;
        case 4 : 
            updateSal(emp);
            break;
        case 5 :
            return 0;

        default:
            cout <<"Invalid Choice !" <<endl;
            break;
        }
    }
    
    return 0;
}