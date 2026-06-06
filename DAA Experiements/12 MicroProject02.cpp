#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> beds, vector<int> priority, int totalBeds) {
    int n = beds.size();
    vector<vector<int>> dp(n + 1, vector<int>(totalBeds + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= totalBeds; j++) {

            int notTake = dp[i - 1][j];
            int take = 0;

            if (beds[i - 1] <= j) {
                take = priority[i - 1] + dp[i - 1][j - beds[i - 1]];
            }

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n][totalBeds];
}

int main() {
    vector<int> beds = {1, 2, 3, 4};        
    vector<int> priority = {10, 15, 40, 15};
    int totalBeds = 5;

    cout << "Hospital Bed Allocation\n";

    for(int i = 0; i < beds.size(); i++){
        cout << "Patient " << i+1 
             << ": Beds=" << beds[i] 
             << ", Priority=" << priority[i] << endl;
    }

    int result = knapsack(beds, priority, totalBeds);

    cout << "\nTotal Beds Available: " << totalBeds << endl;
    cout << "Maximum Priority Allocated: " << result << endl;

    return 0;
}