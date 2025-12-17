#include <iostream>

using namespace std;

double add (int num1 , int num2 ){
	cout << "Sub is :"<<num1 + num2 << endl;
	return 0;
}


double sub (int num1 , int num2 ){
	cout << "Sub is :"<<num1 - num2 << endl;
	return 0;
}


double division (int num1 , int num2 ){
	cout << "Division is :"<<num1 % num2 << endl;
	return 0;
}


double mul (int num1 , int num2 ){
	cout << "Multiplication is :"<<num1 * num2<< endl;
	return 0;
}


int main (){
	int num1 , num2, total, option ;

	cout << "Enter 1st number : "<< endl;
	cin>>num1;
	
	cout << "Enter 2nd number : "<< endl;
	cin>>num2;

	if (num2 == 0){
	cout << "2nd number cant be zero" << endl;

	}

	else {
	cout << "Which option you want ?\n 1. Add \n 2. Sub \n 3. Divide \n 4. Multiply \n" << endl;
	cin >> option;
	
	switch(option){

		case 1 : add(num1, num2); break;
		case 2 : sub(num1, num2); break;
		case 3 : division(num1, num2); break;
		case 4 : mul(num1, num2); break;
		default: cout << "Invalid option, Try again " << endl;
 			   break;
			}
}
    

return 0;


}