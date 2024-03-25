#include "Hero.h"
#include "Map.h"
#include"Monster.h"

Map::Map()
{

}
char Map::get_road(int x, int y)
{
	return map[y][x];
}
void Map::set_road(int x, int y, char input)
{
	map[y][x] = input;
}
void Map::set_road(int x, int y, char input,Hero& object)
{
	map[y][x] = input;
	object.set_place(x, y);
}
void Map::set_road(int x, int y, char input, Monster& object)
{
	map[y][x] = input;
	object.set_place(x, y);
}
void Map::draw(Hero &player)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << map[i][j];
		if (i == 1)
			cout << setw(4) << ' ' << setw(5) << left << "Name" << ": " << player.get_name();
		else if (i == 2)
			cout << setw(4) << ' ' << setw(5) << left << "HP" << ": " << player.get_HP();
		else if (i == 3)
			cout << setw(4) << ' ' << setw(5) << left << "ATK" << ": " << player.get_ATK();
		else if (i == 5)
			cout << setw(4) << ' ' <<"H為英雄 M為怪物";
		else if (i == 6)
			cout << setw(4) << ' ' <<"F為命運 G為終點";
		else if (i == 7)
			cout << setw(4) << ' ' << "#為圍牆 8為邊界";
		cout << endl;
	}
}