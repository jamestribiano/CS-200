//Cat.h
#include"Animal.h"

class Cat: public Animal{
      public:
      virtual string print() const;
};

string Cat::print()const
{
       string str = "Cat Name: " + petName + "\n" + "Owner Name: " + ownerName;
       return str;
}
