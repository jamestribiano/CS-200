//Animal.h
#include<string>
using namespace std;
#ifndef ANIMAL_H
#define ANIMAL_H
class Animal
{
      public:
         Animal();
         void setPetName(string name);
         void setOwnerName(string name);
         virtual string print() const = 0;
      protected:
         string petName;
         string ownerName;
      };

Animal::Animal(){
   setPetName("");
   setOwnerName("");
}
void Animal::setPetName(string name){petName = name;}
void Animal::setOwnerName(string name){ownerName = name;}
#endif
