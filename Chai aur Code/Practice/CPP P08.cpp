#include <iostream>
#include <string>
using namespace std;

class Animal{
        string name;
    
    public: 
        virtual void speak()= 0;
        
        
        virtual ~ Animal(){
            cout << "Animal : V Destructor " ;
        }

};


class Dog :  public Animal {

    public : 
        void speak () override{
            cout << "Bhaww Bhaww" << endl;
        }

    ~Dog (){
        cout << "Dog : Destructor " << endl;
    }
};

class Cat : public Animal{

    public :
        void speak() override {
            cout << "Meow Meoww ! " << endl;
        }
    ~Cat(){

        cout << "Cat : Destructor " <<endl;
    }
};

int main()
{

    Animal * d = new Dog ();
    Animal * c = new Cat();

    d->speak();
    c->speak();

    Animal * a = d;

    Dog * newDog = dynamic_cast<Dog*> (d); 

    delete d;
    delete c;

    
    return 0;
}