#include <iostream>
#include<string>
using namespace std;

class student {
private:
    int rollNo ;
    float marks;
    string name;


public:
        student (){
        cout << "Parameterless constructor is called\n "<< endl;

    }
    student (int rollNo1 ,  int marks1,  string name1 ){
        rollNo = rollNo1;
        marks = marks1;
        name = name1;

    }

    void input(){

        cout << "Enter student ID  : ";
        cin>> rollNo;
        cout << "Enter student Marks : ";
        cin>> marks;
        cout << "Enter name of student  : ";
        cin>> name;    
    
    }

    void display()const{
        cout << "student ID : "<< rollNo<< endl;
        cout << "student Marks : "<<marks<< endl;
        cout <<"Your Grade is : " ; getGrade();
        cout << "student name  : "<<name << endl;    
    }        
    
    void getGrade() const {
        cout <<((marks>=90)?"A Grade" : (marks>= 75) ? "B Grade" : (marks >= 35) ? "Pass" : "Fail")<< endl;
    }



   
};



int main()
{

    student const c1(01, 18,"Ayushman");
    cout << "Default values are : \n "<< endl;
    c1.display();
    
    
    
    student c2;
    cout << "Give user input values  : \n "<< endl;
    c2.input();
    c2.display();





    return 0;
}