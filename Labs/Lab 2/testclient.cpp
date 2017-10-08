/*
CS-200 Lab 2

This program will allow the user to store clients data in an external file,
it will also allow the user to edit the file. The file is encrypted and the
program will decrypt the informatoin that you chose to edit.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#include"client.h"

int main(int argc, char *argv[])
{
    int choice;
    int flag = 0;
    while(flag == 0)
    {
        cout<<"\t---Main Menu---";
        cout<<"\n1. Add a new client.";
        cout<<"\n2. Show all clients stored in the file.";
        cout<<"\n3. Edit an existing client.";
        cout<<"\n4. Delete a client from the file.";
        cout<<"\n5. Exit the program.";
        cout<<"\nEnter a number for what you want to do: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
				client st1;
                st1.writeOutToFile();
                break;
			}
            case 2:
            {
                client st1;
            	st1.readFromFile();
            	break;
			}
            case 3:
            {
                client st1;
                st1.editClientInformatoin();
                break;
			}
            case 4:
           	{
            	client st1;
            	st1.deleteClientFromFile();
            	break;
			}
            case 5:
           	{
				flag = 1;
           		cout << "\n";
           		break;
			}
            default:
                cout<<"\nInvalid selection. Hit enter to return to the main menu.\n";
                exit(0);
        }
			if (flag == 1) 
	  		{
        		 break;
      		}
    }
    system("PAUSE");
    return 0;
}
