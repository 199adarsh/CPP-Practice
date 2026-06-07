#include <bits/stdc++.h>
using namespace std;

void perm(string &s, int l = 0) {
    if (l == s.size()) {
        cout << s << '\n';
        return;
    }

    for (int i = l; i < s.size(); i++) {
        swap(s[l], s[i]);
        perm(s, l + 1);
        swap(s[l], s[i]);
    }
}

int main() {
    string s = "ABC";
    perm(s);
}