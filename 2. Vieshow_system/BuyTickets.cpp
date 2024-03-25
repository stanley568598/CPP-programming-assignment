// BuyTickets.cpp
// Member-function definitions for class BuyTickets
#include <iostream>
#include <iomanip>
using namespace::std;
#include "BuyTickets.h" // BuyTickets class definition

extern char hours[17][8];
extern char movieNames[30][60];
extern char availableDates[10][12];
extern int numDates;
int inputAnInteger(int begin, int end);

// BuyTickets default constructor
BuyTickets::BuyTickets(MovieDatabase &theMovieDatabase, BookingDatabase &theBookingDatabase, string theEmail)
	: movieDatabase(theMovieDatabase),
	bookingDatabase(theBookingDatabase)
{
	int length = theEmail.size();
	for (int i = 0; i < length; i++)
		email[i] = theEmail[i];
	email[length] = '\0';
}

void BuyTickets::execute()
{
	movieDatabase.displaySessionTimes(movieNames,availableDates);
	cout << endl;
	int choice1;
	cout << "Enter movie code(0 - " << movieDatabase.getNumMovies() - 1 << ") : ";
	cin >> choice1;
	while (choice1 < 0 || movieDatabase.getNumMovies() - 1 < choice1)
	{
		cout << "Enter movie code(0 - " << movieDatabase.getNumMovies() - 1 << ") : ";
		cin >> choice1;
	}
	cout << endl;
	int choice2;
	cout << "Enter date code(0 - " << numDates - 1 << ") : ";
	cin >> choice2;
	while (choice2 < 0 || numDates - 1 < choice2 || movieDatabase.getMovie(choice1).getDate(choice2) == 0)
	{
		cout << "Enter date code(0 - " << numDates - 1 << ") : ";
		cin >> choice2;
	}
	cout << endl;
	int choice3;
	cout << "Enter session time code(0 - 16) : ";
	cin >> choice3;
	while (choice3 < 0 || 16 < choice3 || movieDatabase.getMovie(choice1).getSessionTime(choice3) == 0)
	{
		cout << "Enter session time code(0 - 16) : ";
		cin >> choice3;
	}
	cout << endl;
	cout << "Movie: " << movieNames[choice1] << endl;
	cout << "Date : " << availableDates[choice2] << endl;
	cout << "Show Time : " << hours[choice3] << endl;
	cout << "Price: Adult-270, Concession-270, Disability-160, Elderly-160" << endl;
	cout << endl;

	Booking newBooking;
	newBooking.setEmail(email);
	newBooking.setMovieCode(choice1);
	newBooking.setDateCode(choice2);
	newBooking.setSessionTimeCode(choice3);

	int choice[4];
	while (1)
	{
		cout << "Enter the number of adult tickets (0 - 6): ";
		cin >> choice[0];
		while (choice[0] < 0 || 6 < choice[0])
		{
			cout << "Enter the number of adult tickets (0 - 6): ";
			cin >> choice[0];
		}

		cout << "Enter the number of concession tickets (0 - 6): ";
		cin >> choice[1];
		while (choice[1] < 0 || 6 < choice[1])
		{
			cout << "Enter the number of concession tickets (0 - 6): ";
			cin >> choice[1];
		}

		cout << "Enter the number of disability tickets (0 - 6): ";
		cin >> choice[2];
		while (choice[2] < 0 || 6 < choice[2])
		{
			cout << "Enter the number of disability tickets (0 - 6): ";
			cin >> choice[2];
		}

		cout << "Enter the number of elderly tickets (0 - 6): ";
		cin >> choice[3];
		while (choice[3] < 0 || 6 < choice[3])
		{
			cout << "Enter the number of elderly tickets (0 - 6): ";
			cin >> choice[3];
		}

		if (choice[0] == 0 && choice[1] == 0 && choice[2] == 0 && choice[3] == 0)
			cout << endl;
		else
		{
			cout << endl;
			break;
		}
	}
	newBooking.setNumTickets(choice);
	newBooking.displayBooking(movieDatabase);
	selectSeats(newBooking);
	bookingDatabase.addBooking(newBooking);
}

void BuyTickets::selectSeats(Booking &newBooking)
{
	int numtickets = newBooking.getNumTickets(0) + newBooking.getNumTickets(1) + newBooking.getNumTickets(2) + newBooking.getNumTickets(3);
	cout << "  A B C D E F G H I J K L" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 12; j++)
			cout << movieDatabase.getMovie(newBooking.getMovieCode()).getOccupiedSeat(newBooking.getDateCode(), newBooking.getSessionTimeCode(), i, j) << " ";
		cout << endl;
	}
	cout << endl;
	cout << "Select " << numtickets << " seats(e.g. 0A) :" << endl;
	string input[24];
	for (int i = 0; i < numtickets; i++)
	{
		cout << "?";
		cin >> input[i];
		input[i][2] = '\0';
		int column = input[i][0] - '0';
		int row = input[i][1] - 'A';
		if (column < 0 || column>7 || row < 0 || row>11)
		{
			cout << "Wrong Input. Please select again." << endl;
			i--;
		}
		else
			if (movieDatabase.getMovie(newBooking.getMovieCode()).getOccupiedSeat(newBooking.getDateCode(), newBooking.getSessionTimeCode(), column, row) == 0)
			{
				movieDatabase.setMovieSeat(newBooking.getMovieCode(), newBooking.getDateCode(), newBooking.getSessionTimeCode(), column, row);
				newBooking.setSeletedSeats(input,i);
			}
			else
			{
				cout << "This seat bas been occupied. Please select another seat." << endl;
				i--;
			}
	}
	cout << endl << "Successful!" << endl;
}