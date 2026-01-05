#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class employee {


    int id;
    double salary;

public:
    employee() {
        cout << "Employee : Parameterless constructor called\n";
    }

    employee(int i, double s) : id(i), salary(s) {
        cout << "Employee ID : " << i << " Employee Salary : " << s << endl;
    }

    void setId(int i) { id = i; }
    void setSalary(double s) { salary = s; }

    int getID() const { return id; }
    double getSalary() const { return salary; }

    virtual void accept() {
        cout << "Enter the Employee ID : ";
        cin >> id;
        cout << "Enter the Employee Salary : ";
        cin >> salary;
    }

    virtual void display() {
        cout << "Employee ID : " << id << endl;
        cout << "Employee Salary : " << salary << endl;
    }

    virtual ~employee() {}
};







class manager : public virtual employee {

    double bonus;

public:
    manager() {
        cout << "Manager : Parameterless constructor called\n";
    }

    manager(int i, double s, double b) : employee(i, s), bonus(b) {
        cout << "Employee Bonus : " << b << endl;
    }

    void setBonus() {
        cout << "Enter the Manager Bonus : ";
        cin >> bonus;
    }

    double getBonus() const { return bonus; }

    void accept() override {
        employee::accept();
        setBonus();
    }

    void display() override {
        employee::display();
        cout << "Bonus : " << bonus << endl;
    }
};








class salesman : public virtual employee {

    double commission;

public:
    salesman() {
        cout << "Salesman : Parameterless constructor called\n";
    }

    salesman(int i, double s, double c) : employee(i, s), commission(c) {
        cout << "Employee Commission : " << c << endl;
    }

    void setCommission() {
        cout << "Enter the Salesman Commission : ";
        cin >> commission;
    }

    double getCommission() const { return commission; }

    void accept() override {
        employee::accept();
        setCommission();
    }

    void display() override {
        employee::display();
        cout << "Commission : " << commission << endl;
    }
};







class salesmanager : public manager, public salesman {

public:
    salesmanager() {
        cout << "Salesmanager : Parameterless constructor called\n";
    }

    salesmanager(int i, double s, double b, double c)
        : employee(i, s), manager(i, s, b), salesman(i, s, c) {
        cout << "Salesmanager constructor\n";
    }

    void accept() override {
        employee::accept();
        setBonus();
        setCommission();
    }

    void display() override {
        employee::display();
        cout << "Bonus : " << getBonus() << endl;
        cout << "Commission : " << getCommission() << endl;
    }
};




int main() {
    int size ;
    cout << "Enter the size of Array :" ;
    cin >> size;
    employee* arr[size];

    int countManager = 0;
    int countSalesman = 0;
    int countSalesManager = 0;
    int countEmp =0;
    int show;
    
    for (int i = 0; i < size; i++) {
        cout << "\nEnter Choice \n1. Manager\n2. Salesman\n3. SalesManager\n ";
        int choice;
        cin >>choice;

        switch (choice) {
            case 1:
                arr[i] = new manager();
                countManager++;
                break;

            case 2:
                arr[i] = new salesman();
                countSalesman++;
                break;

            case 3:
                arr[i] = new salesmanager();
                countSalesManager++;
                break;

            default:
                cout << "Invalid Enter Employee Detials\n";
                arr[i] = new employee();
                countEmp++;
        }

        arr[i]->accept();
    }

    
    cout << "\n\nTotal Managers    : " << countManager;
    cout << "\n\nTotal Employees    : " << countEmp;
    cout << "\nTotal Salesmen      : " << countSalesman;
    cout << "\nTotal SalesManagers : " << countSalesManager << "\n";

    while(show != 0){  
        cout << "\nSelect Role to Display \n";
        cout << "1 Managers\n";
        cout << "2 Salesmen\n";
        cout << "3 SalesManagers\n";
        cout << "4 All\n";
        cout <<"0 Exit \n";
        cout << "Enter choice: ";

        
        cin >> show;

        cout << "\nRESULT \n";

            for (int i = 0; i < size; i++) {
                switch (show) {

                    case 1:
                        if (typeid(*arr[i]) == typeid(manager)){
                            cout << "Manager" << endl;
                            arr[i]->display();
                            cout << "\n";}
                        break;

                    case 2:
                        if (typeid(*arr[i]) == typeid(salesman)){
                            cout << "SalesMan" << endl;
                            arr[i]->display();
                            cout << "\n";}
                        break;

                    case 3:
                        if (typeid(*arr[i]) == typeid(salesmanager)){
                            cout << "Salesmanager" << endl;
                            arr[i]->display();
                            cout << "\n";}
                        break;

                    case 4:
                        arr[i]->display();
                        cout << "\n";
                        break;
                    
                    case 0 :  
                        cout << "Invalid display choice\n";
                        i = size;
                        break;
                    default:
                        cout << "Invalid display choice\n";
                        i = size;
                        break;
                }
            }
    }

    for (int i = 0; i < size; i++)
        delete arr[i];

    return 0;
}
