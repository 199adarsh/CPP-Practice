#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 2, 33, 50, 60, 80};
    int n = arr.size();

    vector<int> dp(n, 1);

    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << "Length of LIS = " << ans;

    return 0;
}