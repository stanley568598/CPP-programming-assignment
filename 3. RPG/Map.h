#ifndef __MAP_H__
#define __MAP_H__

#include <iostream>
#include <iomanip>

using namespace std;

// #include "Map.h"
// #include "Monster.h"

class Hero;
class Monster;

class Map 
{
public:
	Map();
	char get_road(int x,int y);
	void set_road(int x, int y, char input);
	void set_road(int x, int y, char input, Hero& object);
	void set_road(int x, int y, char input, Monster& object);
	void draw(Hero& player);
private:
	char map[9][9]
	{
		{ '8','8','8','8','8','8','8','8','8' },
		{ '8',' ',' ',' ','#',' ',' ','F','8' },
		{ '8','F','#','H','#','G','#',' ','8' },
		{ '8',' ','#','#','#','#','#',' ','8' },
		{ '8',' ',' ',' ',' ',' ','#',' ','8' },
		{ '8',' ','#',' ','#','F',' ',' ','8' },
		{ '8',' ','#',' ','#',' ','#',' ','8' },
		{ '8','F','#',' ',' ',' ','#',' ','8' },
		{ '8','8','8','8','8','8','8','8','8' }
	};
};

#endif