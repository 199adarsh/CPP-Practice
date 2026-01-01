#include <iostream>
#include <cmath>

using namespace std;

double formula (double principle , double rate, double compound, double years){
	double total = principle * pow(1+ rate / (100 * compound ), years * compound );
	return total;
}

int main (){
	double principle, rate, compound, years;

	cout << "Enter Principle : "<< endl;
	cin >> principle;
	
	cout << "Enter Rate : "<< endl;			
	cin >> rate;

	cout << "Enter rate of compounding in years : "<< endl;
	cin >> compound;
	
	cout << "Enter Years : "<< endl;
	cin >> years;

	for (int i = 1; i <= 10; i++){
		double total = formula(principle, rate, compound, i);
		cout << "Year " << i << ": Your calculated value is: " << total << endl;
	}

	return 0;
}
