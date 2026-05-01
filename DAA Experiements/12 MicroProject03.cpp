//Matrix Chain Multiplication (MCM)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mcm(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int len = 2; len < n; len++){
        for(int i = 1; i < n - len + 1; i++){
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k+1][j]
                         + arr[i-1]*arr[k]*arr[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    cout << mcm(arr);
}