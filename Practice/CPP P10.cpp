#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class person {};

int main()
{
    person p1;

    cout << typeid(p1).name() << endl;

    return 0;
}
