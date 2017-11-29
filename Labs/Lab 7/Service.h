//Service.h
#include <time.h>
#include"Animal.h"
using namespace std;
class Service{
      public:
             Service();
             void setInformation(Animal* anPTR, string type);
             string report();
      private:
          Animal* anmPTR; 
          string serviceType;
          string date;   

};

Service::Service(){
   date = "";
   serviceType = "";
   anmPTR = NULL;

}

void Service::setInformation(Animal* anPTR, string type)
{
    anmPTR = anPTR;
    serviceType = type;
    time_t now = time(0);
    char* dt = ctime(&now);
    date = dt;
}
string Service::report()
{
       string str;
       str = "Date of service: " + date + "\n";
       str += "Service type: " + serviceType + "\n";
       str += "Animal and Owner Information\n";
       str += "============================\n";
       str += anmPTR -> print();
       return str;
}
