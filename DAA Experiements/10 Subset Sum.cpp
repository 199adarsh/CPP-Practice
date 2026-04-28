#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a, int i, int sum, int target, vector<int>& cur) {
    if (sum == target) {
        for (int x : cur) cout << x << " ";
        cout << "\n";
        return;
    }
    if (i == a.size() || sum > target) return;

    cur.push_back(a[i]);
    solve(a, i+1, sum + a[i], target, cur);
    cur.pop_back();

    solve(a, i+1, sum, target, cur);
}

int main() {
    vector<int> a = {1,2,5,6,8}, cur;
    solve(a, 0, 0, 9, cur);
}