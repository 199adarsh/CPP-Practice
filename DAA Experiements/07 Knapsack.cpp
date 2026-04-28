#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> val = {60,100,120}, wt = {10,20,30};
    int n = val.size(), W = 50;

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++)
        for (int w = 1; w <= W; w++)
            dp[i][w] = (wt[i-1] <= w)
                ? max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w])
                : dp[i-1][w];

    cout << dp[n][W];
}