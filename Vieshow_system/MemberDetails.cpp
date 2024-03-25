// MemberDetails.cpp
// Member-function definitions for class MemberDetails
#include <iostream>
using namespace std;
#include "MemberDetails.h" // MemberDetails class definition

int inputAnInteger(int begin, int end);

MemberDetails::MemberDetails(MemberDatabase &theMemberDatabase)
	: memberDatabase(theMemberDatabase)
{
}

void MemberDetails::execute(vector< Member >::iterator it)
{
	cout << "1. Name: " << it->getName() << endl;
	cout << "2. Email Address: " << it->getEmail() << endl;
	cout << "3. Phone Number: " << it->getPhone() << endl;
	cout << "4. ID Number: " << it->getIdNumber() << endl;
	cout << "5. Password: " << it->getPassword() << endl;

	int modify;
	cout << endl;
	cout << "Which one do you want to modify (0 ¡V not modify)? ";
	string modifyData;
	bool stop = false;
	while (stop == false)
	{
		cin >> modify;
		switch (modify)
		{
		case 0:
			stop = true;
			break;

		case 1:
			cout << "Enter correct data: ";
			cin >> modifyData;
			it->setName(modifyData);
			cout << endl << "Successful!" << endl;
			stop = true;
			break;

		case 2:
			cout << "Enter correct data: ";
			char email[40];
			cin >> email;
			while (memberDatabase.existingEmail(email))
			{
				cout << "Enter correct data: ";
				cin >> email;
			}
			it->setEmail(email);
			cout << endl << "Successful!" << endl;
			stop = true;
			break;

		case 3:
			cout << "Enter correct data: ";
			cin >> modifyData;
			it->setPhone(modifyData);
			cout << endl << "Successful!" << endl;
			stop = true;
			break;

		case 4:
			cout << "Enter correct data: ";
			char IDNumber[12];
			cin >> IDNumber;
			while (memberDatabase.existingId(IDNumber))
			{
				cout << "Enter correct data: ";
				cin >> IDNumber;
			}
			it->setIdNumber(IDNumber);
			cout << endl << "Successful!" << endl;
			stop = true;
			break;

		case 5:
			cout << "Enter correct data: ";
			cin >> modifyData;
			it->setPassword(modifyData);
			cout << endl << "Successful!" << endl;
			stop = true;
			break;

		default:
			cout << endl << "Input Error!   Please try again: ";
			break;
		}
	}
}