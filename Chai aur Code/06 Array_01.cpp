#include <iostream>
#include <string>
    using namespace std;

    int main (){

        string array[] = {"Leamon Tea", "Black Tea" , "Orange Tea" , "Green Tea"}; 

        for(string arrayy : array) // this iterates all the arrays of string from 0th index to last index it is easier than normal meathod
        {
            cout<< arrayy <<endl; 
        }

    return 0;

}