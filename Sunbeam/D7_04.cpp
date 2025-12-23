#include <iostream>
using namespace std;
inline bool is_even(int num){

    if (num % 2==0){
        return true;
    }
    else {
        return false;
    }
}
int main()
{

    int num ;
    cout <<"Enter number";
    cin >> num;
    if (is_even(num)){
        cout <<"The number is Even";
    
    }
    else {
        cout <<"The number is odd";
    }
    return 0;
}