/*
This program will allow the user to add multiple clients at a time,
and save all of their account information to a file called
clients.dat . The user can also edit the clients information in
the program.
*/
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

struct client
	{
       string fName;
       string lName;
       double checking;
       double savings; 
    };

	void addNewClients(client cl[], int size)
	{
    	ofstream outData;
     	outData.open("clients.dat", ios::app);
     	int i;
     	for (i = 0; i < size; i++)
       	outData <<cl[i].fName<<" "<<cl[i].lName<<" "<<0.00<<" "<<0.00<<endl;
     	outData.close();
	}
	int viewAllClients()
	{
    	ifstream inData;
     	inData.open("clients.dat");
     	string data;
     int rNum = 0;
     while (! inData.eof())
     {     inData >>data;
           rNum++;
     }
     
     rNum = (rNum -1)/4;
     inData.close();
     inData.clear();
     int i, num = 0;
	 inData.open("clients.dat");
     cout << "\nActNum\t1stNam\tLastNam\tCheck\tSav\n";
     
     while (!inData.eof())
     {
          cout <<num<<"\t";
          for (int i = 0; i < 4; i++)
          {
              inData >> data;
              cout <<data<<"\t";
          }
          num++;
          cout <<"\n";
          if (num == rNum)
             break;
     }
     inData.close();
     return rNum;
}

	void addClients(client cl[], int size)
	{	
    	 int i;
     	for (i = 0; i < size; i++)
     	{
        	 cout << "Enter your full name: ";
         	cin >> cl[i].fName>>cl[i].lName;
     	}
	}

	void transactions(client &cl)
	{	
    	int selection;
     	double moneyBeingTransfered;
     	cout <<"\tClient Information:\n";
        cout <<"\tName: "<<cl.fName<<" "<<cl.lName<<"\n";
       	cout <<"\tChecking Balance: $"<<fixed<<setprecision(2)<<cl.checking<<"\n";
        cout <<"\tSavings Balance: $"<<cl.savings<<"\n";
     do
     {
         cout << "Transaction Type\n";
         cout << "1 - Deposit to Checking\n";
         cout << "2 - Deposit to Savings\n";
         cout << "3 - Withdraw from Checking\n";
         cout << "4 - Withdraw from Savings\n";
         cout << "5 - Cancel Transaction\n";
         cout << "Enter your choice: ";
         cin >> selection;
         
     }while (selection < 1 || selection > 5);
     
     switch(selection)
     {
         case 1:
              cout << "Enter the amount you would like to deposit into your checking account $";
              cin >> moneyBeingTransfered;
              cl.checking += moneyBeingTransfered;
         	  break;
         case 2:
              cout << "Enter the amount you would like to deposit into your savings account: $";
              cin >> moneyBeingTransfered;
              cl.savings += moneyBeingTransfered;
        	  break;
         case 3:
              cout << "Enter the amount you would like to withdraw into your checking account: $";
              cin >> moneyBeingTransfered;
              cl.checking -= moneyBeingTransfered;
        	  break;
         case 4:
              cout << "Enter the amount you would like to withdraw into your savings account: $";
              cin >> moneyBeingTransfered;
              cl.savings -= moneyBeingTransfered;
         	  break;
         
     }
}
	void loading(client cl[], int size)
	{
    	 ifstream inData;
     	 inData.open("Client Information.dat");
     	 int i;
     	for (i = 0; i < size; i++)
     	{
     	    inData >>cl[i].fName;
        	inData >>cl[i].lName;
         	inData >>cl[i].checking;
         	inData >>cl[i].savings;
     	}
	}	

	int mainMenu()
	{
    	int selection;
    	cout << "Banking Menu\n"
        	 << "1 - Add new clients\n"
        	 << "2 - Transactions on clients accounts\n"
        	 << "3 - Show Report\n"
        	 << "4 - Exit the program\n"
        	 << "Enter what you would like to you: ";
    	cin >>selection;
    	return selection;
	}

int main()
{
    int selection, newClients, clientsSavedInFile, clientToBeEdited;
    client cl[75];
    int i, j;
    
    do
    {
        selection = mainMenu();
        switch (selection)
        {
               case 1: 
                    cout << "How many new clients do you want to add to the file: ";
                    cin >> newClients;
                    addClients(cl, newClients);
                    addNewClients(cl, newClients);
                    
               break;
               case 2:
                       clientsSavedInFile = viewAllClients();
                       cout <<"Pick an acount number: ";
                       cin >> clientToBeEdited;
                       loading(cl, clientsSavedInFile);
                       transactions(cl[clientToBeEdited]);
                       {ofstream outData;
                       outData.open("clients.dat");
                       for (i = 0; i < clientsSavedInFile; i++)
                           outData << cl[i].fName << " " << cl[i].lName << " " << cl[i].checking << " " << cl[i].savings << endl;
                       outData.close();}
              
               break;
               case 3:
                    clientsSavedInFile = viewAllClients();
               break;
               case 4: cout << "Quiting the program.\n";
               break;
               default: cout << selection << " - is an invalid choice please chose again\n";
        }
        system("PAUSE");
    }while (selection != 4);
    
    return 0;
}
