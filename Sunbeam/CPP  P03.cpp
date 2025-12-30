#include <iostream>
using namespace std;

int main()
{
    int length = 1189;
    int width  = 841;

    for (int i = 0; i <= 8; i++) {
        cout << "Size of A" << i << ": "
             << length << " mm x " << width << " mm" << endl;

        
        int temp = length;
        length = width;
        width = temp / 2;
    }

    return 0;
}
