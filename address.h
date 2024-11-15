
#ifndef ADDRESS_H
#define ADDRESS_H
#include"darray.h"
#include <iostream>
#include <string>
using namespace std;
class Address {
private:
    int streetnum;
    string streetname;
    string city;
    string state;

public:
    Address() : streetnum(0),streetname("") ,city(""), state("") {}

    Address(int streetnum,string streetname, string city, string state)
        : streetnum(streetnum),streetname(streetname), city(city), state(state) {}


    void getFullAddress()  {
        cout<<getStreetNum();
        cout<< streetname << "," + city << "," << state ;
    }
    int getStreetNum() {return streetnum;}
    void setStreetnum(const int& stnum) { streetnum = stnum; }
    void setStreetname(const string& stname) { streetname = stname; }
    void setCity(const string& ct) { city = ct; }
    void setState(const string& ste) { state = ste; }
};
#endif //ADDRESS_H
