#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int value) {
        this->value = value;
    }

    Counter* increment() {
        value++;
        return this;  // return current object
    }

    void show() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Counter c(10);

    c.increment()->increment()->increment(); // method chaining
    c.show();

    return 0;
}

    // without using this ptr overall values will change 
    // if we use this ptr only the objects value will change
