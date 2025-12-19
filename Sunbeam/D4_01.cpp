#include <iostream>
#include<iomanip>
#include <string>

using namespace std;

double gross(double adult_tp , double child_tp, double at_sold , double ct_sold){
	int total = (adult_tp * at_sold) + ( child_tp * ct_sold );

	return total ;
}



int main (){

	string name  ;
	double adult_tp , child_tp, at_sold , ct_sold , gross_amount , percentage , net_profit;

	cout << "Enter name of movie : "<< endl;
	cin>> name;
	
	cout << "Enter Child tickit price : "<< endl;
	cin>> child_tp;

	cout << "Enter Adult tickit price : "<< endl;
	cin>> adult_tp;

	cout << "Enter Child tickit sold : "<< endl;
	cin>> ct_sold;

	cout << "Enter Adult tickit sold: "<< endl;
	cin>> at_sold;

	cout << "Enter Percentage: "<< endl;
	cin>> percentage;


    	double g_amount =  gross(adult_tp , at_sold ,child_tp  , ct_sold);
	
	double dpercentage = (percentage / 100)* (g_amount);
	net_profit = g_amount - dpercentage; 

	

	cout << "Movie Name :" << setw(30) << setfill('.') << name << endl;
	cout << "Number of Tickets sold :" << setw(18) << setfill('.') << (at_sold + ct_sold) << endl;
	cout << "Gross amount :" << setw(28) << setfill('.')  << g_amount << endl;
	cout << "Percentage of gross amount donated :" << setw(6) << setfill('.') << percentage << "%" << endl;
	cout << "Amount donated :" << setw(26) << setfill('.')  << dpercentage << endl;
	cout << "Net sale :" << setw(32) << setfill('.')  << net_profit << endl;
	return 0;


}