// Client.h

#include <string>
class Worker
{
 public:
  Worker();
  ~Worker();

  int  calculateSalaryInDollars();

  int          getWorkerCode();
  void         setWorkerCode(int code);
  std::string  getPIB();
  void         setPIB(std::string PIB);
  std::string  getSex();
  void         setSex(std::string sex);
  int          getAge();
  void         setAge(int age);
  int          getPositionCode();
  void         setPositionCode(int code);
  std::string  getAddress();
  void         setAddress(std::string address);
  std::string  getPassport();
  void         setPassport(std::string passport);
  void  show();
 private:
  int  mWorkerCode;
  std::string  mPIB;
  std::string  mSex;
  int          mAge;
  int          mPositionCode;
  std::string  mAddress;
  std::string  mPassport;
}; 
