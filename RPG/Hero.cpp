#include "Hero.h"
#include "Map.h"
#include"Monster.h"

Hero::Hero()
{
	bool check = false;
	string okay;
	while (!check)
	{
		system("cls");
		cout << "Please give capability!" << endl;

		cout << "Name: ";
		cin >> name;

		cout << "HP: ";
		set_HP();

		cout << "ATK: ";
		set_ATK();

		cout << "OK? (y/n)";
		cin >> okay;
		if (okay.compare("y") == 0)
			check = true;
	}
	set_place(3, 2);
}
string Hero::get_name()
{
	return name;
}
bool Hero::get_win()
{
	return win;
}
void Hero::move(Map& now, Monster *monster)
{
	int c[2]{};
	choice(c);

	now.set_road(get_x(), get_y(), ' ', *this);

	if (now.get_road(c[0], c[1]) == 'G')
		win = true;
	else if (now.get_road(c[0], c[1]) == 'M')
		for (int i = 0; i < 3; i++)
		{
			if (c[0] == monster[i].get_x() && c[1] == monster[i].get_y())
				fight(monster[i]);
		}
	else if (c[0] == 1 && c[1] == 2 && now.get_road(c[0], c[1]) == 'F')
	{
		now.set_road(4, 4, '#');
		now.set_road(1, 3, '#');
		now.set_road(3, 3, ' ');
		now.set_road(5, 3, ' ');
		set_HP(get_HP()*1.5);
		set_ATK(get_ATK()*1.5);
	}
	else if (c[0] == 1 && c[1] == 7 && now.get_road(c[0], c[1]) == 'F')
	{
		now.set_road(3, 2, '#');
		now.set_road(6, 7, ' ');
		set_HP(get_HP() / 2);
		set_ATK(get_ATK() / 2);
	}
	else if (c[0] == 5 && c[1] == 5 && now.get_road(c[0], c[1]) == 'F')
		set_HP(0);
	else if (c[0] == 7 && c[1] == 1 && now.get_road(c[0], c[1]) == 'F')
	{
		now.set_road(6, 1, '#');
		now.set_road(4, 1, ' ');
		now.set_road(1, 3, ' ');
		set_HP(get_HP() - 50);
		set_ATK(get_ATK() - 50);
	}

	if (now.get_road(c[0], c[1]) == '8' || now.get_road(c[0], c[1]) == '#')
		now.set_road(get_x(), get_y(), 'H', *this);
	else
		now.set_road(c[0], c[1], 'H', *this);

}
void Hero::choice(int* c)
{
	cout << "Move (w/a/s/d) :";
	char choice[15]{};
	cin >> choice;
	switch (choice[0])
	{
	case 'w':
		c[0] = get_x();
		c[1] = get_y() - 1;
		break;
	case's':
		c[0] = get_x();
		c[1] = get_y() + 1;
		break;
	case'a':
		c[0] = get_x() - 1;
		c[1] = this->get_y();
		break;
	case'd':
		c[0] = get_x() + 1;
		c[1] = this->get_y();
		break;
	default:
		break;
	}
}
void Hero::fight(Monster &monster)
{
	while (monster.get_HP() > 0 && get_HP() > 0)
	{
		set_HP(get_HP() - monster.get_ATK());
		monster.set_HP(monster.get_HP() - get_ATK());
	}
}