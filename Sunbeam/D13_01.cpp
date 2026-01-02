#include <iostream>
#include <string>
using namespace std;



class Artist {
    private : 
        string name;
        int rating;
        string country;

    public : 
	void acceptData(){
		cout << "Enter the name of Artist : " ;
		cin >> name;
		cout << "Enter the Rating of Artist : " ;
		cin >> rating;
		cout << "Enter the Country of Artist : " ;
		cin >>country;
	}

	void displayArtistData(){
		cout << "Name of Artist : " << name << endl;
		cout << "Rating of Artist : " << rating << endl;
		cout << "Country of Artist : " << country << endl;
	}
	
	virtual float calculateTotalIncome()= 0;
    bool isFamus(){
        cout << ((rating >=2) ? "Artist is not Famus !" : (rating <2) ? "Artist is Famus " : " " ) << endl;
        return true ; 
    }
    
};

class painter : public Artist {

    private : 
        string type;
        float paintingRate;
        int paintings;

    public : 
	void acceptPainterData(){
        Artist::acceptData();
		cout << "Enter the type of painting (Decorative / Commercial) : " ;
		cin >> type;
		cout << "Enter the Rate of Painting: " ;
		cin >> paintingRate;
		cout << "Enter the no of Paintings : " ;
		cin >> paintings;
	}

	void displayPainterData(){
        Artist::displayArtistData();
		cout << "Type of Paintings : " << type << endl;
		cout << "Rate of Painting : " << paintingRate << endl;
		cout << "No of Paintings : " << paintings<< endl;
        cout << "Total Income of Painter : "<<calculateTotalIncome();
	}
	
	virtual float calculateTotalIncome()override{
        return (paintingRate*paintings);

    } ;

    
};

class singer : public Artist {

    private : 
        string type;
        float albumsRate;
        int albums;

    public : 
	void acceptsingerData(){
		Artist::acceptData();
		cout << "Enter the Rate of Albums : " ;
		cin >> albumsRate;
		cout << "Enter the no of albums : " ;
		cin >> albums;
	}

	void displaysingerData(){
        Artist::displayArtistData();
		cout << "Rate of Albums : " << albumsRate << endl;
		cout << "No of albums : " << albums<< endl;
        cout << "Total Income of singer : "<<calculateTotalIncome();
	}
	
	virtual float calculateTotalIncome()override{
        return (albumsRate*albums);

    } ;

    
};

int main(){

    singer s1;
    painter p1;
    int choice;

    do{
        cout << "\n";
        cout << "\n1. Accept Singer Details";
        cout << "\n2. Display Singer Details";
        cout << "\n3. Accept Painter Details";
        cout << "\n4. Display Painter Details";
        cout << "\n0. Exit";
        cout << "\nEnter choice : ";
        cin >> choice;
        cout << "\n";

        switch(choice)
        {
            case 1:
                s1.acceptsingerData();
                break;

            case 2:
                cout << "\nSinger Details \n";
                s1.displaysingerData();
                break;

            case 3:
            {
               
                p1.acceptPainterData();
                break;
            }
            case 4:
            {
               
                p1.displayPainterData();
                break;
            }

            case 0:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    }while(choice != 0);

    return 0;
}


