#include <iostream>
#include "Hero.h"
#include "Map.h"
#include "Monster.h"

using namespace std;

void Execute();

int main()
{
	bool Check = false;
	while (Check == false)
	{
		cout << "RPG GAME" << endl;
		cout << "1. New Game" << endl;
		cout << "2. Exit" << endl;
		cout << "Your choice:";
		char choice[15];
		cin >> choice;
		cout << endl;
		switch (choice[0])
		{
			case '1':
				Check = true;
				Execute();
				break;
			case '2':
				Check = true;
				break;
			default:
				cout << "Input wrong！ please press any key to reboot！"<<endl << endl;
				system("pause");
				break;
		}
		system("cls");
	}
	cout << "Game Over"<<endl;
	system("pause");
}

void Execute()
{
	Hero player;
	Map newMap;
	Monster monster[3];
	for (int i = 0; i < 3; i++)
		monster[i].set_monster(newMap);
	
	while (1)
	{
		system("cls");
		newMap.draw(player);
		player.move(newMap, monster);
		if (player.get_win() == true)
		{
			system("cls");
			cout << "You Win !"<<endl;
			system("pause");
			break;
		}
		else if (player.get_HP() <= 0)
		{
			system("cls");
			cout << "You Lose !"<<endl;
			system("pause");
			break;
		}
	}
}


