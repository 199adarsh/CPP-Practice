#include <iostream>
#include <string>
using namespace std;

class Account {
        
    public :
      	int accId;
        string accHolder ;
        float balance;

        Account (){
            cout << "Class Account : Param-less constructor callled " << endl;
        }// Parameter less constructor

        Account ( int Id , string holder ,float bal) {
	accId = Id;
	accHolder = holder;
	balance = bal;
	
	} // Prameterised constructor 


	virtual void accept(){		// To accept the details of user 
	try{
	cout << "Enter the Bank Account Id : ";
	cin >> accId;
	cout << "Enter the Account Holder : ";
	cin >> accHolder;
	cout << "Enter the Bank Balance: "; 
	cin >> balance;	if (balance<0) throw string("Balance cannot be negative!");}
	catch(string *m){cout << &m << endl;}
	}

	virtual void display(){ //To disply the details of user 
	cout << "Bank Account Id :" <<accId << endl;
	cout << "Account Holder : "<<accHolder << endl;
	cout << "Bank Balance: "<<balance<< endl;
	
	}
	
	virtual void calculateIntrest () = 0;	//Exception rule inside accept(): If balance < 0, throw an exception 
	


}; // Account class closed 


class savingsAccount : virtual public Account {
	private: 
		float interestRate;
	public:
		void calculateIntrest() override{ // overriden the virtual funtion of calculate intrest 
		balance = balance + (balance * interestRate /100);
		}

	void accept (){
		Account :: accept();
		try {
			cout << "Enter the Intrest Rate : ";
			cin >> interestRate;
			if (interestRate < 0) throw string("Intrest Rate cant be less than zero");
		}
		catch (string* m){
			std::cerr<< "ERROR : " << *m <<endl;		// catched the error ofintrest rate (if intrest rate < 0 )
		}
		
	}
	
	void display(){
		savingsAccount :: calculateIntrest();
		Account :: display();
		cout << "Intrest Rate : " << interestRate<< endl;
		cout << "\n";
	}



};


class CurrentAccount : virtual public Account {
	private:
		float serviceCharge;
	public :

	void calculateIntrest () override{
	balance = (balance - serviceCharge);
	}
	
	void accept (){
		Account :: accept();
		cout << "Enter the Service Charge : ";
		cin >> serviceCharge;	
	}
	void display(){
		CurrentAccount :: calculateIntrest();
		Account :: display();
		cout << "Service Charges : " << serviceCharge<< endl;
		cout << "\n";
	}

	
	
};
int main()
{
	int choise;
	savingsAccount s;
 	CurrentAccount c;
 	Account* ptr = new CurrentAccount;
	 ptr=&s;

	do{
	
	cout << "Menue:" <<endl;
	cout <<"1. Enter Savings Account Details:" <<endl;
	cout <<"2. Enter Current Account Details:" <<endl;
	cout <<"3. Display Savings Account using base-class pointer:" <<endl;
	cout <<"4. Display Current Account using base-class pointer:" <<endl;
	cout <<"5. Exit	:" <<endl;
	cin >> choise;
	
	switch(choise){
		case 1:
			ptr = new savingsAccount;
			cout <<"Enter Savings Account Details:" <<endl;
			ptr->accept();
			break;
		case 2:
			ptr = new CurrentAccount;
			cout <<"Enter Current Account Details:" <<endl;
			c.accept();
			break;
		
		case 3 : 
			cout <<"Saving Account Details: "<<endl;
			s.display();
			break;
		case 4:
			ptr->display();
			break;
		case 5 :
			delete ptr;
			ptr = nullptr;
			break;
			
		default:
			cout << "Invalid Choice!" <<endl;
			
			return 0;			
		}	


	}while(choise != 5 );



}
//fix the try catch throw 
// in main function use one upcasting and fix those issues 