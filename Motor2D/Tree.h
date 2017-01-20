#ifndef _TREE_H_
#define _TREE_H_

#include "Sprite2D.h"
#include "Entity.h"

enum WindDirection
{
	east,
	west,
	no_wind
};

class Tree : public Entity
{
public:
	Tree(iPoint position, const char* entity_name, int speed);

	~Tree();

	bool Update(float dt);

	bool Draw();

public:
	int speed = 0;
	int wind_force = 0;
	WindDirection wind_direction = no_wind;

};
#endif // !_TREE_H_