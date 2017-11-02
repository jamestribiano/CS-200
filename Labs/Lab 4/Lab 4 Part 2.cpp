#include <iostream>
using namespace std;
//Temperature conveter. 

//Base class for person
class tempConvert
{
    public:
   		double inputTemp;
    protected:
    	double finalTemp;
};

//converting f to c 
class convertftoc:public tempConvert
{
	public:
	void ftoc(void);	
};
void convertftoc::ftoc()
{
	cout <<"\nInput the temperature that you are going to convert: ";
	cin >>inputTemp;
	finalTemp = (inputTemp-32)*5/9;
	cout <<"\nConverted temperature: " <<finalTemp<<" Degrees Celsius"<<endl;
	
}
//converting f to k
class convertftok:public tempConvert
{
	public:
	void ftok(void);	
};
void convertftok::ftok()
{
	cout <<"\nInput the temperature that you are going to convert: ";
	cin >>inputTemp;
	finalTemp = (inputTemp + 459.67) *5/9;
	cout <<"\nConverted temperature: " <<finalTemp<<" Kelvin"<<endl;
}
//converting c to f
class convertctof:public tempConvert
{
	public:
	void ctof(void);	
};
void convertctof::ctof()
{
	cout <<"\nInput the temperature that you are going to convert: ";
	cin >>inputTemp;
	finalTemp = (inputTemp * 9/5) + 32;
	cout <<"\nConverted temperature: " <<finalTemp<<" Degrees Fahrenheit"<<endl;
}
//converting c to k
class convertctok:public tempConvert
{
	public:
	void ctok(void);	
};
void convertctok::ctok()
{
	cout <<"\nInput the temperature that you are going to convert: ";
	cin >>inputTemp;
	finalTemp = (inputTemp * 9/5) + 32;
	cout <<"\nConverted temperature: " <<finalTemp<<" Degrees Kelvin"<<endl;
}
//converting k to f
class convertktof:public tempConvert
{
	public:
	void ktof(void);	
};
void convertktof::ktof()
{
	cout <<"\nInput the temperature that you are going to convert: ";
	cin >>inputTemp;
	finalTemp = (inputTemp * 9/5) - 459.67;
	cout <<"\nConverted temperature: " <<finalTemp<<" Degrees Fahrenheit"<<endl;
}
//converting k to c
class convertktoc:public tempConvert
{
	public:
	void ktoc(void);	
};
void convertktoc::ktoc()
{
	cout <<"\nInput the temperature that you are going to convert: ";
	cin >>inputTemp;
	finalTemp = (inputTemp - 273.15);
	cout <<"\nConverted temperature: " <<finalTemp<<" Degrees Celsius"<<endl;
}
//Main
int main()
{
	convertftoc temp1;
	convertftok temp2;
	convertctof temp3;
	convertktof temp4;
	convertktof temp5;
	convertktoc temp6;
	
	int answer;
	int i;
	
    cout <<"What temperature are you converting from?";
    cout <<"\n1. Fahrenheit to Celsius.";
    cout <<"\n2. Fahrenheit to Kelvins.";
    cout <<"\n3. Celsius to Fahrenheit.";
    cout <<"\n4. Celsius to Kelvins.";
    cout <<"\n5. Kelvins to Fahrenheit.";
    cout <<"\n6. Kelvins to Celsius.\n";
    cin >>answer;
    i = 1;
    
while(i < 2)
{
	switch (answer)
	{
		case 1 :
			{
				system("CLS");
				cout <<"You selected Fahrenheit to Celsius.";
				temp1.ftoc();
				i = i + 1;
				break;
			}
		case 2 :
			{
				system("CLS");
				cout <<"You selected Fahrenheit to Kelvins.";
				temp2.ftok();
				i = i + 1;
				break;
			}
		case 3 :
			{
				system("CLS");
				cout <<"You selected Celsius to Fahrenheit.";
				temp3.ctof();
				i = i + 1;
				break;
			}
		case 4 :
			{
				system("CLS");
				cout <<"You selected Celsius to Kelvins.";
				temp4.ktof();
				i = i + 1;
				break;
			}
		case 5 :
			{
				system("CLS");
				cout <<"You selected Kelvins to Fahrenheit.";
				temp5.ktof();
				i = i + 1;
				break;
			}
		case 6 :
			{
				system("CLS");
				cout <<"You selected Kelvins to Celsius.";
				temp6.ktoc();
				break;
			}
			
		default:
			cout <<"Invalid selection please try again.\n";
	}
	i = i + 1;
}
	system("PAUSE");
	return 0;
}
