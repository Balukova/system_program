#pragma once
#include "Worker.h"
#include <string>
#include <vector>

using namespace std;
class DataBase {
    public:
        DataBase();

        ~DataBase();
        Worker& addWorker(const string& pib, const int& positionCode);
        Worker& getWorker(const int& WorkerCode) ;
        Worker& getWorker(const string& pib, const int& positionCode) ;
        void displayAll() const;
        void displayWithPositionCode(const int& positionCode) const;

    private:
        int nextWorkerCode = 0;
        vector<Worker> Workers;
};