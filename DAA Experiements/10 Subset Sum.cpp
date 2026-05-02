#include <iostream>
using namespace std;

int set[] = {1,2,5,6,8}, sub[10], n=5, target=9;

bool subSet(int i, int sum, int k){

    if(sum==target){

        for(int j=0; j<k; j++) cout<<sub[j]<<" ";
        return true;
    }
    for(; i<n; i++){
        if(sum + set[i] <= target){
            sub[k] = set[i];

            if(subSet(i+1, sum+set[i], k+1)) 
            return true;
        }
    }
    return false;
}

int main(){ subSet(0,0,0); }