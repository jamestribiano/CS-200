/*
This program will allow you to .
*/
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	 string firstName, lastName;
	 
     cout << "Enter full name: ";
     cin >>firstName>>lastName;
     
     int selection;
    	cout << "Banking Menu\n"
        	 << "1 - Withdraw\n"
        	 << "2 - Deposit\n"
        	 << "3 - Exit the program\n"
        	 << "Enter what you would like to you: ";
    	cin >>selection;
                    
	int balance = 0;
    int withdraw, deposit;
    int endLoop = 0;
   while (endLoop < 1 )
   {
        switch (selection)
        {
               case 1:
                 	cout << "Enter the amount you would like to withdraw $";
                    cin >> withdraw;
                    balance = balance - withdraw;           
               break;
               
               case 2:
               		cout << "Enter the amount you would like to deposit $";
                    cin >> deposit;
                    balance = balance + deposit;
                    
               case 3: cout << "Quiting the program.\n";
               endLoop = endLoop + 1;
			   break;
               
               default: cout << selection << " - is an invalid choice please chose again\n";
        }
    }
    
    return 0;
}
