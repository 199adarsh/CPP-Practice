#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> addressBook;
    string name, address;

    cout<<"Enter 5 names and addresses: "<<endl;
    for (int i = 1; i <= 5; i++) {
        cout <<"BOOK : "<<i<<endl;
        cout<<"Name: "; getline(cin, name);
        cout<<"Address: "; getline(cin, address);
        addressBook[name] = address;
        cout <<"\n";
    }



    cout<<"\nDisplay Address Book: "<<endl;
    for (const auto &book : addressBook) {
        cout<<"Name: "<<book.first<<endl;
        cout<<"Address: "<<book.second<<endl;
        cout <<"\n";
    }




    cout<<"\nEnter name to delete: "<<endl;
    cin>>name;

    if (addressBook.erase(name) == 1)
        cout<<"Book deleted!"<<endl;
    else
        cout<<"Name not found!"<<endl;



    cout<<"Address Book After Deletion: "<<endl;
    for (const auto &book : addressBook) {
        
        cout<<"Name: "<<book.first<<endl;
        cout<<"Address: "<<book.second<<endl;
        cout <<"\n";
    }

    return 0;
}
