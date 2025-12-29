#include <iostream>
#include <string>
using namespace std;

int main()
{
int x = 10;

int* p = &x;     // pointer to int
int** pp = &p;

    cout <<" int *ptr = &x : " << *p<<endl;
    cout <<"int **ptr =&ptr :" << &(**pp) << endl;
    return 0;
}
