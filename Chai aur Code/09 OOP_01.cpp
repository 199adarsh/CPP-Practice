#include <iostream>
#include <vector>

using  namespace std ;

class chai{
private:
    int servings;
    string chaiName;
    vector<string> ingridients;

public:
    chai(){     // constructor
    servings = 2;
    chaiName = "Lemon Tea";
    ingridients = {"Water ", "Sugar" , "Lemon "};

    }

    chai(int Servings):(servings, "Chaii",{"water", "tea leves"}){}
    //Parametarized constructor
    chai(int Servings ,string ChaiName,vector<string> Ingridients){
        Servings = servings;
        ChaiName = chaiName;
        Ingridients = ingridients;

    
    }
    // getter 
    string getChai() {
        return chaiName;
    }

    //setter 
    void setChaiName(string name){
        chaiName = name;

    }
    

};


int main(){

    chai c1;
    string serv = c1.getChai(); // gets the value of chaiName
    cout << serv;

    c1.setChaiName("Masala Chai"); // sets the new value to chaiName 
    string serv1 = c1.getChai();
    cout << serv1;
}