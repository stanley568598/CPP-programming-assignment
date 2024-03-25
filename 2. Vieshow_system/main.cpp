#include <iostream>
#include <fstream>
#include <cmath>

using namespace::std;

#include "NewMember.h"     // NewMember class definition
#include "MemberDetails.h" // MemberDetails class definition
#include "BuyTickets.h"    // BuyTickets class definition

char hours[17][8] = { "09:00", "10:00", "11:00", "12:00", "13:00", "14:00", "15:00", "16:00", "17:00",
"18:00", "19:00", "20:00", "21:00", "22:00", "23:00", "00:00", "01:00" };
char movieNames[30][60];
char availableDates[10][12];
int numDates;

int inputAnInteger(int begin, int end);
void signIn(MemberDatabase &memberDatabase);
void loadMovieNames();
void loadAvailableDates();

int main()
{
	MemberDatabase memberDatabase;
	NewMember newMember(memberDatabase);

	cout << "Welcome to Vieshow Cinemas Taipei QSquare system\n\n";

	int choice;

	while (true)
	{
		cout << "Enter your choice:" << endl;
		cout << "1. Sign In\n";
		cout << "2. New Member\n";
		cout << "3. End\n? ";

		choice = inputAnInteger(1, 3);
		cout << endl;

		switch (choice)
		{
		case 1:
			signIn(memberDatabase);
			break;

		case 2:
			newMember.execute();
			break;

		case 3:
			cout << "Thank you...\n\n";
			system("pause");
			return 0;

		default:
			cout << "Input Error!\n\n";
			break;
		}
	}

	system("pause");
}

int inputAnInteger(int begin, int end)
{
	string input;
	cin >> input;

	if (input.length() == 0 || input.length() >= 3)
		return -1;

	int number = 0;
	for (unsigned int i = 0; i < input.length(); i++)
		if (input[i] < '0' || input[i] > '9')
			return -1;
		else
			number += (input[i] - '0')*pow(10, i);

	if (number >= begin && number <= end)
		return number;
	else
		return -1;
}

void signIn(MemberDatabase &memberDatabase)
{
	char email[40] = "";
	char password[24] = "";

	vector< Member >::iterator it;

	cout << "Enter email address: ";
	cin >> email;
	cout << "Enter password: ";
	cin >> password;
	cin.ignore();

	it = memberDatabase.getMember(email, password);
	if (it == memberDatabase.end())
	{
		cout << endl << "Sorry, unrecognized email or password." << endl << endl;
		return;
	}
	loadMovieNames();

	loadAvailableDates();

	MemberDetails memberDetails(memberDatabase);
	MovieDatabase movieDatabase;
	BookingDatabase bookingDatabase;
	BuyTickets buyTickets(movieDatabase, bookingDatabase, email);
	int choice;

	while (true)
	{
		cout << "\nEnter your choice:" << endl;
		cout << "1. Account Information\n";
		cout << "2. Buy Tickets\n";
		cout << "3. My Bookings\n";
		cout << "4. Sign Out\n? ";

		choice = inputAnInteger(1, 4);
		cout << endl;

		switch (choice)
		{
		case 1:
			memberDetails.execute(it);
			break;

		case 2:
			buyTickets.execute();
			break;

		case 3:
			bookingDatabase.displayBookings(email, movieDatabase);
			break;

		case 4:
			return;

		default:
			cout << "Input Error!\n";
			break;
		}
	}
}

void loadMovieNames()
{
	ifstream inFile("Movie Names.txt", ios::in);

	if (!inFile)
	{
		cout << "File \"Movie Names.txt\" could not be opened" << endl;
		system("pause");
		exit(1);
	}

	int i = 0;
	while (inFile.getline(movieNames[i], 60))
		i++;
}

void loadAvailableDates()
{
	ifstream inFile("Available Dates.txt", ios::in);

	if (!inFile)
	{
		cout << "File \"Available Dates.txt\" could not be opened" << endl;
		system("pause");
		exit(1);
	}

	int i = 0;
	while (inFile.getline(availableDates[i], 12))
		i++;

	numDates = i;
}