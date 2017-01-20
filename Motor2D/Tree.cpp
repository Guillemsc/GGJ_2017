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
	if (growing)
	{
		if(create_cube)
			CreateNewCube();

		UpdateCenterPointTop();
	}

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

// Creates a New Cube on the highest last cube
void Tree::CreateNewCube()
{
	// Set name
	p2SString name; name.create("TreeCube: %d", tree_cubes_list.count());
	
	TreeCube* tree_cube = nullptr;

		// Create tree cube on starting point
	if (tree_cubes_list.count() == 0)
		tree_cube = new TreeCube(iPoint(info.GetPos().x, info.GetPos().y), name.GetString());
	
	else
		// Create tree cube on the center point
		tree_cube = new TreeCube(iPoint(center_point_top.x - (tree_cubes_list.end->data->info.GetAnim()->frames[0].w / 2), center_point_top.y), name.GetString());

	tree_cubes_list.add(tree_cube);
}

// Update center_point_top
void Tree::UpdateCenterPointTop()
{
	if (tree_cubes_list.count() > 0)
	{
		center_point_top.x = tree_cubes_list.end->data->info.GetPos().x + (tree_cubes_list.end->data->info.GetAnim()->frames[0].w / 2);
		center_point_top.x = tree_cubes_list.end->data->info.GetPos().y;
	}
}

// Takes the cubes higher
void Tree::MakeTreeGrow()
{
	//tree_cubes_list.end->data->info.SetPos()
}
