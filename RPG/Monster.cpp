#include"Monster.h"
#include "Map.h"
#include <time.h>
#define rand_number(low,high) rand()%((high)-(low)+1)+(low);

Monster::Monster()
{

}
void Monster::set_monster(Map &now)
{
	int n[2];
	while (1)
	{
		srand((unsigned)time(NULL)); //該算法使用一個種子來生成序列，應該使用函數將其初始化為一些獨特的值函數srand。
		for (int i = 0; i < 2; i++)
			n[i] = rand_number(1, 8);
		if (now.get_road(n[0], n[1]) == ' ')
			break;
	}
	now.set_road(n[0], n[1], 'M',*this);
	set_HP(70);
	set_ATK(20);
}