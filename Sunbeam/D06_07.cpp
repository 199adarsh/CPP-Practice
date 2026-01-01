#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[] = {"flower", "flow", "flight"};
    int n = 3;
    
    string prefix = "";

    for (int i = 0; i < arr[0].length(); i++) {
        char c = arr[0][i];

        for (int j = 1; j < n; j++) {
            if (arr[j][i] != c) {
                cout << prefix;
                return 0;
            }
        }
        prefix += c;
    }

    //cout << prefix 
    return 0;
}
