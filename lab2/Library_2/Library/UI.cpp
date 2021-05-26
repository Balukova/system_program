

#include <iostream>
#include <stdexcept>
#include <exception>
#include "DataBase.h"

using namespace std;

int displayMenu();
void displayAll(DataBase* db);
void displayWithPositionCode(DataBase* db);
void addWorker(DataBase* db);
void getWorker(DataBase* db);

int main()
{
    DataBase* marriageDB = new DataBase();
    bool done = false;
    while (!done) {
        int selection = displayMenu();
        cout<<selection<<endl;
        switch (selection) {
            case 0:
                done = true;
                break;
            case 1:
                displayAll(marriageDB);
                break;
            case 2:
                displayWithPositionCode(marriageDB);
                break;
            case 3:
                addWorker(marriageDB);
                break;
            case 4:
                getWorker(marriageDB);
                break;
            default:
                cerr << "Unknown command." << endl;
                break;
        }
    }
    return 0;
}

int displayMenu()
{
    int selection;
    cout << endl;
    cout << "Library Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Display all workers" << endl;
    cout << "2) Display with specific position code " << endl;
    cout << "3) Add Worker" << endl;
    cout << "4) Get Worker" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> selection;
    return selection;
}

void displayAll(DataBase* db)
{
    cout << "All workers! "<<endl;
    cout << "-----------------------------------"<<endl;
    db->displayAll();
}

void displayWithPositionCode(DataBase* db)
{
    int positionCode = 0;
    cout<<"Enter Position Code ";
    cin>>positionCode;
    cout << "Workers with specific position code "<<endl;
    cout << "-----------------------------------"<<endl;
    db->displayWithPositionCode(positionCode);
}


void addWorker(DataBase* db)
{
    string pib;
    int positionCode = 0;
    cout << "Enter PIB ";
    getline(cin, pib);
    getline(cin, pib);
    cout << "Position Code ";
    cin >> positionCode;
    db->addWorker(pib, positionCode);
}

void getWorker(DataBase* db)
{
    int WorkerCode;
    cout << "Enter Worker Code ";
    cin >> WorkerCode;
    db->getWorker(WorkerCode).show();
}