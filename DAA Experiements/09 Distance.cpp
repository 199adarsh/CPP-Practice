#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "DOG", b = "DIG";

    int m = a.size(), n = b.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
                
            else
                dp[i][j] = 1 + min({
                                    dp[i][j - 1],     // insert
                                    dp[i - 1][j],     // delete
                                    dp[i - 1][j - 1]  // replace
                });
        }
    }

    cout << dp[m][n];
}