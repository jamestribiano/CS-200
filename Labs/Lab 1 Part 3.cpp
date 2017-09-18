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
 	  string firstName, lastName;
 	  
      float accountBalance;
 
   public:
      BankTeller() 
	  {              
         accountBalance = 0.00;
      }
 
      void firstTimeCustomer() 
	  {
         cout << "\nEnter your name: ";    
		 cin >> firstName >> lastName;
         cout << "\nEnter a starting money value for the account: $";    
		 cin >> accountBalance;
      }
 
      void depositChecking() 
	  {
         float depositMoney;
         cout << "\nEnter amount to be deposited: ";
         cin >> depositMoney;
         accountBalance += depositMoney;
      }
     
	  void depositSavings() 
	  {
         float depositMoney;
         cout << "\nEnter amount to be deposited: ";
         cin >> depositMoney;
         accountBalance += depositMoney;
      }
 
      void withdrawChecking() 
	  {
         float withdrawMoney;
         cout << "\nEnter amount to be withdrawn: ";    
		 cin >> withdrawMoney;
         accountBalance -= withdrawMoney;
      }
      void withdrawSavings() 
	  {
         float withdrawMoney;
         cout << "\nEnter amount to be withdrawn: ";    
		 cin >> withdrawMoney;
         accountBalance -= withdrawMoney;
      }
 
      void accountDisplay() 
	  {
         cout << "Name: " <<firstName<<" "<<lastName<< endl;
         cout << "\nAccount Balance: $" << accountBalance << endl;
      }
 
};
 
int main() 
{
 
   char choice;
   int input;
   int flag = 0;
   int count = 0;
   int customerID = 0;
   BankTeller data[10]; 
 
   while (flag == 0)
    {
      cout << "\t\t\n\n" << "Bank Teller";
      cout << "\t\n\n" << "Select a number for what you would like to do: \n";
      cout << "\t\n" << "1 - Add a customer.";
      cout << "\t\n" << "2 - Deposit money into the customers checking account.";
      cout << "\t\n" << "3 - Deposit money into the customers savings account.";
      cout << "\t\n" << "4 - Withdraw money from the customers bank account.";
      cout << "\t\n" << "5 - Withdraw money from the customers bank account.";
      cout << "\t\n" << "6 - Show account information.";
      cout << "\t\n" << "7 - Quit the program.\n\n";
      cout << "Enter a number for what you want to do: ";
      choice = getche();
      switch(choice) 
	  {
         case '1':
         	customerID++;
         	cout << "\nYour account ID is: \n"<< customerID << endl;
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
            data[input].depositChecking();
            break;
        
		case '3':
            cout << "\nEnter customer number: ";
            cin >> input;
            data[input].depositSavings();
            break;
 
         case '4':
            cout << "\nEnter customer number: ";
            cin >> input;
            data[input].withdrawChecking();
            break;
        
		 case '5':
            cout << "\nEnter customer number: ";
            cin >> input;
            data[input].withdrawChecking();
            break;
 
         case '6':
            cout << "\nEnter customer number: ";
            cin >> input;
            data[input].accountDisplay();
            getche();
            break;
 
         case '7':
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
