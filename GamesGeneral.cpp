#include<iostream>
#include<set>
using namespace std;
class GamesGeneral{
protected:
    int timeFrom, timeTo, hours = 0,numberOfPlayers;
    float price=0;
    string  category;

public:

    int getNumberOfPlayers() {
        return numberOfPlayers;
    }



    float getPice() {
        return price;
    }
    int getHours() {
        return hours;
    }



    int getTimeFrom() {
        return timeFrom;
    }



    int getTimeTo() {
        return timeTo;
    }



    string getCategory() {
        return category;
    }



    virtual void Reservation(set<int>c) = 0;
    virtual void getInfo() = 0;
    virtual void getTimeTable() = 0;
    virtual void PriceCalculation() = 0;

};
