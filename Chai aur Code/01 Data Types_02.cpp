#include <iostream>
using namespace std;

int main() {
    float basePrice;
    cout << "Enter the base price of tea: ";
    cin >> basePrice;

    // Increase by 10%0
    float increasedPrice = basePrice * 1.10;

    // Explicit type casting to int (rounding)
    int roundedPrice = (int) (increasedPrice + 0.5); // manual rounding

    cout << "Original Price: " << basePrice << endl;
    cout << "Price after 10% increase (float): " << increasedPrice << endl;
    cout << "Rounded New Price (int using casting): " << roundedPrice << endl;

    return 0;
    
}
