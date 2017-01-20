#ifndef _TREE_H_
#define _TREE_H_

#include "Sprite2D.h"
#include "Entity.h"
#include "TreeCube.h"

class TreeCube;

enum WindDirection
{
	east,
	west,
	no_wind
};

class Tree : public Entity
{
public:
	Tree(iPoint starting_position, const char* entity_name, int speed);

	~Tree();

	bool Update(float dt);

	bool Draw();

	void StartGrowing();

	void CreateNewCube();

public:
	// Growing speed of the tree
	int speed = 0;

	int wind_force = 0;
	WindDirection wind_direction = no_wind;

	// List with tree cubes
	p2List<TreeCube*> tree_cubes_list;

	// Highest point on the tree
	iPoint center_point_top;

private:
	bool growing = false;
};
#endif // !_TREE_H_