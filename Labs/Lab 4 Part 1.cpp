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
      //  string fname;
		//string lname;
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
//staff class with nothing declared
class staff:public print_info
{
	private:
		int workingStartDateMonth;
		int workingStartDateDay;
		int workingStartDateYear;
		string typeOfStaffMember;
		string staffTerminated;
		string workLocation;
		
	public:
		void getStaffMemberType(void);
		void printStaffInfo(void);
};
//asks the user what kind of staff member they are if selected.
void staff::getStaffMemberType(void)
{
	cout <<"\nWhat is there job title: ";
	cin >>typeOfStaffMember;
	cout<<"When did this staff member start working at the Uniersity: ";
	cin >> workingStartDateMonth >> workingStartDateDay >> workingStartDateYear;
	cout <<"Has this staff member been terminated (Enter yes or no)? : ";
	cin >> staffTerminated;
	cout <<"What building does this staff member work in (if off campus put online)? : ";
	cin >> workLocation;
}

//print function for student
void print_info::putResultInfo(void)
{
    cout <<"\nStudents GPA: " <<gpa;
    cout <<"\nStudents Total Class Credits: " <<totalCredits;
    cout <<"\nStudents Start Date: " << startDateMonth << "/" << startDateDay << "/" << startDateYear <<endl;
    cout <<"Students Graducation Date: " << graduationDateMonth << "/" << graduationDateDay << "/" << graductionDateYear <<endl;
}

//print function for staff
void staff::printStaffInfo(void)
{
	cout <<"Job title: "<<typeOfStaffMember<<endl;
	cout <<"Staff members start date: " << workingStartDateMonth << "/" << workingStartDateDay<< "/" << workingStartDateYear << endl;
	cout <<"Has this staff member been terminated: "<<staffTerminated;
	cout <<"This staff member works in the: " << workLocation << " building" <<endl;
	cout <<"\n";
}
 
int main()
{
    int answer;
    answer = 0;
	//create object of derived class (std is like st1 in other programs)
    print_info std;
 	staff std1;
    //read student basic and result information
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
    			cout << "This person is a facility member.";
				std1.getStaffMemberType();
				std.putBasicInfo();
				std1.printStaffInfo();
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
