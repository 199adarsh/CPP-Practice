#include <iostream>
#include <string>
using namespace std;

class Account {

    private :
        int accId;
        string accHolder ;
        float balance;
        
    public :
        Account (){
            cout << "Class Account : Param-less constructor callled " << endl;
        }// Parameter less constructor

        Account ( int Id , string holder ,float bal) {
	accId = Id;
	accHolder = holder;
	balance = bal;
	
	} // Prameterised constructor 


	virtual void accept(){		// To accept the details of user 
	cout << "Enter the Bank Account Id : ";
	cin >> accId;
	cout << "Enter the Account Holder : ";
	cin >> accHolder;
	cout << "Enter the Bank Balance: ";
	cin >> balance;
	}

	virtual void display(){ //To disply the details of user 
	cout << "Bank Account Id :" <<accId << endl;
	cout << "Account Holder : "<<accHolder << endl;
	cout << "Enter the Bank Balance: "<<balance<< endl;
	}
	
	virtual void calculateIntrest () = 0;
	


};

int main()
{



}