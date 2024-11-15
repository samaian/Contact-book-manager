#include <bits/stdc++.h>
#include <iomanip>
#include"person.h"
#include "contact.h"
#include "Address.h"
#include"darray.h"
using namespace std;
#define table cout << left << setw(20) << setfill(' ')
void printMenu()
{
    cout <<setw(30)<<"                                    ===================================================================\n";
    cout <<setw(30)<<"                                    |                       Contact Menu                              |"<<std::endl;
    cout <<setw(30)<<"                                    ===================================================================\n";
    cout <<setw(30)<<"                                    | 1. Add a new Contact                                            |\n";
    cout <<setw(30)<<"                                    | 2. Search by Last Name (Enter LastName correctly)               |\n";
    cout <<setw(30)<<"                                    | 3. Search by Classification (friend, work, family, other)       |\n";
    cout <<setw(30)<<"                                    | 4. Print All Contacts                                           |\n";
    cout <<setw(30)<<"                                    | 5. Print Fav Contacts                                           |\n";
    cout <<setw(30)<<"                                    | 6. Save to File                                                 |\n";
    cout <<setw(30)<<"                                    | 7. Load from File                                               |\n";
    cout <<setw(30)<<"                                    | 8. Delete Contact                                               |\n";
    cout <<setw(30)<<"                                    | 9. Update Contact Information                                   |\n";
    cout <<setw(30)<<"                                    | 10. Reverse contacts book                                       |\n";
    cout <<setw(30)<<"                                    | 11. Exit                                                        |\n";
    cout <<setw(30)<<"                                    |=================================================================|\n";
    cout << setw(30)<<"                                   Your choice: ";
}

const void printAllContacts( contact & contactBook)
{
    contactBook.RemoveDuplicates();
    cout << "==================================================================================================================================\n";
    cout << setw(5) << "ID" << setw(20)  <<"FName"  <<setw(20) <<"LName"
         << setw(20) <<"Classification" << setw(20) << "Favorite"<<setw(13)<<"Address"<<setw(30)<<"Phone Number\n";
    cout << "==================================================================================================================================\n";

    for (int i = 0; i < contactBook.getContactSize(); i++)
    {

        person contact = contactBook.getContact(i);
        cout << setw(5) << i + 1
             << setw(20) << contact.getFirstName()
             <<setw(20) << contact.getLastName()
             <<setw(20) << contact.getClassification();
            cout  << setw(15) << (contact.isFavorite() ? "Yes" : "No")
            <<setw(10) ;
            contact.printaddress();
           cout<<setw(20 );
           contact.printphone();
           cout<<endl;
    }
       cout << "==================================================================================================================================\n";
}
void enterdata(contact &cont)
{
    string firstName, lastName, classification, streetname, city, state;
    bool fav;
    int nums,numemail,stnum;

    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Classification (friend, family, work, other): ";
    cin >> classification;
    //============================================================================

    cout<<"How many numbers for this contact ? ";
    cin>>nums;
    vector<string> numofnums(nums);
    cout << "Enter "<<nums<<" Phone Number: \n";
    for(int i=0; i<nums; i++)
    {
        cout<<"Enter phone (" << i+1 << ") : ";
        cin>>numofnums[i];
        string x=numofnums[i];
        if(x.size()<13||x.size()>13||x[0]!='+'||x[1]!='2'||x[2]!='0'||x[3]!='1'){
            cout<<"invalid number , please enter it again\n";
        i--;
        }
    }
    //=================================================================================
    cout<<"How many emails for this contact ? ";cin>>numemail;
    vector<string >numofemails(numemail);
    cout << "Enter "<<numemail<<" Phone Number: ";
    for(int i=0; i<numemail; i++)
    {
        cout<<"Enter email ("<<i+1<<") : ";
        cin>>numofemails[i];
        string y=numofemails[i];
        if(!(y.find("@gmail.com")&&y[y.size()-1]=='m'&&y[y.size()-2]=='o'&&y[y.size()-3]=='c')){
            cout<<"invalid email , please enter it again\n";
        i--;
        }
    }
    //==================================================================================
    cout << "Enter Address (Street number , Street name , City , State):\n";
    cout<<"Street number => ";cin >> stnum;
    cout<<"Street name   => ";cin >>  streetname;
    cout<<"City name     => ";cin >> city;
    cout<<"State name    => ";cin >> state;
    //==================================================================================
    cout << "Is this a favorite contact? (1 for Yes, 0 for No): ";
    cin >> fav;

    Address addr(stnum,streetname ,city, state);
    person per(firstName,lastName,classification, numofnums,nums
               ,numofemails, numemail
                ,addr,
                fav);
           cont.AddContact(per);


}

