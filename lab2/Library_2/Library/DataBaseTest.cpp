#include "DataBase.h"
#include <iostream>

using namespace std;

int main() {
    DataBase* my_db = new DataBase();
    cout<<"Test Start"<<endl;
    my_db->displayAll();
    cout<<"Test End"<<endl;

}