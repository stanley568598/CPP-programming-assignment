// Booking.cpp
// Member-function definitions for class Booking
#include <iostream>
#include <iomanip>
#include "Booking.h" // Booking class definition

Booking::Booking()
{
}

void Booking::setEmail(string theEmail)
{
	int length = theEmail.size();
	length = (length < 40 ? length : 39);
	for (int i = 0; i < length; i++)
		email[i] = theEmail[i];
	email[length] = '\0';
}

string Booking::getEmail()
{
	return string(email);
}

void Booking::setMovieCode(int theMovieCode)
{
	movieCode = (theMovieCode > 0 ? theMovieCode : 0);
}

int Booking::getMovieCode()
{
	return movieCode;
}

void Booking::setDateCode(int theDateCode)
{
	dateCode = (theDateCode > 0 ? theDateCode : 0);
}

int Booking::getDateCode()
{
	return dateCode;
}

void Booking::setSessionTimeCode(int theSessionTimeCode)
{
	sessionTimeCode = (theSessionTimeCode > 0 ? theSessionTimeCode : 0);
}

int Booking::getSessionTimeCode()
{
	return sessionTimeCode;
}

void Booking::setNumTickets(int theNumTickets[])
{
	for (int i = 0; i < 4; i++)
		numTickets[i] = (theNumTickets[i] > 0 ? theNumTickets[i] : 0);
}

int Booking::getNumTickets(int ticketType)
{
	return numTickets[ticketType];
}

void Booking::setSeletedSeats(string theSeletedSeats[], int numSeats)
{
	for (int i = 0; i <= numSeats; i++)
	{
		seletedSeats[i][0] = theSeletedSeats[i][0];
		seletedSeats[i][1] = theSeletedSeats[i][1];
		seletedSeats[i][2] = theSeletedSeats[i][2];
	}
}

string Booking::getSeletedSeat(int number)
{
	return seletedSeats[number];
}

void Booking::displayBooking(MovieDatabase &movieDatabase)
{
	int total = 0;
	cout << "             No. of Tickets  Price  Subtotal" << endl;
	for (int i = 0; i<4; i++)
		if (numTickets[i] != 0)
		{
			switch (i)
			{
			case 0:
				cout << setw(20) << left << "Adult ticket";
				break;
			case 1:
				cout << setw(20) << left << "Concession ticket";
				break;
			case 2:
				cout << setw(20) << left << "Disability ticket";
				break;
			case 3:
				cout << setw(20) << left << "Elderly ticket";
				break;
			}
			cout << setw(7) << right << numTickets[i];
			cout << setw(7) << right << movieDatabase.getMovie(movieCode).getPrice(i);;
			cout << setw(10) << right << movieDatabase.getMovie(movieCode).getPrice(i) * numTickets[i];
			total += movieDatabase.getMovie(movieCode).getPrice(i) * numTickets[i];
			cout << endl;
		}

	cout << endl << "Total Amount For Tickets: " << total << endl;
}