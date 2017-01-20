#include "Tree.h"
#include "TreeCube.h"
#include "Flower.h"
#include "Branch.h"
#include <random>
#include <iostream>
using namespace std;

Tree::Tree()
{
}

Tree::Tree(iPoint position, const char* entity_name, int _speed) : Entity(EntityType::tree, position, entity_name), speed(_speed)
{
}

Tree::~Tree()
{
}

bool Tree::Update(float dt)
{
	if (growing)
	{
		if (create_cube)
		{
			CreateNewCube();
			distance_next_treecube = center_point_top.y - tree_cubes_list.end->data->info.GetAnim()->frames[0].h;
			create_cube = false;
		}

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

void Tree::CreateNewFlower()
{
	// Set Name
	p2SString name; name.create("Flower: %d", flower_list.count());

	// Create flowers on a percentage
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> random(0, 2); //0 don't create, 1 create in left, 2 create in rigth
	int rand = random(gen);

	switch (rand) {
	case 1: {
		Flower* flower = new Flower(iPoint(tree_cubes_list.end->data->info.GetPos().x - (tree_cubes_list.end->data->info.GetAnim()->frames[0].w / 2), tree_cubes_list.end->data->info.GetPos().y), "flower_left");
	}
		break;
	case 2: {
		Flower* flower = new Flower(iPoint(tree_cubes_list.end->data->info.GetPos().x + (tree_cubes_list.end->data->info.GetAnim()->frames[0].w / 2), tree_cubes_list.end->data->info.GetPos().y), "flower_right");
	}
		break;
	default:
		break;
	}

}

void Tree::CreateNewBranch()
{
	// Set Name
	p2SString name; name.create("Branch: %d", branch_list.count());

	// Create branchs on a percentage
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> random(0, 2); //0 don't create, 1 create in left, 2 create in rigth
	int rand = random(gen);

	switch (rand) {
	case 1:	{
		Branch* branch = new Branch(iPoint(tree_cubes_list.end->data->info.GetPos().x - (tree_cubes_list.end->data->info.GetAnim()->frames[0].w / 2), tree_cubes_list.end->data->info.GetPos().y), "branch_left");
	}
		break;
	case 2: {
		Branch* branch = new Branch(iPoint(tree_cubes_list.end->data->info.GetPos().x + (tree_cubes_list.end->data->info.GetAnim()->frames[0].w / 2), tree_cubes_list.end->data->info.GetPos().y), "branch_right");
	}
		break;
	default:
		break;
	}
}

// Update center_point_top
void Tree::UpdateCenterPointTop()
{
	if (tree_cubes_list.count() > 0)
	{
		center_point_top.x = tree_cubes_list.end->data->info.GetPos().x + (tree_cubes_list.end->data->info.GetAnim()->frames[0].w / 2);
		center_point_top.y = tree_cubes_list.end->data->info.GetPos().y;
	}
}

// Takes the cubes higher
void Tree::MakeTreeGrow()
{
	// Update position of the last treecube
	tree_cubes_list.end->data->info.SetPos(iPoint(tree_cubes_list.end->data->info.GetPos().x, tree_cubes_list.end->data->info.GetPos().y - speed));
	
	// Check if we have to create another treecube
	if (tree_cubes_list.end->data->info.GetPos().y <= distance_next_treecube) 
	{
		create_cube = true;
	}
}
