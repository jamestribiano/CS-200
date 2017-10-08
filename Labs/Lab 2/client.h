//client.h
#include<string>

class client
{
		private:
		char accID[25];
        char fname[25];
        char lname[25];
        float savingsBalance;
        float checkingBalance;
        
		public:
			//Defualt constructor
			client();
			//overloaded constructors
			client(string, string);
			//Other functions
			void newClient();
	        void displayClientInfo();
	        void writeOutToFile();
	        void readFromFile();
	        void editClientInformatoin();
	        void deleteClientFromFile();
};	
