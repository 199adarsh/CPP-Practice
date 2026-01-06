#include <iostream>
#include <string>
using namespace std;

template <typename T>

class Price {

    private :
        T value ;
        T percent ;
    
    public :
        T setPrice (T val) {
            value = val;
            return 0;
        }

        T addGST(T GST){
            percent = GST;
            return 0;

        }


        T showFinalPrice(){
            cout << "The final price is :" << value+(value*(percent/100)) << endl;
            return 0;
        }



};



int main()
{

    Price <float> p1;
    p1.setPrice(3000.15);
    p1.addGST(5.00);

    Price <double> p2;
    p2.setPrice(2500.12);
    p2.addGST(18.00);


    p1.showFinalPrice();
    p2.showFinalPrice();
    
    return 0;
}