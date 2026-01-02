#include<iostream>

using namespace std; 

int main() {
    int a, b;
    cin >> a >> b;

    try {
        if (b == 0)
            throw "Division by zero error!";
        
        cout << a / b;
    }
    catch (const char* msg) {
        cout << "Error: " << msg;
    }

    cout << "\nProgram continues...";
}