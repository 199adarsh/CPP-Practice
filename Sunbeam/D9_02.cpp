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
            cout << "Enter the Day : ";
            setDay();
            cout << "Enter the Month : " ;
            setMonth();
            cout << "Enter the Year : " ;
            setYear();
            cout << "\n" << endl;

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
            cout << "Day : ";
            getDay();
            cout << "  Month : " ;
            getMonth();
            cout << "  Year : ";
            getYear();
            cout << "\n" << endl;
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
            cout << "---- Enter Employee Details ----" << endl;
            cout << "\nEnter the Employee ID : "<< endl;
            setID();
            cout << "Enter the Employee Dept : " << endl;
            setName();
            cout << "\nEnter the Joining Date: " << endl;
            d1.acceptDate();
            cout << "\n" << endl;

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
            cout << "\n---- Employyee Details ----" << endl;
            cout << "ID : ";
            getID();
            cout << "\nDept Name : " ;
            getName();
            cout << "\nJoining Date : " << endl;
            d1.displayDate();
            cout <<endl;
            cout << "\n" << endl;

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
            cout << "---- Enter Student Details ----" << endl;
            cout << "Enter the Studetn ID : ";
            setID();
            cout << "Enter the Course : " ;
            setCourse();
            cout << "Enter the Marks : " ;
            setMarks();
            cout << "Enter the Joining Date: " ;
            d1.acceptDate();
            cout << "Enter the End Date: " ;
            d2.acceptDate();
            cout << "\n" << endl;
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
            cout << RollNo<<endl;

        }
        void getMarks(){
            cout << marks<<endl; 

        }
        
        void getCourse(){
            cout <<course<<endl; 

        }

        void displayStud(){
            cout << "\n---- Student Details ----" << endl;
            cout << "Student ID : ";
            getID();
            cout << "Course : " ;
            getCourse(); 
            cout << "Marks : " ;
            getMarks();
            cout << "Joining Date: " ;
            d1.displayDate();
            cout << "Joining Date: " ;
            d2.displayDate();
            cout << "\n" << endl;
        }
        



};

int main()
{
    int choice;
    Employee employee;
    Student student;

    
    cout << "\n" << endl;
    do {
        cout << "\n" << endl;
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