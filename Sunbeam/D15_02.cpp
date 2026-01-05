#include <iostream>
#include <string>
using namespace std;

class Bank {
    private :   
        int accNo;
        double balance;
        double value;
    public: 
        void accountCreation(){
            cout << "Enter the account no : " ;
            cin >>accNo;
            cout << "Enter the initial money to deposit : ";
            cin >> balance;
            if (balance < 2000) throw string ("Initial balance cant be less than 2000");

            cout << "Account Created with Account No : " << accNo << " Balance : " << balance << endl;
        }

        void deposit (){

            cout << "Enter the money to deposit : ";
            cin >> value;
            if (value <= 0) throw string ("Deposit cant be less than 0 ");
            else balance += value;
            cout << "Money deposited to Account No : " << accNo << " Balance : " << balance << endl;
        }

        void withdraw (){

            cout << "Enter the money to Withdraw : ";
            cin >> value;
            if (value > (balance-2000)) throw string ("Please maintain Min Balance of 2000");
            else balance -= value;
            cout << "Money Withdrawn from Account No : " << accNo << " Balance : " << balance << endl;
        }

};

class BankingEx {
    public :
        Bank b1;
        int choice;

    void createAcc(){
        try{
            b1.accountCreation();
        }

        catch(string &e){
            cout  << e << '\n';
        }
    }   
    int DepoWithdraw(){   
        try
        {
            while(choice != 3){
            cout << "\nMenue :" << endl;
            cout << "1. deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Exit " << endl;
            cin >> choice;
                switch(choice){

                    case 1 :
                        b1.deposit();
                        break;
                    case 2 :
                        b1.withdraw();
                        break;
                    case 3 :
                        cout << "Exited the Program";
                        return 0 ;
                    default :
                        cout << "Invalid Choice !"<< endl;                
                }
            }
        }
        
        catch(string &e){
            cout  << e << '\n';
            
        }
    return 1;        
    }

     
};

int main()
{
    BankingEx b2;
    b2.createAcc();
    b2.DepoWithdraw();
   
    
    return 0;
}
