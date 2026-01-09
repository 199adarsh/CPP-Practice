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
	cout << "Bank Balance: "<<balance<< endl;
	
	}
	
	virtual void calculateIntrest () = 0;	//Exception rule inside accept(): If balance < 0, throw an exception 
	


}; // Account class closed 


class savingsAccount : class Account {
	private: 
		float interestRate;
	public:
		virtual void calculateIntrest () override{ // overriden the virtual funtion of calculate intrest 
		balance = balance + (balance ×interestRate /100)
		}

	void accept (){
		Account :: accept();
		try {
			cout << "Enter the Intrest Rate : ";
			cin >> interestRate;
			if (interestRate < 0) throw string(Intrest Rate cant be less than zero);
		}
		catch (string * m){
			cout << "ERROR : " << m <<endl;		// catched the error of intrest rate (if intrest rate < 0 )
		}
		
	}
	void display(){
		Account :: display();
		cout << "Intrest Rate : " << interestRate<< endl;
		cout << "\n";
	}



};


class CurrentAccount : class Account {
	private:
		float serviceCharge;
	public :

	void calculateIntrest () override{
	balance = balance − serviceCharge;
	}
	
	void accept (){
		Account :: accept();
		cout << "Enter the Intrest Rate : ";
		cin >> interestRate;	
	}
	void display(){
		Account :: display();
		cout << "Service Charges : " << serviceCharge<< endl;
		cout << "\n";
	}

	
	
};

int main()
{
	int choise;
	SavingsAccount s;
 	CurrentAccount c;
 	Account* ptr = &s;
	

	do{
	
	cout << "Menue:" <<endl;
	cout <<"1. Enter Savings Account Details:" <<endl;
	cout <<"2. Enter Current Account Details:" <<endl;
	cout <<"3. Display Savings Account using base-class pointer:" <<endl;
	cout <<"4. Display Current Account using base-class pointer:" <<endl;
	cout <<"5. Exit	:" <<endl;
	cin >> choise;


	}



}