#include <iostream>
#include <string>
using namespace std;
 
//Base class for person
class person
{
    protected:
    	string fname;
		string lname;
	private:
		string dateOfBirthMonth;
		string dateOfBirthDay;
		string dateOfBirthYear;
		int answer;
    public:
        void getBasicInfo(void);
        void putBasicInfo(void);
};
 
//function definitions
void person::getBasicInfo(void)
{
    cout << "What is your first name?: ";    
	cin >> fname >> lname;
    cout <<"When were you born? (Enter as MM DD YY do not put slashes.): ";
    cin >> dateOfBirthMonth >> dateOfBirthDay >> dateOfBirthYear;
}
 
void person::putBasicInfo(void)
{
    cout << "\nName: " << fname << " " << lname << endl;
    cout << "Date of birth: " << dateOfBirthMonth << "/" << dateOfBirthDay << "/" << dateOfBirthYear << endl;
}
 
//Derived class for students
class print_info:public person
{
    private:
        double gpa;
        int totalCredits;
        string startDateMonth;
        string startDateDay;
        string startDateYear;
        string graduationDateMonth;
        string graduationDateDay;
        string graductionDateYear;
        
    public:
        void getResultInfo(void);
        void putResultInfo(void);
};
 
//function to ask the user about the student
void print_info::getResultInfo(void)
{
    cout << "\nEnter the student's GPA: ";
	cin >> gpa;
	cout << "Enter the students total class credits: ";
	cin >> totalCredits;
	cout <<"Enter the students start date (Enter as MM DD YY do not put slashes.): ";
	cin >> startDateMonth >> startDateDay >> startDateYear;
	cout <<"Enter the students graduation date (Enter as MM DD YY do not put slashes.): ";
	cin >> graduationDateMonth >> graduationDateDay >> graductionDateYear;
}

//print function for student
void print_info::putResultInfo(void)
{
    cout <<"\nStudents GPA: " <<gpa;
    cout <<"\nStudents Total Class Credits: " <<totalCredits;
    cout <<"\nStudents Start Date: " << startDateMonth << "/" << startDateDay << "/" << startDateYear <<endl;
    cout <<"Students Graducation Date: " << graduationDateMonth << "/" << graduationDateDay << "/" << graductionDateYear <<endl;
}

int main()
{
    int answer;
    answer = 0;
    print_info std;
    std.getBasicInfo();
    
    cout << "Is this person a student or is this person facility of the university? (Put 1 for student, put 2 for facility): ";
    cin >>answer; 
    int i;
    i = 1;
    
while (i < 2)
{

    switch(answer) 
	{
    	case 1 :
    		cout << "This person is a student.";
    		std.getResultInfo();
    		std.putBasicInfo();
    		std.putResultInfo();
    		i = i + 1;
    		break;
    		
    	case 2 :
    		{
    			cout << "This part of the program will be finished in phase 2. \n";
				i = i + 1;
				break;
			}
		
		default:
			cout <<"\nInvalid selection please try again.";
			break;
	}
	i = i + 1;
}
			
	system("PAUSE");	
    return 0;
}
