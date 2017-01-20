#include "Tree.h"
#include "TreeCube.h"

Tree::Tree(iPoint position, const char* entity_name, int _speed) : Entity(EntityType::Tree, position, entity_name), speed(_speed)
{
}

Tree::~Tree()
{
}

bool Tree::Update(float dt)
{
	return true;
}

bool Tree::Draw()
{
	return true;
}

void Tree::StartGrowing()
{
	growing = true;
}

void Tree::CreateNewCube()
{
	// Set name
	p2SString name; name.create("TreeCube: %d", tree_cubes_list.count());
	
	// Create tree cube on the center point
	TreeCube* tree_cube = new TreeCube({ center_point_top.x - (tree_cube->info.GetAnim()->frames[0].w/2) ,center_point_top.y }, name.GetString());
	tree_cubes_list.add(tree_cube);
}
