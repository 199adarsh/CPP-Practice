#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> val = {20, 20, 50};
    vector<int> wt  = {2, 3, 4};

    int n = val.size();
    int W = 5;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int cap = 0; cap <= W; cap++) {

            if (wt[i - 1] <= cap)
                                dp[i][cap] = max(   dp[i - 1][cap],
                                                    val[i - 1] + dp[i - 1][cap - wt[i - 1]]);
                                            
            else
                dp[i][cap] = dp[i - 1][cap];
            
            
        }
    }

    cout << dp[n][W];
}