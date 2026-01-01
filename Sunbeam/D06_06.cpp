#include <iostream>

using namespace std;

bool Password(const string& password) {
    bool Upper = false, Lower = false;
    bool Digit = false, Special = false;

    for (char ch : password) {
        if (ch >= 'A' && ch <= 'Z')
            Upper = true;
        else if (ch >= 'a' && ch <= 'z')
            Lower = true;
        else if (ch >= '0' && ch <= '9')
            Digit = true;
        else
            Special = true;
    }

    return Upper && Lower && Digit && Special;
}

int main() {
    string password;
    cout << "Enter a password to check if it is valid / invalid :" ;
    cin >> password;

    if (Password(password))
        cout << "Your Password is a Valid password";
    else
        cout << "Your Password is a Invalid password";

    return 0;
}
