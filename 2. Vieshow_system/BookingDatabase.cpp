// BookingDatabase.cpp
// Member-function definitions for class BookingDatabase
#include <iostream>
#include <fstream>
#include<iomanip>
#include "BookingDatabase.h" // BookingDatabase class definition

extern char hours[17][8];
extern char movieNames[30][60];
extern char availableDates[10][12];

// BookingDatabase default constructor loads bookings from the file Bookings.dat
BookingDatabase::BookingDatabase()
{
	loadBookings();
}

// BookingDatabase destructor saves bookings into the file Bookings.dat
BookingDatabase::~BookingDatabase()
{
	saveBookings();
}

void BookingDatabase::addBooking(Booking newBooking)
{
	bookings.push_back(newBooking);
}

// retrieve Booking object containing specified email
bool BookingDatabase::existingBooking(string email)
{
	return (bookings.size() != 0);
} // end function existingBooking

void BookingDatabase::displayBookings(string email, MovieDatabase &movieDatabase)
{
	if (existingBooking(email) == false)
		cout << "No bookings!" << endl;
	else
	{
		cout << "Booking History :" << endl;
		for (int i = 0; i < bookings.size(); i++)
			if (email.compare(bookings[i].getEmail()) == 0)
			{
				cout << "\nMovie: " << movieNames[bookings[i].getMovieCode()] << endl;
				cout << "Date : " << availableDates[bookings[i].getDateCode()] << endl;
				cout << "Show Time : " << hours[bookings[i].getSessionTimeCode()] << endl;
				cout << "Seats : ";
				for (int j = 0; j < bookings[i].getNumTickets(0) + bookings[i].getNumTickets(1) + bookings[i].getNumTickets(2) + bookings[i].getNumTickets(3); j++)
					cout << setw(4) << left << bookings[i].getSeletedSeat(j);
				cout << endl << endl;

				bookings[i].displayBooking(movieDatabase);
			}
	}
}

void BookingDatabase::loadBookings()
{
	ifstream inBookingFile;
	inBookingFile.open("Bookings.dat", ios::binary);
	if (!inBookingFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	
	while (inBookingFile && inBookingFile.peek() != EOF)
	{
		bookings.push_back(Booking());
		inBookingFile.read(reinterpret_cast< char * >(&bookings[bookings.size()-1]), sizeof(Booking));
	}
	inBookingFile.close();
}

void BookingDatabase::saveBookings()
{
	ofstream outBookingFile;
	outBookingFile.open("Bookings.dat", ios::out | ios::binary);
	if (!outBookingFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	for (int i = 0; i <bookings.size(); i++)
		outBookingFile.write(reinterpret_cast< const char * >(&bookings[i]), sizeof(Booking));
	outBookingFile.close();
}