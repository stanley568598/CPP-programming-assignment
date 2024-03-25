#include "Capacity.h"

Capacity::Capacity()
{
}
int Capacity::get_x()
{
	return x;
}
int Capacity::get_y()
{
	return y;
}
void Capacity::set_place(int X, int Y)
{
	x = X;
	y = Y;
}

int Capacity::get_HP()
{
	return HP;
}
void Capacity::set_HP()
{
	cin >> HP;
}
void Capacity::set_HP(int hp)
{
	HP = hp;
}

int Capacity::get_ATK()
{
	return ATK;
}
void Capacity::set_ATK()
{
	cin >> ATK;
}
void Capacity::set_ATK(int atk)
{
	ATK = atk;
}