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
	cout << "\n";
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
		float serviceCharge

	
}

int main()
{



}