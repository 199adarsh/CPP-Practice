#include<iostream>

using namespace std;

int main(){
    int arr[] = {1,2,2,3,3,4,5};
    int count = 0;

    for (int i = 0; i <=6; i++){

        if (arr[i]==arr[i+1]){ count ++;}
    }

    cout << count ;
}