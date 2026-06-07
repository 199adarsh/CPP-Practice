#include <iostream>
using namespace std;

int a[] = {1,2,5,6,8};
int idx[5];

void subset(int i,int sum, int k){
 
    if (sum == 9) {
        cout<<"\nFound at Index :";
        for (int j = 0; j < k; j++) cout << idx[j] ;
    
        }
    

    if (i>=5 || sum >=9) return;

    idx[k]=i;
    subset(i+1,sum+a[i],k+1);
    subset(i+1,sum,k);
    



}


int main() {
    subset(0, 0, 0);
}