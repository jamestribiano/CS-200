/*
CS-200 Lab 1

This program will allow the user to store up to 10 customers
bank account information. The user can withdraw, deposit money from customers accounts,
view the users bank account by using their ID and create customer accounts. 
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
 
class BankTeller 
{
 	  char accountName[20];
      float accountBalance;
 
   public:
      BankTeller() 
	  {              
         accountBalance = 0.00;
      }
 
      void firstTimeCustomer() 
	  {
         cout << "\nEnter your name: ";    
		 cin >> accountName;
         cout << "\nEnter a starting money value for the account: $";    
		 cin >> accountBalance;
      }
 
      void deposit() 
	  {
         float depositMoney;
         cout << "\nEnter amount to be deposited: ";
         cin >> depositMoney;
         accountBalance += depositMoney;
      }
 
      void withdraw() 
	  {
         float withdrawMoney;
         cout << "\nEnter amount to be withdrawn: ";    
		 cin >> withdrawMoney;
         accountBalance -= withdrawMoney;
      }
 
      void accountDisplay() 
	  {
         cout << "Name: " << accountName;
         cout << "\nAccount Balance: $" << accountBalance << endl;
      }
 
};
 
int main() 
{
 
   char choice;
   int input;
   int flag = 0;
   int count = 0;
   BankTeller data[10]; 
 
   while (flag == 0)
    {
      cout << "\t\t\n\n" << "Bank Teller V1";
      cout << "\t\n\n" << "Select a number for what you would like to do: \n";
      cout << "\t\n" << "1 - Add a customer (Max amount that can be stored is 10).";
      cout << "\t\n" << "2 - Deposit money into the customers bank account.";
      cout << "\t\n" << "3 - Withdraw money from the customers bank account.";
      cout << "\t\n" << "4 - Show account information (The customers id number starts at 1 and goes up as you add users.)";
      cout << "\t\n" << "5 - Quit the program.\n\n";
      cout << "Enter a number for what you want to do: ";
      choice = getche();
      switch(choice) 
	  {
         case '1':
            if (count > 10) 
			{
               cout << "Can't add anymore customers, the max is 10 please press any key to return to the main menu";
               getche();
               break;
            }
            count += 1;
            data[count].firstTimeCustomer();
            break;
 
         case '2':
            cout << "\nEnter customer number: ";
            cin >> input;
            data[input].deposit();
            break;
 
         case '3':
            cout << "\nEnter customer number: ";
            cin >> input;
            data[input].withdraw();
            break;
 
         case '4':
            cout << "\nEnter customer number: ";
            cin >> input;
            data[input].accountDisplay();
            getche();
            break;
 
         case '5':
            flag = 1;
            cout << "\n";
            break;
 
         default: //returns the user to the main menu if they enter an invalid character or number.
            cout << "\nInvalid selection. Hit enter to return to the main menu.\n";
            getche();
      }
 
      if (flag == 1) 
	  {
         break;
      }
 
   }
   system("PAUSE");
   return 0;
}
