#include <iostream>
using namespace std;

int main() {
    int val[] = {20, 60, 70};
    int wt[]  = {2, 3, 4};

    int n = 3;
    int W = 5;

    int dp[10][10] = {0};

    for (int i = 1; i <= n; i++) {
        for (int cap = 0; cap <= W; cap++) {

            if (wt[i - 1] <= cap)
                dp[i][cap]=max( dp[i - 1][cap],  val[i - 1] + dp[i - 1][cap - wt[i - 1]]);

            else
                dp[i][cap] = dp[i - 1][cap];
        }
    }

    cout << dp[n][W];
}