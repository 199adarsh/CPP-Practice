#include <iostream>
#include <string>
using namespace std;

// ===================== BASE CLASS =====================

class Account
{
protected:
    int accId;
    string accHolder;
    float balance;

public:
    // Default Constructor
    Account()
    {
        accId = 0;
        accHolder = "";
        balance = 0;
    }

    // Parameterized Constructor
    Account(int id, string holder, float bal)
    {
        accId = id;
        accHolder = holder;
        balance = bal;
    }

    // Virtual Destructor
    virtual ~Account() {}

    // Virtual Accept
    virtual void accept()
    {
        try
        {
            cout << "Enter Account ID: ";
            cin >> accId;

            cout << "Enter Account Holder Name: ";
            cin >> accHolder;

            cout << "Enter Balance: ";
            cin >> balance;

            if (balance < 0)
                throw "Exception: Balance cannot be negative!";
        }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
    }

    // Virtual Display
    virtual void display()
    {
        cout << "Account ID      : " << accId << endl;
        cout << "Account Holder : " << accHolder << endl;
        cout << "Balance        : " << balance << endl;
    }

    // Pure Virtual Function
    virtual void calculateInterest() = 0;
};

// ===================== SAVINGS ACCOUNT =====================

class SavingsAccount : public Account
{
private:
    float interestRate;

public:
    void accept() override
    {
        Account::accept();

        try
        {
            cout << "Enter Interest Rate: ";
            cin >> interestRate;

            if (interestRate < 0)
                throw "Exception: Interest rate cannot be negative!";
        }
        catch (const char* msg)
        {
            cout << msg << endl;
        }
    }

    void calculateInterest() override
    {
        balance = balance + (balance * interestRate / 100);
    }

    void display() override
    {
        calculateInterest();
        Account::display();
        cout << "Interest Rate  : " << interestRate << endl;
    }
};

// ===================== CURRENT ACCOUNT =====================

class CurrentAccount : public Account
{
private:
    float serviceCharge;

public:
    void accept() override
    {
        Account::accept();
        cout << "Enter Service Charge: ";
        cin >> serviceCharge;
    }

    void calculateInterest() override
    {
        balance = balance - serviceCharge;
    }

    void display() override
    {
        calculateInterest();
        Account::display();
        cout << "Service Charge : " << serviceCharge << endl;
    }
};

// ===================== MAIN =====================

int main()
{
    int choice;
    SavingsAccount s;
    CurrentAccount c;

    Account* ptr = NULL;   // Upcasting

    do
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Enter Savings Account Details" << endl;
        cout << "2. Enter Current Account Details" << endl;
        cout << "3. Display Savings Account" << endl;
        cout << "4. Display Current Account" << endl;
        cout << "5. Exit" << endl;
        cout << "--------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ptr = &s;
            ptr->accept();
            break;

        case 2:
            ptr = &c;
            ptr->accept();
            break;

        case 3:
            ptr = &s;
            ptr->display();
            break;

        case 4:
            ptr = &c;
            ptr->display();
            break;

        case 5:
            cout << "Exiting Program..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
