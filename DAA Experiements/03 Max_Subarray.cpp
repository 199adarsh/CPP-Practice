#include <bits/stdc++.h>
using namespace std;

int max_c(int arr[], int l , int m , int r){

    int sum = 0 , leftSum = -1000 , rightSum = -1000;

    for (int i = m ; i >= l ; i--){
        sum += arr[i];
        leftSum = max(leftSum,sum);
    }    

    sum = 0; 
    for (int i = m+1 ; i <= r ; i++){
        sum += arr[i];
        rightSum = max(rightSum,sum);
    }    

    return leftSum + rightSum ; 
}



int maxSub (int arr[], int l , int r){

    if(l == r) return arr[l];

    int m = (l+r)/2;

    int left = maxSub(arr,l,m);
    int right = maxSub(arr, m+1, r);
    int cross = max_c(arr,l,m,r);


    return max(max(left,right),cross);





}


int main()
{

    int arr[] =  {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSub(arr,0,8);
    
    return 0;
}