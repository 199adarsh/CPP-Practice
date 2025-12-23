#include <iostream>
using namespace std;


string pallin(string s){
    string rev="";
        for (int i = s.length() - 1; i >= 0; i--) {
        rev += s[i];
    }

    if (s == rev)
        cout << "The given word is a Palindrome";
    else
        cout << "The given word is Not Palindrome";
    return s ;
}
int main() {
    string s, rev = "";
    cout <<"Enter a word to check if it is pallindrome :"<< endl;
    cin >> s;
    pallin(s);
    

    return 0;
}
