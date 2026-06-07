#include <iostream>
#include <vector>
using namespace std;

int main() {
   int a [] = {10,2,15,60,75,82,22};
   int n = 7;


   vector<int> dp(n,1);

    for (int i =0; i<n; i++){
         for (int j =0; j<i; j++){
          
            if(a[i]>a[j])
                dp[i]= max(dp[i],dp[j]+1);
        }
    }

    int ans = 0;
    for(int x : dp){ ans = max(dp[x], ans);}

    cout << ans;


}


