// AirlineTicketTest.cpp

#include <iostream>
#include "Worker.h"

using namespace std;

int main(int argc, char** argv)
{
 Worker WorkerStack;
    Worker* WorkerHeap;
    WorkerHeap = new Worker();

    WorkerStack.setAge(20);
    WorkerStack.setPIB("John Brown");
    WorkerStack.setSex("male");
    WorkerStack.setAddress("Kyiv");
    WorkerStack.setPositionCode(1);

    WorkerHeap->setAge(29);
    WorkerHeap->setPIB("Alice White");
    WorkerHeap->setSex("female");
    WorkerHeap->setAddress("Kyiv");

    std::cout << WorkerStack.getPIB() << " "
            << WorkerStack.getAge() << " "
            << WorkerStack.getSex() << " "
            << WorkerStack.getAddress() << " "
            << WorkerStack.getPositionCode() << " "
            << WorkerStack.calculateSalaryInDollars()
            << std::endl;


    std::cout << WorkerHeap->getPIB() << " "
            << WorkerHeap->getAge() << " "
            << WorkerHeap->getSex() << " "
            << WorkerHeap->getAddress() << " "
            << WorkerStack.getPositionCode() << " "
            << WorkerHeap->calculateSalaryInDollars() 
            << std::endl;

    delete WorkerHeap;

  return 0;
} 
