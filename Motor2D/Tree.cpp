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

void Tree::CreateNewFlower(int x, int y)
{
	// Set Name
	p2SString name; name.create("Flower: %d", flower_list.count());

	// Create flowers on a percentage
	int rand = RandomGenerate(0, 2); //0 don't create, 1 create in left, 2 create in rigth
	Flower* flower;

	switch (rand) {
	case 1: {
		flower = new Flower(iPoint(x, y), "flower_left");
	}
		break;
	case 2: {
		flower = new Flower(iPoint(x, y), "flower_right");
	}
		break;
	default:
		break;
	}

	if (rand != 0) flower_list.add(flower);

}

void Tree::CreateNewBranch()
{
	// Set Name
	p2SString name; name.create("Branch: %d", branch_list.count());

	// Create branchs on a random number
	int rand = RandomGenerate(0, 2); //0 don't create, 1 create in left, 2 create in rigth
	Branch* branch;
	int x, y = tree_cubes_list.end->data->GetY();

	switch (rand) {
	case 1:	{
		x = tree_cubes_list.end->data->GetX() - (tree_cubes_list.end->data->GetWidth() / 2);
		branch = new Branch(iPoint(x, y), "branch_left");
	}
		break;
	case 2: {
		x = tree_cubes_list.end->data->GetX() + (tree_cubes_list.end->data->GetWidth() / 2);
		branch = new Branch(iPoint(x, y), "branch_right");
	}
		break;
	default:
		break;
	}

	if (rand != 0) {
		branch_list.add(branch);
		CreateNewFlower(x, y);
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

int Tree::RandomGenerate(int x, int y)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> random(x, y);
	return random(gen);
}
