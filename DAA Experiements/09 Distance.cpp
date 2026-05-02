#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    string a = "DOG";
    string b = "DIG";

    int m = a.size();
    int n = b.size();

    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i; // delete all characters
    for (int j = 0; j <= n; j++) dp[0][j] = j; // insert all characters

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            // If characters match → no operation needed
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            else {
                int insertOp  = dp[i][j - 1];
                int deleteOp  = dp[i - 1][j];
                int replaceOp = dp[i - 1][j - 1];

                dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
            }
        }
    }

    cout << dp[m][n];
}