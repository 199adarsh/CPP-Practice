#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> value = {1,2,5,6};
    vector<int> weight = {2,3,4,5};
    int n = 4;
    int maxWeight = 8;

    
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxWeight; j++) {

            // option 1: don't take the item
            int notTake = dp[i - 1][j];

            // option 2: take the item (only if possible)
            int take = 0;
            if (weight[i - 1] <= j) {
                take = value[i - 1] + dp[i - 1][j - weight[i - 1]];
            }

            dp[i][j] = max(take, notTake);
        }
    }

    cout << dp[n][maxWeight];
}