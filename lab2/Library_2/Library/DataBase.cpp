#include <iostream>
#include <stdexcept>
#include "DataBase.h"
#include <fstream>
using namespace std;
DataBase::DataBase() {
    Worker worker;
    worker.setPIB("Worker1");
    worker.setAge(20);
    worker.setAddress("Address1");
    worker.setPIB("Passport1");
    worker.setPositionCode(0);
    worker.setSex("Male");
    worker.setWorkerCode(this->nextWorkerCode++);
    Workers.push_back(worker);

        Worker worker2;
    worker2.setPIB("Worker2");
    worker2.setAge(20);
    worker2.setAddress("Address2");
    worker2.setPIB("Passport2");
    worker2.setPositionCode(1);
    worker2.setSex("Female");
    worker2.setWorkerCode(this->nextWorkerCode++);
    Workers.push_back(worker2);

        Worker worker3;
    worker3.setPIB("Worker3");
    worker3.setAge(18);
    worker3.setAddress("Address3");
    worker3.setPIB("Passport3");
    worker3.setPositionCode(0);
    worker3.setSex("Male");
    worker3.setWorkerCode(this->nextWorkerCode++);
    Workers.push_back(worker3);
};
DataBase::~DataBase() {};

Worker& DataBase::addWorker(const string& pib, const int& positionCode){
        Worker* worker = new Worker();
        worker->setPIB(pib);
        worker->setPositionCode(positionCode);
        worker->setWorkerCode(this->nextWorkerCode++);
        Workers.push_back(*worker);
        return *worker;
}
 Worker& DataBase::getWorker(const string& pib, const int& positionCode) {
        for(Worker& Worker : this->Workers) {
            if(Worker.getPIB() == pib && Worker.getPositionCode() == positionCode) return Worker;
        }

}
 Worker& DataBase::getWorker(const int& WorkerCode) {
        for(Worker& Worker : this->Workers) {
            if(Worker.getWorkerCode() == WorkerCode) return Worker;
        }
}

void DataBase::displayAll() const {
    for(Worker Worker : this->Workers) {
        Worker.show();
    }
}
void DataBase::displayWithPositionCode(const int& positionCode) const {
    for(Worker Worker : this->Workers) {
        if(Worker.getPositionCode() == positionCode) 
             Worker.show();
    }
}
