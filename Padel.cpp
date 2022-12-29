
#include <iostream>
#include "GamesGeneral.cpp"
#include<set>
using namespace std;

class Padel : public GamesGeneral {

private:
    string size;
    string typeOfRakcet;
    int numOfRacket;
public:
    set<int > Time_Table1 = { 1,2,3,4,5,6,7,8,9 };
    set<int > Time_Table2 = { 1,2,3,4,5,6,7,8,9 };
    set<int > Time_Table3 = { 1,2,3,4,5,6,7,8,9 };

public:



    void run(){
        category = "Padel";
        cout << "Welcome to Padel Court" << endl;
        sizeOfCourt();
        numRackets();
        typeOfRackets();
        setNumberOfPlayers();
        getTimeTable();
        ReservationSubmit();

    }


    void sizeOfCourt() {
        int num;
        bool flage = false;
        while (!flage) {
            cout << "we have different sizes of courts \n choose size that you want \n 1.Wide \n 2.Narrow \n 3.Normal" << endl;
            cout << "********************************" << endl;
            cout << "one hour in wide = 200 L.E \n one hour in Normal = 150 L.E \n one hour in Narrow = 100 L.E" << endl;
            cout << "***********************************" << endl;
            cin >> num;
            if (num == 1) {
                size = "wide";
                flage = true;
            }
            else if (num == 2) {
                size = "narrow";
                flage = true;
            }
            else if (num == 3) {
                size = "normal";
                flage = true;
            }
            else {
                cout << "Invalid input" << endl;
                flage = false;

            }
        }
    }
    void numRackets() {
        bool flage = false;
        int n;
        while (flage == false) {
            cout << "Enter number of Rackets *note* you must enterd  2 or 4 only";
            cin >> n;
            if (n == 2 || n == 4) {
                numOfRacket = n;
                flage = true;
            }
            else {
                cout << "Invalid" << endl;
                flage = false;
            }
        }
    }

    void typeOfRackets() {
        int racketT;
        bool flage = false;
        while (flage == false) {
            cout << "Now enter type of rackets do you want we have \n 1.Power Racquets \n 2.Control or Player's Racquets \n 3.Tweener Racquets :";
            cin >> racketT;
            if (racketT == 1) {
                typeOfRakcet = "Power Racquets";
                flage = true;

            }
            else if (racketT == 2) {
                typeOfRakcet = "Control or Player's Racquets";
                flage = true;

            }
            else if (racketT == 3)
            {
                typeOfRakcet = "Tweener Racquets";
                flage = true;

            }
            else {
                cout << "Ivalid choice" << endl;
                flage = false;

            }
        }
    }
    void setNumberOfPlayers() {
        int num;
        bool flage=false;
        while (!flage) {
            cout << "enter number of players maximum number is 8" << endl;
            cin >> num;
            if (num > 8) {
                cout << "Invalid" << endl;
                flage = false;
            }
            else {
                numberOfPlayers = num;
                flage = true;
            }
        }
    }
    void PriceCalculation() {


        if (size == "wide")
        {
            price = hours * 200;
        }
        else if (size == "normal")
        {
            price = hours * 150;
        }
        else if (size == "narrow")
        {
            price = hours * 100;
        }

    }
    void getTimeTable() {
        cout<<"we have this hours allowed to reserve from them "<<endl;
        if (size == "wide") {
            for (auto it : Time_Table1)
            {
                cout << it << endl;
            }
        }
        else if (size == "normal") {
            for (auto it : Time_Table2)
            {
                cout << it << endl;
            }
        }
        else {
            for (auto it : Time_Table3)
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
        if (size == "wide"){
            Reservation(Time_Table1);
        }
        else if (size == "narrow") {
            Reservation(Time_Table2);

        }
        else {
            Reservation(Time_Table3);

        }
    }
    void getInfo() {
        cout << "Your reservation is done\n your reset :" << endl;
        cout << "**********************************************************************" << endl;
        cout << "Category of Court is : " << getCategory() << endl << "Type of size is:  " << size << endl;
        cout << "Type of Rackets is : " << typeOfRakcet << endl;
        cout << "Tools in court are :" << endl;
        cout << numOfRacket << " Rackets"<<endl ;
        cout << "3 balls"<<endl;
        cout << "Number of players allowed to enter is : " << getNumberOfPlayers() << endl;
        cout << "you reserved time from " << getTimeFrom() << " to " << getTimeTo() << " There is " << getHours() << " hour/s" << endl;
        cout<<"Total Price is : "<<getPice()<<" L.E";
        cout << "**********************************************************************" << endl;



    }


};
