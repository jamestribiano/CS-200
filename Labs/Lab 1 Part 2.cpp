//Banking program
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main()
{

	char choice; 
	float withdraw, deposit;
	float balance = 0;
	float savings = 0; 
	float checking = 0;
	string firstName, lastName;
	int flag = 0;
	
	while (flag == 0) {
      cout << "\t\n\n" << "Select a number for what you want to do:";
      cout << "\t\n" << "1 - Withdraw money from savings account.";
      cout << "\t\n" << "2 - Withdraw money from your checking account.";
      cout << "\t\n" << "3 - Deposit money into your savings account.)";
      cout << "\t\n" << "4 - Deposit money into your checking account.)";
      cout << "\t\n" << "5 - View your saving and checking account balances.)";
      cout << "\t\n" << "6 - Quit the program.\n\n";
      cout << "What would you like to do: ";
      choice = getche();
      switch(choice) 
	  {
         case '1':
            cout << "\nEnter the amount you would like to withdraw from your savings account: $";
            cin >> withdraw;
            savings = savings - withdraw;
            break;
        case '2':
            cout << "\nEnter the amount you would like to withdraw from your checkings account: $";
            cin >> withdraw;
            checking = checking - withdraw;
            break;
 
         case '3':
           cout << "\nEnter the amount you would like to deposit into your savings account: $";
            cin >> deposit;
            savings = savings + deposit;
            break;
 
         case '4':
            
			cout << "\nEnter the amount you would like to deposit into your checkings account: $";
            cin >> deposit;
            checking = checking + deposit;
            break;
 
 
         case '5':
            system("cls");
			cout << "\nYour savings account balance: $"<<savings<<endl;
            cout << "Your savings checking balance: $"<<checking<<endl;
        
            break;
         
		 case '6':
            flag = 1;
            break;
 
         default: //returns the user to the main menu if they enter an invalid character or number.
            cout << "\nInvalid selection. Hit enter to return to the main menu";
            getche();
      }
 
      if (flag == 1) 
	  {
         break;
      }
 
   }
   return 0;
}
