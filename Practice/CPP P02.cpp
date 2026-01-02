#include <iostream>
using namespace std;

int main()
{
    int rows= 5;
    int num = 1;

    for (int cols = 1; cols <= rows; cols++) {


        for (int j = 0; j < rows- cols; j++)
            cout << " ";

        for (int k = 1; k <= cols; k++) {
            cout << num<< " ";
            num++;
            if (num == 10) num = 0; 
        }

        cout << endl;
    }
    return 0;
}
