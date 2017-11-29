#include <cstdlib>
#include <iostream>
#include"Dog.h"
#include"Cat.h"
#include"Service.h"

using namespace std;

int menu()
{
    int choice;
    cout <<"Main Menu\n"
         <<"=========\n"
         <<"1. Enter a cat\n"
         <<"2. Enter a dog\n"
         <<"3. View all services on all animals\n"
         <<"4. Exit\n"
         <<"Enter your choice: ";
    cin >>choice;
    return choice;
}
void animalInfo(Animal* ptr)
{
     string data;
     cout <<"Enter the animal name: ";
     cin >>data;
     ptr ->setPetName(data);
     cout <<"Enter the owner's first name: ";
     cin >>data;
     ptr ->setOwnerName(data);
}
void myService(Service* srv, Animal* anPTR)
{
     string option[3]={"Rabies", "Distemper", "Fleas"};
     int choice;
     do
     {
         system("CLS");
         cout <<"Service choices\n";
         for (int i = 0; i < 3; i++)
             cout <<i+1<<" "<<option[i]<<endl;
         cout <<"Enter your choice: ";
         cin >>choice;
     }while (choice < 1 || choice > 3);
     srv ->setInformation(anPTR, option[choice - 1]);
     
}

int main(int argc, char *argv[])
{
    Service services[100];
    Cat cats[100];
    Dog dogs[100];
    
    int serviceCount = 0;
    int catCount = 0;
    int dogCount = 0;
   
    int option;
    do
    {
        system("CLS");
        option = menu();
        switch(option)
        {
             case 1:
                  //use the array fo cats to enter the cat's info
                  animalInfo(&cats[catCount]);
                  //update a service for that cat
                  myService(&services[serviceCount], &cats[catCount]);
                  //increment the cat count and the service count
                  catCount++;
                  serviceCount++;
                  break;
             case 2:
                   animalInfo(&dogs[dogCount]);
                   myService(&services[serviceCount], &dogs[dogCount]);
                   dogCount++;
                   serviceCount++;
                   break;
                  
             case 3: //print all services
                  for (int i = 0; i < serviceCount; i++)
                      cout <<services[i].report()<<endl;
                   break;       
             case 4: cout <<"Goodbye!\n";
                  break; 
             default: cout <<option<<" is not a valid option!\n";
        }
        
        system("PAUSE");
    }while (option !=4);
    
    
    /*
    Service sv1;
    Cat ct1;
    ct1.setOwnerName("drew");
    ct1.setPetName("fifi");
    sv1.setInformation(&ct1, "rabies");
    cout <<sv1.report()<<endl;
    */
    
    
    return EXIT_SUCCESS;
}
