// AirlineTicket.cpp

#include <iostream>
#include "Worker.h"

using namespace std;

Worker::Worker()
{
  // initialize data members
  mPIB = "Unknown Worker";
  mAge = 0;
  mWorkerCode = 0;
  mSex = "Unknown";
  mPassport = "Unknown";
  mPositionCode = 0;
  mAddress  = " Unknown";

}

Worker::~Worker()
{
  // nothing much to do in terms of cleanup
}

int Worker::calculateSalaryInDollars()
{
  if (getPositionCode() == 0) {

    return 700;
  }
 
 
  return static_cast<int>((getPositionCode() * 500));
}

int Worker::getWorkerCode()
{
  return mWorkerCode;
}

void Worker::setWorkerCode(int inCode)
{
  mWorkerCode = inCode;
}
int Worker::getPositionCode()
{
  return mPositionCode;
}

void Worker::setPositionCode(int inCode)
{
  mPositionCode = inCode;
}

string Worker::getPIB()
{
  return mPIB;
}

void Worker::setPIB(string inPIB)
{
  mPIB = inPIB;
}
string Worker::getSex()
{
  return mSex;
}

void Worker::setSex(string inSex)
{
  mSex = inSex;
}


int Worker::getAge()
{
  return mAge;
}

void Worker::setAge(int inAge)
{
  mAge = inAge;
}

string Worker::getAddress()
{
  return mAddress;
}

void Worker::setAddress(string inAddress)
{
  mAddress = inAddress;
}


string Worker::getPassport()
{
  return mPassport;
}

void Worker::setPassport(string inPassport)
{
  mPassport = inPassport;
}
