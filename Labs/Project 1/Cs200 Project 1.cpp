#include<iostream>
#include<string> 
using namespace std; 

//rename Univeristy to person.
class Person
{
public:
	string fname;
	string lname;
	string dateOfBirthMonth;
	string dateOfBirthDay;
	string dateOfBirthYear;
	
	double gpa;
    int totalCredits;
    string startDateMonth;
    string startDateDay;
    string startDateYear;
    string graduationDateMonth;
    string graduationDateDay;
    string graductionDateYear;

	int workingStartDateMonth;
	int workingStartDateDay;
	int workingStartDateYear;
	string typeOfStaffMember;
	string staffTerminated;
	string workLocation;

	virtual void start()
	{
		    cout<<"Enter the persons first name: ";
			cin>>fname;
			cout<<"Enter the persons last name: ";
			cin>>lname;
			cout <<"When was this person born? (Enter as MM DD YY do not put slashes.): ";
 		    cin >> dateOfBirthMonth >> dateOfBirthDay >> dateOfBirthYear;	
	}
	virtual void printNameandDate()
	{
			cout << "\nName: " << fname << " " << lname << endl;
		    cout << "Date of birth: " << dateOfBirthMonth << "/" << dateOfBirthDay << "/" << dateOfBirthYear << endl;
	}
};
class student:public Person
{
	public:
        	virtual void userStudent()
		{
			cout<<"This user is a student. \n";
			cout << "\nEnter the student's GPA: ";
			cin >> gpa;
			cout << "Enter the students total class credits: ";
			cin >> totalCredits;
			cout <<"Enter the students start date (Enter as MM DD YY do not put slashes.): ";
			cin >> startDateMonth >> startDateDay >> startDateYear;
			cout <<"Enter the students graduation date (Enter as MM DD YY do not put slashes.): ";
			cin >> graduationDateMonth >> graduationDateDay >> graductionDateYear;
		}
			virtual void printStudent()
		{
			cout <<"\nStudents GPA: " <<gpa;
		    cout <<"\nStudents Total Class Credits: " <<totalCredits;
		    cout <<"\nStudents Start Date: " << startDateMonth << "/" << startDateDay << "/" << startDateYear <<endl;
		    cout <<"Students Graducation Date: " << graduationDateMonth << "/" << graduationDateDay << "/" << graductionDateYear <<endl;
		}
	
};
class staff:public Person
{
	public:
			virtual void userStaff()
		{
			cout <<"\nWhat is there job title: ";
			cin >>typeOfStaffMember;
			cout<<"What date did this staff member start working at the Uniersity: ";
			cin >> workingStartDateMonth >> workingStartDateDay >> workingStartDateYear;
			cout <<"Has this staff member been terminated (Enter yes or no)? : ";
			cin >> staffTerminated;
			cout <<"What building does this staff member work in (if off campus put online)? : ";
			cin >> workLocation;
		}
		virtual void printStaff()
		{
			cout <<"Job title: "<<typeOfStaffMember<<endl;
			cout <<"Staff members start date: " << workingStartDateMonth << "/" << workingStartDateDay<< "/" << workingStartDateYear << endl;
			cout <<"Has this staff member been terminated: "<<staffTerminated;
			cout <<"\nThis staff member works in the: " << workLocation <<endl;
			cout <<"\n";
		}
};

int main()
{
	int answer;
	int i;
	i = 1;
//For the univeristy class
	Person P;
	Person *ptr;
	ptr=&P;
	ptr->start();
//For the student class
	student S;
	student *S1;
	S1 = &S;
//For the staff class
	staff StaffMember;
	staff *S2;
	S2 = &StaffMember;

    cout << "Is this person a student or is this person facility of the university? (Put 1 for student, put 2 for facility): ";
    cin >>answer; 
    
	while (i < 2)
	{
		switch(answer)
		{
			case 1 :
				{
					S1->userStudent();
					system("CLS");
					cout<<"This user is a student and their information is: ";
					ptr->printNameandDate();
					S1->printStudent();
					break;
				}
			case 2:
				{
					S2->userStaff();
					system("CLS");
					cout<<"This user is a staff member and their information is: ";
					ptr->printNameandDate();
					S2->printStaff();
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
