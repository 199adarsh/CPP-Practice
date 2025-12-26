#include<iostream>
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

int main (){
    Animal a1;
    Dog d1;
    d1.speak();
    a1.speak();   

    return 0;
}