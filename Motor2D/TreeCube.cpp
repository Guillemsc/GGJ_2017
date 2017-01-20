#include "TreeCube.h"

TreeCube::TreeCube(iPoint position, const char * entity_name)
{
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
