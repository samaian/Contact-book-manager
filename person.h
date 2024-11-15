#ifndef PERSON_H
#define PERSON_H
#include<bits/stdc++.h>
#include"address.h"
//#include"darray.h"
using namespace std;
class person
{
private:
    string firstName;
    string lastName;
    string Classification;
    bool Favorite;
    Address add;
    int nn,mm;
    vector<string>phoneNumber,Email;

public:
    person(){}
    person (string firstname,string lastname,string classification,vector<string> numofnums,int n,
            vector<string> numofemails,int m,Address &addr, bool favorite)
        :firstName(firstname),
         lastName(lastname),
         Classification(classification),
         phoneNumber(numofnums),
         nn(n),
         Email(numofemails),
         mm(m),
         add(addr),Favorite(favorite) {}
    person(const string& fName, const string& lName, bool fav, const string& classif)
      : firstName(fName), lastName(lName), Favorite(fav), Classification(classif) {}

    person(const string& fName, const string& lName, const string& classif,string phone,string email,  bool fav)
     : firstName(fName), lastName(lName), Classification(classif), Favorite(fav) {
        phoneNumber.push_back(phone);
        Email.push_back(email);

    }

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    bool isFavorite() const { return Favorite; }
    string getClassification()  { return Classification; }

    void setFirstName(string fName) { firstName = fName; }
    void setLastName(string lName) { lastName = lName; }
    //void setPhoneNumber(string phone) { phoneNumber = phone; }
    //void setEmail(string email) { this->email = email; }
    void setClassification(string classif) { Classification = classif; }
    void setFavorite(bool fav) { Favorite = fav; }
    void setAddress(Address addr) { add = addr; }
    bool operator==(const person& other) const {
        return (firstName == other.firstName &&lastName==other.lastName&& phoneNumber == other.phoneNumber && Email == other.Email);
    }
    void printaddress() {
        add.getFullAddress();
    }
    void printphone() {
        for(int i=0;i<phoneNumber.size();i++)cout<<phoneNumber[i]<<",";
    }
   /* void printEmail() {
        for(int i=0;i<Email.size();i++)cout<<Email[i]<<",";
    }*/

    void getInfo()  {
    cout << "==================================================================================================================================\n";
        cout << setw(5) << "FName" << setw(15) << "LName"
             << setw(20) << "Classification" << setw(15) << "Favorite"<<setw(15)<<"        Address"<<setw(30)<<"Phone Number\n";
    cout << "==================================================================================================================================\n";
            cout<< setw(5) << getFirstName()
                 << setw(15) << getLastName()
                 << setw(15) << getClassification();
            cout  << setw(17) << (isFavorite() ? "Yes" : "No")
            <<setw(10) ;
            printaddress();
            cout<<setw(26);
            printphone();
            cout<<endl;
    cout << "==================================================================================================================================\n";
    }
};
#endif //PERSON_H
