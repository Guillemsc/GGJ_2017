#include "TreeCube.h"

TreeCube::TreeCube(iPoint position, const char * entity_name, p2List<SDL_Rect> rects) : Entity(tree_Cube, position, entity_name)
{
	for (int i = 0; i < rects.count(); i++)
	{
		CubePart cubepart(iPoint(position.x, position.y + (i*rects[i].h)), { rects[i].x, rects[i].y, rects[i].w, rects[i].h });
		tree_cube_parts.add(cubepart);
	}
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
		ret = tree_cube_parts[0].pos.x;
	
	return ret;
}

int TreeCube::GetY()
{
	int ret = -1;

	if (tree_cube_parts.count() > 0)
		ret = tree_cube_parts[0].pos.y;
	
	return ret;
}

int TreeCube::GetHeight()
{
	int ret = -1;

	if (tree_cube_parts.count() > 0)
		ret = tree_cube_parts[0].rect.h * tree_cube_parts.count();

	return ret;
}

int TreeCube::GetWidth()
{
	int ret = -1;
	if (tree_cube_parts.count() > 0)
		ret = tree_cube_parts[0].rect.w;
	
	return ret;
}

void TreeCube::SetPos(int x, int y)
{
	if (tree_cube_parts.count() > 0)
	{
		for (int i = 0; i < tree_cube_parts.count(); i++)
		{
			tree_cube_parts[i].pos.x = x;
			tree_cube_parts[i].pos.y = y + (i*tree_cube_parts[i].rect.h);
		}
	}
}
