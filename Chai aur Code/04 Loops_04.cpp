#include <iostream>
#include <string>

using namespace std;

int main()
{

    string tea[] = {"Lemon Tea", "Green Tea", "Black Tea", "Orange Tea", "Oolong Tea"};

    for (int i = 0; i < 5; i++)
    {

        if (tea[i] == "Black Tea")
            continue;

        for (int j = 0; j < 3; j++)
        {
            cout << "Serving " << tea[i] << endl;
        }
        cout << "Served all 3" << tea[i] << "\n"
             << endl;
    }

    return 0;
}
