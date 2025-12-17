#include <iostream>

using namespace std;

double value (int num1 , int num2 ){

	cout << "\nBy Value \n "<< endl;
	cout << "1st Number is:" << num1<< endl;
	cout<< "2nd Number is :" << num2 << endl;

	cout << "\nSwapped Numbers by value :"<< endl;
	int temp = num1;

	num1 = num2;
	num2 = temp;

	cout << "1st Number is:" << num1<< endl;
	cout<< "2nd Number is :" << num2 << endl;
	return 0;
}

double add (int *num1 , int * num2 ){
	
	cout << "\nBy Address :\n" << endl;
	cout << "1st Number is:" << *num1<< endl;
	cout<< "2nd Number is :" << *num2 << endl;
 
	cout << "\nSwapped Numbers by address :"<< endl;
	int temp = *num1;

	*num1 = *num2;
	*num2 = temp;

	cout << "1st Number is:" << *num1<< endl;
	cout<< "2nd Number is :" << *num2 << endl;
	return 0;
}

int main (){
	int num1 , num2 ;

	cout << "Enter 1st number : "<< endl;
	cin>>num1;
	
	cout << "Enter 2nd number : "<< endl;
	cin>>num2;

	add(&num1, &num2);
	value(num1 , num2);
	
	return 0;
}
