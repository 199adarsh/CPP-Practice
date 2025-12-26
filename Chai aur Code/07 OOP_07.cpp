#include <iostream>
using namespace std;

class Animal {
public:
    int age;   // this is the object's own age

    // this function sets the object's age
    void setAge(int age) {

        // 🤯 two things named "age"
        // left side  -> object's age
        // right side -> function's age (the one we received)

        // 🫏 listen, donkey:
        // "this->age" means: the age that belongs to THIS object
        // "age" (right side) means: the value that came from outside
        this->age = age;  

        // so we are saying:
        // put outside-age INTO this-object's-age
        // (cup gets sugar, simple!)
    }

    void show() {
        // print the object's age
        cout << "Age is: " << age << endl;
    }
};

int main() {

    Animal a;        // create one animal (one object)
    a.setAge(5);     // give age = 5 using the function
    a.show();        // should print: Age is: 5

    return 0;
}
