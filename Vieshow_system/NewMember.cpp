// NewMember.cpp
// Member-function definitions for class NewMember
#include <iostream>
#include <fstream>
#include "NewMember.h" // NewMember class definition

NewMember::NewMember(MemberDatabase &theMemberDatabase)
	: memberDatabase(theMemberDatabase)
{
}

void NewMember::execute()
{
	string newID;
	string newName;
	string newEmail;
	string newPassword;
	string newPhone;
	cout << "Enter your ID number: ";
	cin >> newID;
	if (memberDatabase.existingId(newID) == false)
	{
		cout << "Enter your name: ";
		cin >> newName;
		cout << "Enter an email address: ";
		cin >> newEmail;
		if(memberDatabase.existingEmail(newEmail) == false)
		{
			cout << "Enter a password: ";
			cin >> newPassword;
			cout << "Enter your phone number: ";
			cin >> newPhone;
			cout << endl << "Successful!" << endl << endl;
			Member newMember(newEmail, newPassword, newID,newName, newPhone);
			memberDatabase.addMember(newMember);
		}
	}
}