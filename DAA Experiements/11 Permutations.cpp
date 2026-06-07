#include <bits/stdc++.h>
using namespace std;

void permute(string &s, int l=0){

    if (l==s.size()){
        cout << s <<"\n";
    }

    for (int i = l ; i < s.size(); i++){
        swap(s[l],s[i]);
        permute(s,l+1);
        swap(s[l],s[i]);
    }


}

int main() {
    string s = "ABC";
    permute(s);
}