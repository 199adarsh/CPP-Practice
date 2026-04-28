#include <iostream>
using namespace std;

class Employee {
    string empName;
    int empID;
    double salary;
    string dept;

public:
    Employee() {}

    Employee(string empName, int empID, double salary, string dept) {
        this->empName = empName;
        this->empID = empID;
        this->salary = salary;
        this->dept = dept;
    }



    void displayEmp() {
        cout << "Employee Name: " << empName << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Employee Salary: " << salary << endl;
        cout << "Employee Department: " << dept << endl;

    }
};


class Node {
public:
    Employee data;
    Node* next;

    Node(Employee e) {
        data = e;
        next = NULL;
    }
};



class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void addFirst(Employee e) {
        Node* newNode = new Node(e);
        newNode->next = head;
        head = newNode;
    }



    void deleteFirst() {
        if (head == NULL) {
            cout << "List is Empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "First Employee Deleted." << endl;
    }



    void displayEmp() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            temp->data.displayEmp();
            cout << "\n";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    int choice =0;

    Employee e1("Ayushman", 4, 75000, "AIDS");
    Employee e2("Pranav", 11, 7000, "DS");
    Employee e3("Jagdish", 45, 80000, "AIDS");

        while(choice != 4){

        cout << "\nEmployee Details" << endl;
        cout << "1.Add Frist Employee" << endl;
        cout << "2.Display Employee Details" << endl;
        cout << "3.Delete Employee Details" << endl;
        cout << "4.Exit the Program \n";
        cin>> choice;

        switch (choice)
        {
        case 1:
            list.addFirst(e1);
            cout << "1st Employee Added !"<< endl;
            list.addFirst(e2);
            cout << "2nd Employee Added !"<< endl;
            list.addFirst(e3);
            cout << "3rd Employee Added !"<< endl;
            cout <<"\n";
            break;
        case 2: 
            cout << "Employees:" << endl;
            list.displayEmp();
            break;
        case 3 :
            list.deleteFirst();
            cout << "\nAfter deleting first employee:" << endl;
            list.displayEmp();
            break;
        case 4 : 
            cout <<"Exited the Program" << endl;
            return 0;
            break;

        default:
            cout <<"Invalid Choice !" <<endl; 
           break;
        }
    }
    
    return 0;
}

