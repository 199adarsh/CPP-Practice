
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal sound";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Bark";
    }
};


int main()
{
    Animal* a = new Dog();
    a->speak(); 

    Dog d ;
    d.speak();
    return 0;
}

 