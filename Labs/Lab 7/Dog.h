//Dog.h
#include"Animal.h"

class Dog: public Animal{
public:
      virtual string print() const;
};

string Dog::print()const
{
       string str = "Dog Name: " + petName + "\n" + "Owner Name: " + ownerName;
       return str;
}
