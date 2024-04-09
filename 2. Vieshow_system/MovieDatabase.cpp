// MovieDatabase.cpp
// Member-function definitions for class MovieDatabase
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace::std;
#include "MovieDatabase.h" // MovieDatabase class definition

extern char hours[17][8];

// MovieDatabase default constructor loads movies from the file Movies.dat
MovieDatabase::MovieDatabase()
{
	loadMovies();
}

// MovieDatabase destructor saves movies into the file Movies.dat
MovieDatabase::~MovieDatabase()
{
	saveMovies();
}

int MovieDatabase::getNumMovies()
{
	return movies.size();
}

Movie MovieDatabase::getMovie(int movieCode)
{
	return movies[movieCode];
}

void MovieDatabase::setMovieSeat(int movieCode, int dateCode, int sessionTimeCode, int row, int col)
{
	movies[movieCode].setOccupiedSeat(dateCode, sessionTimeCode, row, col);
}

void MovieDatabase::displaySessionTimes(char movieNames[][60], char availableDates[][12])
{
	for (int i = 0; i < movies.size(); i++)
	{
		cout << setw(2) << i << "." << " Movie: " << movieNames[i] << endl;
		cout << setw(3) << " " << " Date:";
		for (int j = 0; j < 4; j++)
		{
				cout << setw(3) << j << ". " << availableDates[j] << ", ";
		}
		cout << endl << setw(3) << " " << " Session Time:";
		for (int j = 0; j < 17; j++)
		{
			if (movies[i].getSessionTime(j) == 1)
				cout << setw(3) << j << ". " << hours[j] << ",";
		}
		cout << endl << endl;
	}
}

void MovieDatabase::loadMovies()
{
	ifstream inMovieFile;
	inMovieFile.open("Movies.dat", ios::binary);
	if (!inMovieFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}

	while (inMovieFile && inMovieFile.peek() != EOF)
	{
		Movie newMovie;
		inMovieFile.read(reinterpret_cast< char * >(&newMovie), sizeof(Movie));
		movies.push_back(newMovie);
	}
	inMovieFile.close();
}

void MovieDatabase::saveMovies()
{
	ofstream outMovieFile;
	outMovieFile.open("Movies.dat", ios::out | ios::binary);
	if (!outMovieFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	for (int i = 0; i < movies.size(); i++)
    {
        outMovieFile.write(reinterpret_cast<const char *>(&movies[i]), sizeof(Movie));
    }
	outMovieFile.close();
}