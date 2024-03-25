// BuyTickets class definition
#ifndef __BUY_TICKETS_H__
#define __BUY_TICKETS_H__

#include "MovieDatabase.h"   // MovieDatabase class definition
#include "BookingDatabase.h" // BookingDatabase class definition

class BuyTickets
{
public:
	BuyTickets(MovieDatabase &theMovieDatabase, BookingDatabase &theBookingDatabase,
		string theEmail);

	void execute();

private:
	MovieDatabase &movieDatabase; // reference to MemberDatabase
	BookingDatabase &bookingDatabase; // reference to BookingDatabase
	char email[40];

	void selectSeats(Booking &newBooking);
}; // end class BuyTickets

#endif // BUY_TICKETS_H