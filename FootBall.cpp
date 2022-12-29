#include <iostream>
#include "GamesGeneral.cpp"
#include<set>
using namespace std;

class FootBall : public GamesGeneral {

private:
    string ground;
    string TypeOfGame;
public:
    set<int > Time_TableGrass = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
    set<int > Time_TableConcreat = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
    set<int > Time_TableSand = {1, 2, 3, 4, 5, 6, 7, 8, 9 };

public:



    void run(){
        category = "FootBall";
        cout << "Welcome to FootBall Court" << endl;
        typeOfGround();
        typeOfGames();
        setNumberOfPlayers();
        getTimeTable();
        ReservationSubmit();

    }


    void typeOfGround() {
        int num;
        bool flage = false;
        while (!flage) {
            cout << "we have different types of grounds \n choose ground that you want \n 1.grass \n 2.concrete \n 3.sand" << endl;
            cout << "********************************" << endl;
            cout << "one hour in grass = 200 L.E \n one hour in concrete = 150 L.E \n one hour in sand = 100 L.E" << endl;
            cout << "***********************************" << endl;
            cin >> num;
            if (num == 1) {
                ground = "grass";
                flage = true;
            }
            else if (num == 2) {
                ground = "concrete";
                flage = true;
            }
            else if (num == 3) {
                ground = "sand";
                flage = true;
            }
            else {
                cout << "Invalid input" << endl;
                flage = false;

            }
        }
    }


    void typeOfGames() {
        int type;
        bool flage = false;
        while (flage == false) {
            cout << "Now choose type of game do you want we have \n 1. 11x11 game  \n 2. 5x5 game \n 3. 7x7 game :";
            cin >> type;
            if (type == 1) {
                TypeOfGame = "11x11 game";
                flage = true;

            }
            else if (type == 2) {
                TypeOfGame = "5x5 game";
                flage = true;

            }
            else if (type == 3)
            {
                TypeOfGame = "7x7 game";
                flage = true;

            }
            else {
                cout << "Invalid choice" << endl;
                flage = false;

            }
        }
    }
    void setNumberOfPlayers() {
        int num;
        cout << "enter number of players " << endl;
        cin >> num;
        numberOfPlayers = num;


    }
    void PriceCalculation() {


        if (ground == "wood")
        {
            price = hours * 200;
        }
        else if (ground == "MultiPurpose")
        {
            price = hours * 150;
        }
        else if (ground == "hard")
        {
            price = hours * 100;
        }

    }
    void getTimeTable() {
        cout<<"we have this hours allowed to reserve from them "<<endl;
        if (ground == "wood") {
            for (auto it : Time_TableGrass)
            {
                cout << it << endl;
            }
        }
        else if (ground == "MultiPurpose") {
            for (auto it : Time_TableConcreat)
            {
                cout << it << endl;
            }
        }
        else {
            for (auto it : Time_TableSand)
            {
                cout << it << endl;
            }
        }
    }
    void Reservation(set<int>Time_Table) {
        bool check = false;
        int f;
        int t;

        while (check == false) {
            cin >> f >> t;

            bool flage1 = false;
            bool flage2 = false;
            for (auto i : Time_Table) {
                if (f == i) {
                    flage1 = true;
                }

                if (t == i) {
                    flage2 = true;
                }
            }

            if (flage1 == false && flage2 == false) {
                cout << "there is not allowed" << endl;
                check = false;
            }
            else if (f > t || f==t) {
                cout << "not allowed" << endl;
                check = false;

            }
            else {

                timeFrom = f; timeTo = t;
                hours = t - f;
                auto itLow = Time_Table.lower_bound(f);
                auto itUpper = Time_Table.upper_bound(t);
                Time_Table.erase(itLow, itUpper);
                check = true;
                PriceCalculation();
                getInfo();
            }
        }

    }
    void ReservationSubmit() {
        if (ground == "grass"){
            Reservation(Time_TableGrass);
        }
        else if (ground == "concrete") {
            Reservation(Time_TableConcreat);

        }
        else {
            Reservation(Time_TableSand);

        }
    }
    void getInfo() {
        cout << "Your reservation is done\n your reset :" << endl;
        cout << "**********************************************************************" << endl;
        cout << "Category of Court is : " << getCategory() << endl << "Type of ground is:  " << ground << endl;
        cout << "Type of Game is : " << TypeOfGame << endl;
        cout << "Tools in court are :" << endl;
        cout << getNumberOfPlayers() << " T-shirts"<<endl ;
        cout << "2 balls"<<endl;
        cout << "Number of players allowed to enter is : " << getNumberOfPlayers() << endl;
        cout << "you reserved time from " << getTimeFrom() << " to " << getTimeTo() << " There is " << getHours() << " hour/s" << endl;
        cout<<"Total Price is : "<<price<<" L.E";


    }


};
