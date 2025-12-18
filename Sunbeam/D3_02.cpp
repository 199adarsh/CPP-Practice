#include <iostream>
#include <cmath>
using namespace std;

int main() {

    
    double amount = 6000;
    double profit_a = 1000;
    double profitA_final = 2000;
    double returnRate = 0.12; // 12% per year
    
    
    
    cout << "Investment Comparison:\n";
    cout << "Investment A: 6000 rs, 1000 rs/year + 2000 rs after n years\n";
    cout << "Investment B: 6000 rs with 12% annual return\n\n";
    
    // Find years where Investment B profit exceeds Investment A profit
    for (int years = 0; years <= 50; years++) {
        double profitA = (profit_a * years) + profitA_final;
        double amountB = amount * pow(1 + returnRate, years);
        double profitB = amountB - amount;
        
        cout << "Year " << years << ": Profit A = " << profitA 
             << " rs, Profit B = " << profitB << " rs\n";
        
        if (profitB > profitA) {
            cout << "\nInvestment B crosses Investment A's profit in year " << years << "\n";
            break;
        }
    }
    
    return 0;
}