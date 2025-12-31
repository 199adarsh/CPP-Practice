#include <iostream>

using namespace std;

int main() {

    int m;
    cout << "Enter number of rows: ";
    cin >> m;

    double** arr2 = new double*[m];

    for (int i = 0; i < m; i++){
        int n;
        cout << "Enter number of columns for row " << i << ": ";
        cin >> n;

        arr2[i] = new double[n];
        for (int j = 0; j < n; j++){
            cout << "Enter the " << j << " Element of row " << i << ": ";
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++){
        delete[] arr2[i];
    }
    delete[] arr2;

    return 0;
}
/*  */