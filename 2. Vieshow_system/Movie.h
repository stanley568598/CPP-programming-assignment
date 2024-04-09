// Movie class definition
#ifndef __MOVIE_H__
#define __MOVIE_H__

class Movie
{
public:
	Movie();

	void setMovieCode(int theMovieCode);
	int getMovieCode();
	void setPrices(int thePrices[]);
	int getPrice(int ticketType);
	void setDates(bool theDates[]);
	bool getDate(int dateCode);
	void setSessionTimes(bool theSessionTimes[]);
	bool getSessionTime(int sessionTimeCode);

	void setOccupiedSeat(int dateCode, int sessionTimeCode, int row, int col);
	bool getOccupiedSeat(int dateCode, int sessionTimeCode, int row, int col);

private:
	int movieCode;
	int prices[4]; // prices[0]:adult, prices[1]:concession, prices[2]:disability, prices[3]:elderly
	bool dates[4]; // dates[i] is true if and only if the movie is offered on i-th date
	bool sessionTimes[17];
	bool occupiedSeats[4][17][8][12]; // occupiedSeats[i][j] is the occupied Seats for all accounts
};                                    // at j-th session time on i-th date

#endif