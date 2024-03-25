#ifndef __CAPACITY_H__
#define __CAPACITY_H__

#include<iostream>
#include<string>

using namespace std;

class Capacity
{
public:
	Capacity();
	int get_x();
	int get_y();
	void set_place(int X, int Y);
	int get_HP();
	void set_HP();
	void set_HP(int hp);
	int get_ATK();
	void set_ATK();
	void set_ATK(int atk);
private:
	int x;
	int y;
	int HP;
	int ATK;
};

#endif
