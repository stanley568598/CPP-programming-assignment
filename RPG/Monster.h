#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Capacity.h"

// #include "Map.h"

class Map;

class Monster:public Capacity
{
public:
	Monster();
	void set_monster(Map &now);
};

#endif
