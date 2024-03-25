// MemberDatabase.cpp
// Member-function definitions for class MemberDatabase
#include <iostream>
#include <fstream>
#include "MemberDatabase.h" // MemberDatabase class definition

// MemberDatabase default constructor loads members from the file Members.dat
MemberDatabase::MemberDatabase()
{
	loadMembers();
}

// MemberDatabase destructor saves members into the file Members.dat
MemberDatabase::~MemberDatabase()
{
	saveMembers();
}

vector< Member >::iterator MemberDatabase::end()
{
	return members.end();
}

// retrieve Member object containing specified id
bool MemberDatabase::existingId(string id)
{
	for (int i = 0; i < members.size(); i++)
		if (id.compare(members[i].getIdNumber()) == 0)
		{
			cout << endl << "An account already exists with the ID number!" << endl << endl;
			return true;
		}
	return false;
} // end function existingId

  // retrieve Member object containing specified email
bool MemberDatabase::existingEmail(string email)
{
	for (int i = 0; i < members.size(); i++)
		if (email.compare(members[i].getEmail()) == 0)
		{
			cout << endl << "An account already exists with the e-mail!" << endl << endl;
			return true;
		}
	return false;
} // end function existingEmail

void MemberDatabase::addMember(Member newMember)
{
	members.push_back(newMember);
}

vector< Member >::iterator MemberDatabase::getMember(string email, string password)
{
	vector< Member >::iterator it = members.begin();
	for (; it != members.end(); ++it)
	{
		if (email.compare((*it).getEmail()) == 0)
			if (password.compare(it->getPassword()) == 0)
				return it;
	}
	return it;
}

void MemberDatabase::loadMembers()
{
	ifstream inMemberFile;
	inMemberFile.open("Members.dat", ios::binary);
	if (!inMemberFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	while (inMemberFile && inMemberFile.peek() != EOF)
	{
		members.push_back(Member());
		inMemberFile.read(reinterpret_cast< char * >(&members[members.size()-1]), sizeof(Member));
	}
	inMemberFile.close();
}

void MemberDatabase::saveMembers()
{
	ofstream outMemberFile;
	outMemberFile.open("Members.dat", ios::out | ios::binary);
	if (!outMemberFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	for (int i = 0; i <members.size(); i++)
		outMemberFile.write(reinterpret_cast< const char * >(&members[i]), sizeof(Member));
	outMemberFile.close();
}