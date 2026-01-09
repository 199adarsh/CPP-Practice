#include <iostream>
#include <string>
using namespace std;

class Account {
	public:
    		int accId;
    		string accHolder;
    		float balance;

    Account() {
        	cout << "Class Account : Param-less constructor callled " << endl;
    } // Parameter less constructor

    Account(int Id, string holder, float bal) {
   	     	accId = Id;
        	accHolder = holder;
        	balance = bal;
    } // Parameterised constructor

    virtual void accept() {
        	try {
            		cout << "Enter the Bank Account Id : ";
            		cin >> accId;
            		cout << "Enter the Account Holder : ";
            		cin >> accHolder;
            		cout << "Enter the Bank Balance: ";
            		cin >> balance;
            		if (balance < 0) throw string("Balance cannot be negative!"); 	} 
		catch (const string& e) { cerr << "ERROR : " << e << endl; // catched the error of balance (if balance < 0)        }
    	}

    virtual void display() {
        		cout << "Bank Account Id :" << accId << endl;
        		cout << "Account Holder : " << accHolder << endl;
        		cout << "Bank Balance: " << balance << endl;
    }

    virtual void calculateIntrest() = 0; // Exception rule inside accept(): If balance < 0, throw an exception
};





class savingsAccount : public Account {
private:
    	float interestRate;

public:
    void calculateIntrest() override {
        	balance = balance + (balance * interestRate / 100);
    }

    void accept() override {
        	Account::accept();
        	try {
            		cout << "Enter the Intrest Rate : ";
            		cin >> interestRate;
            		if (interestRate < 0) throw string("Intrest Rate cannot be less than zero"); }
	 catch (const string& e) {	cerr << "ERROR : " << e << endl; // catched the error of interest rate (if interest rate < 0)}
    }

    void display() override {
        	savingsAccount::calculateIntrest();
        	Account::display();
        	cout << "Intrest Rate : " << interestRate << endl;
        	cout << "\n";
    }
};







class CurrentAccount : public Account {
private:
    float serviceCharge;

public:
    void calculateIntrest() override {
        	balance = balance - serviceCharge;
    }

    void accept() override {
        	Account::accept();
        	cout << "Enter the Service Charge : ";
        	cin >> serviceCharge;
    }

    void display() override {
        	CurrentAccount::calculateIntrest();
        	Account::display();
        	cout << "Service Charges : " << serviceCharge << endl;
        	cout << "\n";
    }
};

int main() {
    int choise;
    savingsAccount s;
    CurrentAccount c;
    Account* ptr = new CurrentAccount;

    do {
        	cout << "Menue:" << endl;
        	cout << "1. Enter Savings Account Details:" << endl;
        	cout << "2. Enter Current Account Details:" << endl;
        	cout << "3. Display Savings Account using base-class pointer:" << endl;
        	cout << "4. Display Current Account using base-class pointer:" << endl;
        	cout << "5. Exit	:" << endl;
        	cin >> choise;

        switch (choise) {
	case 1:
		cout << "\nEnter Savings Account Details:" << endl;
		ptr->accept();
		break;
	case 2:
		cout << "\nEnter Current Account Details:" << endl;
		c.accept();
		break;
	case 3:
                			cout << "\nSaving Account Details: " << endl;
                			s.display();
		break;
	case 4:
		cout <<"\nCurrent Account Details: "<<endl;
		ptr->display();
		break;
	case 5 :
		return0;
			break;
			
	default:
		cout << "Invalid Choice!" <<endl;	
		return 0;			
	}	


	}while(choise != 5 );

return 0;

}


//fix the try catch throw and possible errors and add comments