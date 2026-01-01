#include <bits/stdc++.h>
using namespace std;

int main() {
    double investment = 6000.0;
    double annualIncome = 1000.0;
    double salvage = 2000.0;
    double rate = 0.12;

    cout<<fixed<<setprecision(2);
    for (int n = 1; n <= 100; ++n) {
        // Present value of an n-year annuity
        double pv_annuity = annualIncome * (1.0 - pow(1.0 + rate, -n)) / rate;
        // Present value of salvage at end of n years
        double pv_salvage = salvage * pow(1.0 + rate, -n);
        double npv = -investment + pv_annuity + pv_salvage;

        cout << "Year " << setw(2) << n << " : NPV = Rs. " << setw(10) << npv << '\n';

        if (npv >= 0.0) {
            cout << "\nMinimum years a needs to cross profit of a   = "
                 << n << " years\n";
            cout << "NPV(" << n << ") = Rs. " << npv << '\n';
            break;
        }

        if (n == 100) {
            cout << "\nNo breakeven within 100 years.\n";
        }
    }

    return 0;
}
