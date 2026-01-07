#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> addressBook;
    string name, address;

    for (int i = 1; i <= 5; i++) {
        cout<<"Name: "<<endl; getline(cin,name);
        cout<<"Address: "<<endl; getline(cin, address);
        addressBook[name] = address;
    }

    cout<<"Address Book "<<endl;

    for (auto &entry : addressBook) {
        cout<<"Name: "<<entry.first<<endl;
        cout<<"Address: "<<entry.second<<endl;
    }

    cout<<"Enter name to delete: "<<endl;
    cin>>name;

    if (addressBook.erase(name))
        cout<<"Entry deleted!"<<endl;
    else
        cout<<"Name not found!"<<endl;

    cout<<"Address Book After Deletion "<<endl;
    
    for (auto &entry : addressBook) {
        cout<<"Name: "<<entry.first<<endl;
        cout<<"Address: "<<entry.second<<endl;
    }

    return 0;
}