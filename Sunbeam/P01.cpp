#include <iostream>

using namespace std;

int main (){

    int number ;
 

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {
    "M", "CM", "D", "CD", "C", "XC",
    "L", "XL", "X", "IX", "V", "IV", "I"
        };

    cout << "Enter a number to convert to romen :" << endl;
    cin >> number;
	
	while(number > 0){

		for (int i =0; i <13 ; i++){
			if (number >= values[i]) {
                number -= values[i];
                cout << symbols[i];
                break;   
            }
		}

	}


}