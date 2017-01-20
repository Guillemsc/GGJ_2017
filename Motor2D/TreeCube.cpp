#include "TreeCube.h"

TreeCube::TreeCube(iPoint position, const char * entity_name) : Entity(tree_Cube, position, entity_name)
{
	//for (i = 0; i < 5; i++) {
	//	Sprite2D tmp(position.x + 55, position.y + 57);
	//	tree_cube_parts.add(tmp);
	//}
}

TreeCube::~TreeCube()
{
}

bool TreeCube::Update(float dt)
{
	return false;
}

bool TreeCube::Draw()
{
	return false;
}

int TreeCube::GetX()
{
	int ret = -1;

	if (tree_cube_parts.count() > 0)
		ret = tree_cube_parts[0].GetPos().x;
	
	return ret;
}

int TreeCube::GetY()
{
	int ret = -1;

	if (tree_cube_parts.count() > 0)
		ret = tree_cube_parts[0].GetPos().y;
	
	return ret;
}

int TreeCube::GetHeight()
{
	int ret = -1;

	if (tree_cube_parts.count() > 0)
		ret = tree_cube_parts[0].GetAnim()->frames[0].h * tree_cube_parts.count();

	return ret;
}

int TreeCube::GetWidth()
{
	int ret = -1;
	if (tree_cube_parts.count() > 0)
		ret = tree_cube_parts[0].GetAnim()->frames[0].w;
	
	return ret;
}

void TreeCube::SetPos(int x, int y)
{
	if (tree_cube_parts.count() > 0)
	{
		for (int i = 0; i < tree_cube_parts.count(); i++)
		{
			tree_cube_parts[i].SetPos(iPoint(x, y + (i * tree_cube_parts[0].GetAnim()->frames[0].h)));
		}
	}
}
