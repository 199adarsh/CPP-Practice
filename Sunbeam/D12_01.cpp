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

        employee(int i , double s): id(i), salary(s){
            cout << "Employee ID : " << i << " Employee Salary : " << s << endl;           
        }

        void accept (){
            cout << "Enter the Employee ID : ";
            cin >> id;
            cout << "Enter the Employee Salary : ";
            cin >> salary;
        }

        void display (){
            cout << "Employee ID : " << id << endl;
            cout << "Employee Salary : " << salary << endl;
        }
};

class manager : public virtual employee {

        double bonus;

    public:
        manager(){
            cout << "Manager : Parameterless constructor called\n";
        }

        manager(int i , double s ,double b ): employee(i, s), bonus(b){
            cout << "Employee Bonus : " << b << endl;
        }

    protected :
        void acceptBonus (){
            cout << "Enter the Bonus : ";
            cin >> bonus;
        }

        void displayBonus (){
            cout << "Bonus: " << bonus << endl;
        }
};

class salesman : public virtual employee {

        double commission;

    public:
        salesman(){
            cout << "Salesman : Parameterless constructor called\n";
        }

        salesman(int i , double s ,double c ) : employee(i, s), commission(c){
            cout << "Employee Commission : " << c << endl;
        }

    protected :
        void acceptCommission (){
            cout << "Enter the commission : ";
            cin >> commission;
        }

        void displayCommission (){
            cout << "commission: " << commission << endl;
        }
};

class salesmanager : public manager , public salesman {

    public:
        salesmanager(){
            cout << "Salesmanager : Parameterless constructor called\n";
        }

        salesmanager(int i , double s ,double b, double c): employee(i , s) , manager(i , s , b) , salesman(i , s , c){
            cout << "Salesmanager constructor\n";
        }

        void accept (){
            // manager::accept(); alternate meathod wihout virtual 
            employee::accept();
            acceptBonus();
            acceptCommission();
        }

        void display (){
            employee::display();
            displayBonus();
            displayCommission();
        }
};
int main()
{
    salesmanager sm;
    int choice;

    do{
        cout << "\n1. Accept Details";
        cout << "\n2. Display Details";
        cout << "\n3. Display Parameterized Constructor Details";
        cout << "\n0. Exit";
        cout << "\nEnter choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                sm.accept();
                break;

            case 2:
                cout << "\nSalesmanager Details \n";
                sm.display();
                break;

            case 3:
            {
                cout << "\nParameterized Salesmanager \n";
                salesmanager temp(101 , 50000 , 7000 , 3000);
                temp.display();
                break;
            }

            case 0:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    }while(choice != 0);

    return 0;
}