int main() {
    int choice;
    contact myContacts;
    do {
        for(int i=0;i<1;i++) {
            printMenu();
            cin >> choice;
        }
        switch (choice)
        {
            case 1:
                cout<<endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
            cout <<setw(30)<<"                                    |                         ADD CONTACT                             |"<<std::endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
                enterdata(myContacts);
                break;
            case 2:
            {
                cout<<endl;
                cout <<setw(30)<<"                                    ===================================================================\n";
                cout <<setw(30)<<"                                    |                       SEARCH BY LAST NAME                       |"<<std::endl;
                cout <<setw(30)<<"                                    ===================================================================\n";
                string lastName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                person* result = myContacts.searchByLastName(lastName);

                if (result)
                {
                     result->getInfo() ;
                }
                else
                {
                    cout << "No contact found with that last name.\n";
                }
                break;
            }
            case 3:
            {
                cout<<endl;

                cout <<setw(30)<<"                                    ===================================================================\n";
                cout <<setw(30)<<"                                    |                       SEARCH BY CLASSIFICATION                  |"<<std::endl;
                cout <<setw(30)<<"                                    ===================================================================\n";
                string classification;
                cout << "Enter Classification: ";
                cin >> classification;
                myContacts.searchByClassification(classification);
                break;
            }
            case 4:
                cout<<endl;

            cout <<setw(30)<<"                                    ===================================================================\n";
            cout <<setw(30)<<"                                    |                       PRINT ALL CONTACTS                        |"<<std::endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
                printAllContacts(myContacts);
            break;
            case 5:
                cout<<endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
            cout <<setw(30)<<"                                    |                       PRINT FAVORITE CONTACTs                   |"<<std::endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
                myContacts.printFavoriteContacts();
            break;
            case 6:
            {
                cout<<endl;
                cout <<setw(30)<<"                                    ===================================================================\n";
                cout <<setw(30)<<"                                    |                       SAVE CONTACTS TO FILE                     |"<<std::endl;
                cout <<setw(30)<<"                                    ===================================================================\n";
                string filename;
                cout << "Enter filename to save: ";
                cin >> filename;
                myContacts.saveToFile(filename);
                break;
            }
            case 7:
            {
                cout<<endl;

                cout <<setw(30)<<"                                    ===================================================================\n";
                cout <<setw(30)<<"                                    |                       LOAD CONTACTS FROM FILE                   |"<<std::endl;
                cout <<setw(30)<<"                                    ===================================================================\n";
                string filename;
                cout << "Enter filename to load: ";
                cin >> filename;
                myContacts.loadFromFile(filename);
                break;
            }
            case 8:
            {
                cout<<endl;

                cout <<setw(30)<<"                                    ===================================================================\n";
                cout <<setw(30)<<"                                    |                       DELETE CONTACT BY INDEX                   |"<<std::endl;
                cout <<setw(30)<<"                                    ===================================================================\n";
                int index;
                cout << "Enter contact index to delete: ";
                cin >> index;
                myContacts.deleteContact(index);
                break;
            }
            
            case 9:
            cout<<endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
            cout <<setw(30)<<"                                    |                       UBDATE CONTACT INFORMATION                |"<<std::endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
            cout << "Update Contact Information feature\n";
            cout << "Enter index of contact to update: ";
            int updateIndex;
            cin >> updateIndex;
            cin.ignore();
            myContacts.updateContact(updateIndex);
            break;

            case 10:
                cout<<endl;

            cout <<setw(30)<<"                                    ===================================================================\n";
            cout <<setw(30)<<"                                    |                       REVERSE CONTACT BOOK                      |"<<std::endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
                cout << "Reverse contacts book feature\n";
            myContacts.reverseContacts();
            break;

            case 11:
                cout<<endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
            cout <<setw(30)<<"                                    |                              EXIT                               |"<<std::endl;
            cout <<setw(30)<<"                                    ===================================================================\n";
                cout << "Exiting...\n";
            return 0;
            break;
            default:
                cout<<endl;
                cout << "Invalid choice. Try again.\n";
        }
    }while (choice != 12);

    return 0;

}

