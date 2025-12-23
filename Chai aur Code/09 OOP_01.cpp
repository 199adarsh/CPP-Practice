#include <iostream>
#include <vector>

using namespace std;

class chai {
private:
    int servings;
    string chaiName;
    vector<string> ingridients;

public:
    // Default constructor
    chai() {
        servings = 2;
        chaiName = "Lemon Tea";
        ingridients = {"Water", "Sugar", "Lemon"};
    }

    // Parameterized constructor (1)
    chai(int Servings)
        : servings(Servings), chaiName("Chaii"), ingridients({"Water", "Tea Leaves"}) {}

    // Parameterized constructor (2)
    chai(int Servings, string ChaiName, vector<string> Ingridients) {
        servings = Servings;
        chaiName = ChaiName;
        ingridients = Ingridients;
    }

    // Getter
    string getChai() {
        return chaiName;
    }

    // Setter
    void setChaiName(string name) {
        chaiName = name;
    }
};

int main() {
    chai c1;

    cout << c1.getChai() << endl;

    c1.setChaiName("Masala Chai");
    cout << c1.getChai() << endl;
}
