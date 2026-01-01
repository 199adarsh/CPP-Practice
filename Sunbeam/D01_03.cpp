
    #include <iostream>
	#include <iomanip>

    using namespace std;


	double calculation(double units, double total){

	double tcharges = units*1.47;
	double echarges = (total * 0.1950);

	double alltotal = 130 + tcharges + echarges+ total;
	return alltotal ;

	}

    int main() {
    	double units , total  ;
		int ec = 130;

	cout << "Enter units used"<< endl;
	cin >> units;

	if (units < 100) {
	total = units*4.28; 
	cout<< "Your bill of units is : " << total << endl;
	}

	else if (units <= 101) {
	total = units*11.1; 
	cout<< "Your bill of units is : " << total << endl;
	}

	else if ( units <= 301) {
	total = units*15.38; 
	cout<< "Your bill of units is : " << total << endl;
	}

	else if (units <= 501) {
	total = units*17.68; 
	cout<< "Your bill of units is : " << total << endl;
	}

	else if (units <= 1001) {

	total = units*19.50;
	cout<< "Your bill of units is : " << total << endl;
	}


	
	cout << setw(35) << setfill('.') << left << "Total units consumed :" << right << setw(10) << units << endl;
	cout << setw(35) << setfill('.') << left << "Electricity consumption charges :" << right << setw(10) << ec << endl;
	cout << setw(35) << setfill('.') << left << "Electricity transmission charges :" << right << setw(10) << (units * 1.47) << endl;
	cout << setw(35) << setfill('.') << left << "Your total bill of units is :" << right << setw(10) << alltotal << endl;
    
	return 0;
    }

