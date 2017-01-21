#ifndef _TREE_H_
#define _TREE_H_

#include "Sprite2D.h"
#include "Entity.h"
#include "TreeCube.h"

class TreeCube;
class Flower;
class Branch;

enum WindDirection
{
	east,
	west,
	no_wind
};

class Tree : public Entity
{
public:
	Tree();
	Tree(iPoint starting_position, const char* entity_name);

	~Tree();

	void Set(int speed);

	bool Update(float dt);

	bool Draw();

	void StartGrowing();

	void CreateNewCube();
	void CreateNewFlower(int x, int y, p2SString _direction);
	void CreateNewBranch();

	void UpdateCenterPointTop();

	void MakeTreeGrow();

	int RandomGenerate(int x, int y);

	void LoadRects();

public:
	// Growing speed of the tree
	int speed = 0;

	int wind_force = 0;
	WindDirection wind_direction = no_wind;

	// List with tree cubes
	p2List<TreeCube*> tree_cubes_list;
	p2List<Flower*> flower_list;
	p2List<Branch*> branch_list;

	// Highest point on the tree
	iPoint center_point_top;

	// Distance to have the next tree cube
	int distance_next_treecube = 0;

	pugi::xml_document doc;
	SDL_Texture* texture = nullptr;

private:
	p2List<SDL_Rect> rects;
	bool growing = false;

	bool create_cube = true;
};
#endif // !_TREE_H_