#ifndef __HERO_H__
#define __HERO_H__

#include<iostream>

using namespace std;

#include "Capacity.h"

// #include "Map.h"
// #include "Monster.h"

class Map;
class Monster;

class Hero :public Capacity
{
public:
	Hero();
	string get_name();
	bool get_win();
	void move(Map& now, Monster* monster);
	void choice(int *c);
	void fight(Monster &monster);
private:
	string name;
	bool win = false;
};

#endif
