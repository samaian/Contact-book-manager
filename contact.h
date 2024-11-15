#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED
#include <iostream>
#include <string>
#include"darray.h"
#include "Address.h"
#include"person.h"
using namespace std;
class contact {
private:
    Darray<person> contacts;
public:
    void AddContact( person& p) {
        contacts.append(p);
    }
    int getContactSize() const {
        return contacts.getSize();
    }

    person getContact(int index)  {
        return contacts[index]; // Use dynamic array indexing
    }

    void deleteContact(int index) {
        if (index >= 0 && index < contacts.getSize()) {
            contacts.remove(index);
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    void printFavoriteContacts()  {
        int j=1;
        for (int i = 0; i < contacts.getSize(); ++i) {
            if (contacts[i].isFavorite()) {
                cout<<j;j++;
                contacts[i].getInfo() ;

            }
        }
    }

    person* searchByLastName(const string& lastName) {
        for (int i = 0; i < contacts.getSize(); ++i) {
            if (contacts[i].getLastName() == lastName) {
                return &contacts[i];
            }
        }
        return nullptr;
    }

    void searchByClassification(const string& classification) {
        for (int i = 0; i < contacts.getSize(); ++i) {
            int j=1;
            if (contacts[i].getClassification() == classification) {
                cout<<j;j++;
                contacts[i].getInfo() ;
            }
        }
    }

    void saveToFile(const string& filename) const {
        std::fstream file;
        file.open(filename, ios::out);
        if (!file.is_open()) {
            cout << "Error opening file for writing: " << filename << endl;
            return;
        }

        for (int i = 0; i < contacts.getSize(); ++i) {
            person contact = contacts[i];

            file<<"First Name"<<setw(25)<<"Last Name"<<setw(25)<<"Favorite"<<setw(25)<<"Classification"<<setw(25)<<"\n";
            file << contact.getFirstName() << setw(25)
                 << contact.getLastName() << setw(30)
                 << (contact.isFavorite() ? "1" : "0") << setw(25)
                 << contact.getClassification() << ".\n";
        }

        file.close();
        cout << "Contacts saved to " << filename << " successfully!" << endl;
    }


    void loadFromFile(const string& filename) {
        ifstream in(filename);
        fstream file;
        file.open(filename/*ios::binary*/);
        if (!file.is_open()) {
            cout << "Error opening file : "<<filename<<" for reading" << std::endl;
            return;
        }
        string line;
        getline (in, line);
        string firstName, lastName, isFavoriteStr, classification,phone,mail;
        vector<string>read;
        string x="";
        int favv;
        for(int i=0;line[i]!=',';i++) {
            if(line [i]!=' ')
                x+=line[i];
            else {
                read.push_back(x);
                x="";
            }
            if(line[i]=='1'||line[i]=='0')favv=line[i]-'0';
        }
        firstName=read[0];
        lastName=read[1];
        classification=read[2];
        phone =read[3];
        mail=read[4];


        person contact(firstName, lastName,classification,phone ,mail,favv);
        // AddContact(contact);
        contacts.append(contact);
        file.close();
        cout << "Contacts loaded from " << filename << " successfully!" << endl;
    }

    void updateContact(int index) {
        if (index < 0 || index >= contacts.getSize()) {
            cout << "Invalid index!" << endl;
            return;
        }

        person& contact = contacts[index];



        string newFirstName, newLastName,newClassification;
        bool isFavorite;

        cout << "Current First Name: " << contact.getFirstName() << endl;
        cout << "Enter new First Name (or press Enter to keep it unchanged): ";
        getline(cin, newFirstName);
        if (newFirstName.empty())
            newFirstName = contact.getFirstName();
        cout << "Current Last Name: " << contact.getLastName() << endl;
        cout << "Enter new Last Name (or press Enter to keep it unchanged): ";
        getline(cin, newLastName);
        if (newLastName.empty())
            newLastName = contact.getLastName();

        cout<<"Current Classification: "<<contact.getClassification()<<endl;
        cout << "Enter new Classification (or press Enter to keep it unchanged): ";
        getline(cin, newClassification);
        if (newClassification.empty())
            newFirstName = contact.getClassification();

        cout << "Current Favorite Status: " << (contact.isFavorite() ? "Yes" : "No") << endl;
        cout << "Mark as Favorite? (1 for Yes, 0 for No): ";
        cin >> isFavorite;
        contact.setFirstName(newFirstName);
        contact.setLastName(newLastName);
        contact.setFavorite(isFavorite);
        contact.setClassification(newClassification);

        cout << "Contact information updated successfully!" << endl;
    }


    void reverseContacts() {
        contacts.Reverse();
        cout << "Contacts reversed successfully!" << endl;
    }
    void RemoveDuplicates() {
        contacts.RemoveDuplicates();
    }



};


#endif // CONTACT_H_INCLUDED


