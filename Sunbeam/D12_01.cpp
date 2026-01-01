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

        double getSalary(){ 
            return salary; 
        }

        double getID(){ 
            return id; 
        }

        void setSalary(double sal){ 
            salary = sal; 
        }

        void setID(int i){ 
            id = i; 
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

class manager : public employee {
        double bonus;

    public:
        manager(){
            cout << "Manager : Parameterless constructor called\n";
        }

        manager(int i , double s ,double b ): employee(i, s), bonus(b){
            cout << "Employee Bonus : " << b << endl;
        }

        double getBonus(){ 
            return bonus; 
        }

        void setBonus(double b){ 
            bonus = b; 
        }

        void acceptBonus (){
            employee::accept();
            cout << "Enter the Bonus : ";
            cin >> bonus;
        }

        void displayBonus (){
            employee::display();
            cout << "Bonus: " << bonus << endl;
        }
};

class salesman : public employee {
        double commission;

    public:
        salesman(){
            cout << "Salesman : Parameterless constructor called\n";
        }

        salesman(int i , double s ,double c ) : employee(i, s), commission(c){
            cout << "Employee Commission : " << c << endl;
        }

        double getcommission(){
             return commission;
        }

        void setcommission(double c){ 
            commission = c; 
        }

        void acceptCommission (){

            employee::accept();

            cout << "Enter the commission : ";
            cin >> commission;
        }

        void displayCommission (){
            employee::display();
            cout << "commission: " << commission << endl;
        }
};

class salesmanager : public manager , public salesman {

public:
    salesmanager(){
        cout << "Salesmanager : Parameter less constructor " << endl;
    }

    salesmanager(int i , double s ,double b, double c): manager(i, s, b), salesman(i, s, c){
        cout << "Salesmanager constructed\n";
    }
};

int main()
{
    salesmanager sm;
    int choice;

    do
    {
        cout << "\n------ MENU ------\n";
        cout << "1. Accept SalesManager Data\n";
        cout << "2. Display SalesManager Data\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter Manager Details \n";
                sm.acceptBonus();         

                cout << "\nEnter Salesman Details \n";
                sm.acceptCommission();    
                break;

            case 2:
                cout << "\nManager Info \n";
                sm.displayBonus();

                cout << "\nSalesman Info \n";
                sm.displayCommission();
                break;

            case 3:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}

