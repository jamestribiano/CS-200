//Client.cpp
#include<string>
#include<iostream>
#include<fstream>
#include<istream>
using namespace std;
using std::fstream; 
#include"client.h"

//Constructors
client::client()
{

}
client::client(string f, string l)
{
	
}

void client::newClient()
{
    cout<<"\nEnter the acount number you would like to assign: ";
    cin>>accID;
    cout<<"Enter the clients first name: ";
    cin>>fname;
    cout<<"Enter the clients last name: ";
    cin>>lname;
    cout<<"Enter starting savings balance: $";
    cin>>savingsBalance;
    cout<<"Enter starting checking balance: $";
    cin>>checkingBalance;
}
void client::displayClientInfo()
{
    cout<<"Account ID: "<<accID<<endl;
    cout<<"First name: "<<fname<<endl;
    cout<<"Last name: "<<lname<<endl;
    cout<<"Savings balance: $"<<savingsBalance<<endl;
    cout<<"Checking balance: $"<<checkingBalance<<endl;
    cout<<"\n";
}
void client::writeOutToFile()
{
    ofstream outfile;
    outfile.open("client.txt", ios::binary|ios::app);
    newClient();
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
    outfile.close();
}
void client::readFromFile()
{
    ifstream infile;
    infile.open("client.txt", ios::binary);
    cout<<"\n**********************************"
    	<<"\nViewing all client data From File."
    	<<"\n**********************************\n"<<endl;
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
        {
            displayClientInfo();
        }
    }
    infile.close();
}
void client::editClientInformatoin()
{
    int tempnum;
    fstream iofile;
    iofile.open("client.txt", ios::in|ios::binary);
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"\nEnter the Account ID of the client you would to edit: ";
    cin>>tempnum;
    iofile.seekg((tempnum-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    //cout<<"Client: "<<tempnum<<endl;
    cout<<"\nDisplaying account information of the client you selected:\n";
    displayClientInfo();
    iofile.close();
    iofile.open("client.txt", ios::out|ios::in|ios::binary);
    iofile.seekp((tempnum-1)*sizeof(*this));
    cout<<"\nRe-enter the data you want to modify. "
        <<"\nIf you do not want to change the value of something"
        <<"\nRe-enter it the same way as you did above.\n"<<endl;
    newClient();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void client::deleteClientFromFile()
{
    int tempnum;
    ifstream infile;
    infile.open("client.txt", ios::binary);
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\nEnter the account ID of the client you wish to delete: ";
    cin>>tempnum;
    fstream tmpfile;
    tmpfile.open("tempstoragefile.txt", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(tempnum-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("client.txt");
    rename("tempstoragefile.txt", "client.txt");
}
