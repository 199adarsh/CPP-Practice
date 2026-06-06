#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {10, 2, 33, 50, 60, 80};
    int size = a.size(), ans = 1;

    vector<int> dp(size, 1);

    for (int i = 1; i < size; i++)
        for (int j = 0; j < i; j++)
               
                if (a[i] > a[j])
                    dp[i] = max(dp[i], dp[j] + 1);
                    

    for (int x : dp)
        ans = max(ans, x);

    cout << "LIS = " << ans;
}