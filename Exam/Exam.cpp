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
    } // Parameterised constructor called

    virtual ~Account() {
        // virtual destructor just for safety to destroy the data
    }

    virtual void accept() { 		// accept the input for 1. Account ID , 2.Ac
        	try {
            		cout << "Enter the Bank Account Id : ";
            		cin >> accId;

            		cout << "Enter the Account Holder : ";
            		cin >> accHolder;

            		cout << "Enter the Bank Balance: ";
            		cin >> balance;

            		if (balance < 0) 
                        throw string("Balance cannot be negative!");  
            } 
		    catch (const string& e) { 
                cerr << "ERROR : " << e << endl;   // catched the error
            }
    	}

    virtual void display() {
        		cout << "Bank Account Id : " << accId << endl;
        		cout << "Account Holder : " << accHolder << endl;
        		cout << "Bank Balance  : " << balance << endl;
    }

    virtual void calculateIntrest() = 0;   // pure virtual function
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

            		if (interestRate < 0) 
                        throw string("Intrest Rate cannot be less than zero"); 
            }
	        catch (const string& e) {	
                cerr << "ERROR : " << e << endl;  // catched the error
            }
    }

    void display() override {
        	calculateIntrest();   // calculating before showing
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
        	balance = balance - serviceCharge;   // minus service charge
    }

    void accept() override {
        	Account::accept();
        	cout << "Enter the Service Charge : ";
        	cin >> serviceCharge;
    }

    void display() override {
        	calculateIntrest();   // calculating before showing
        	Account::display();
        	cout << "Service Charges : " << serviceCharge << endl;
        	cout << "\n";
    }
};

int main() {
    int choise;

    savingsAccount s;
    CurrentAccount c;

    Account* ptr = NULL;   // base class pointer

    do {
        	cout << "Menue:" << endl;
        	cout << "1. Enter Savings Account Details:" << endl;
        	cout << "2. Enter Current Account Details:" << endl;
        	cout << "3. Display Savings Account using base-class pointer:" << endl;
        	cout << "4. Display Current Account using base-class pointer:" << endl;
        	cout << "5. Exit :" << endl;
        	cin >> choise;

        switch (choise) {
	case 1:
		cout << "\nEnter Savings Account Details:" << endl;
		ptr = &s;          // pointing base pointer to savings
		ptr->accept();
		break;

	case 2:
		cout << "\nEnter Current Account Details:" << endl;
		ptr = &c;          // pointing base pointer to current
		ptr->accept();
		break;

	case 3:
            cout << "\nSaving Account Details: " << endl;
            s.display();
		break;

	case 4:
        
            cout <<"\nCurrent Account Details: "<<endl;
            c.display();
		break;

	case 5 :
		cout << "Exiting program..." << endl;
		break;
			
	default:
		cout << "Invalid Choice!" <<endl;	
	}	

	} while(choise != 5);

    return 0;
}
