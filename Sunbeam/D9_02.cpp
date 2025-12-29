#include <iostream>
#include<string>
using namespace std;


class Date{
    private :
        int day; 
        int month ;
        int year;

    public:
        Date() {
            cout << "Class Date : Constructor is called !" << endl;


        }

        void acceptDate(){
            cout << "Enter the Day : "<< endl;
            setDay();
            cout << "Enter the Month : " << endl;
            setMonth();
            cout << "Enter the Year : " << endl;
            setYear();

        }

        void setDay(){
            cin >> day; 

        }
        void setMonth(){
            cin >> month; 

        }
        void setYear(){
            cin >> year; 

        }
        
        void getDay(){
            cout << day; 

        }
        void getMonth(){
            cout <<month; 

        }
        void getYear(){
            cout << year; 

        }
        void displayDate(){
            cout << "Day : "<< endl;
            getDay();
            cout << "Month : " << endl;
            getMonth();
            cout << "Year : " << endl;
            getYear();

        }



};

class Employee{
    private :
        int id; 
        string Dept;
        Date d1;
    public:
        Employee() {
            cout << "Class Employee : Constructor is called !" << endl;
        }


        void acceptEmp(){
            cout << "Enter the Employee ID : "<< endl;
            setID();
            cout << "Enter the Employee Dept : " << endl;
            setName();
            cout << "Enter the Joining Date: " << endl;
            d1.acceptDate();

        }

        void setID(){
            cin >> id; 

        }
        void setName(){
            cin >> Dept; 

        }
        
        
        void getID(){
            cout << id; 

        }
        void getName(){
            cout <<Dept; 

        }

        void displayEmp(){
            cout << "ID : "<< endl;
            getID();
            cout << "Dept Name : " << endl;
            getName();
            cout << "Joining Date : " << endl;
            d1.displayDate();

        }



};

class Student{
    private :
        int RollNo; 
        string course;
        float marks;
        Date d1;
        Date d2;
    public:
        Student() {
            cout << "Class Student : Constructor is called !" << endl;
        }


        void acceptStud(){
            cout << "Enter the Studetn ID : "<< endl;
            setID();
            cout << "Enter the Course : " << endl;
            setCourse();
            cout << "Enter the Marks : " << endl;
            setMarks();
            cout << "Enter the Joining Date: " << endl;
            d1.acceptDate();
            cout << "Enter the Joining Date: " << endl;
            d2.acceptDate();
        }

        void setID(){
            cin >> RollNo; 

        }
        void setMarks(){
            cin >> marks; 

        }
        void setCourse(){
            cin >> course; 

        }
        
        
        void getID(){
            cout << RollNo; 

        }
        void getMarks(){
            cout << marks; 

        }
        void getCourse(){
            cout <<course; 

        }

        void displayStud(){
            cout << "Studetn ID : "<< endl;
            getID();
            cout << "Enter the Course : " << endl;
            getCourse();
            cout << "Enter the Marks : " << endl;
            getMarks();
            cout << "Joining Date: " << endl;
            d1.displayDate();
            cout << "Joining Date: " << endl;
            d2.displayDate();
        }
        



};

int main()
{
    int choice;
    Employee employee;
    Student student;
    cout << "\n" << endl;
    do {
        cout << "Menu:" << endl;
        cout << "1. Accept Employee Details" << endl;
        cout << "2. Display Employee Details" << endl;
        cout << "3. Accept Student Details" << endl;
        cout << "4. Display Student Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                employee.acceptEmp();
                break;
            case 2:
                employee.displayEmp();
                break;
            case 3:
                student.acceptStud();
                break;
            case 4:
                student.displayStud();
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}