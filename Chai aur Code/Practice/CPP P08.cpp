#include <iostream>
#include <string>
using namespace std;

class Animal{
        string name;
    
    public: 
        virtual void speak()= 0; //Pure virtual function
        
        
        virtual ~ Animal(){
            cout << "Animal : V Destructor " << endl ;
        }

};


class Dog :  public Animal {

    public : 
        void speak () override{     // funtion overriding
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

        cout << "Cat : Destructor " <<endl;     // Virtual destructor
    }
};

int main()
{

    Animal * d = new Dog ();
    Animal * c = new Cat();

    d->speak();
    c->speak();

    Animal * a = d;      // Upcasting       

    Dog * newDog = dynamic_cast<Dog*> (d);   // DownCasting 

    delete d;
    delete c;

    
    return 0;
}

