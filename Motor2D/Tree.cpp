#include "Tree.h"
#include "TreeCube.h"
#include "Flower.h"
#include "Branch.h"
#include <random>
#include <iostream>
#include "j1FileSystem.h"
using namespace std;

Tree::Tree()
{
}

Tree::Tree(iPoint position, const char* entity_name) : Entity(EntityType::tree, position, entity_name)
{
}

Tree::~Tree()
{
	while (tree_cubes_list.count()) {
		RELEASE(tree_cubes_list.end->data);
		tree_cubes_list.del(tree_cubes_list.end);
	}
	while (branch_list.count()) {
		RELEASE(branch_list.end->data);
		branch_list.del(branch_list.end);
	}
	while (flower_list.count()) {
		RELEASE(flower_list.end->data);
		flower_list.del(flower_list.end);
	}
}

void Tree::Set(int _speed)
{
	speed = _speed;
	App->LoadXML("tree_cube.xml", doc);
	LoadRects();
}

bool Tree::Update(float dt)
{
	for (int i = 0; i < tree_cubes_list.count(); i++)
	{
		tree_cubes_list[i]->Update(dt);
		tree_cubes_list[i]->Draw();
	}
		
	if (growing)
	{
		if (create_cube)
		{
			CreateNewCube();
			distance_next_treecube = center_point_top.y - tree_cubes_list.end->data->GetHeight();
			create_cube = false;
		}

		UpdateCenterPointTop();
		MakeTreeGrow();
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
	p2SString name("tree_cube");

	TreeCube* tree_cube = nullptr;

		// Create tree cube on starting point
	if (tree_cubes_list.count() == 0)
	{
		tree_cube = new TreeCube(iPoint(info.GetPos().x, info.GetPos().y), name.GetString(), rects, texture);
		center_point_top.y = info.GetPos().y;
	}
	else
		// Create tree cube on the center point
		tree_cube = new TreeCube(iPoint(center_point_top.x - (tree_cubes_list.end->data->GetWidth() / 2), center_point_top.y), name.GetString(), rects, texture);

	if(tree_cube!= nullptr)
		tree_cubes_list.add(tree_cube);

}

void Tree::CreateNewFlower(int x, int y, p2SString _direction)
{
	// Set Name
	p2SString name; name.create("flower");

	// Create flowers on a percentage
	int rand = RandomGenerate(0, 1); // 0 No create, 1 Create

	if (rand != 0) {
		Flower* flower = new Flower(iPoint(x, y), name.GetString());
		flower->ChangeDirection(_direction.GetString());
		flower_list.add(flower);
	}
}

void Tree::CreateNewBranch()
{
	// Set Name
	p2SString name; name.create("branch");

	// Create branchs on a random number
	int rand = RandomGenerate(0, 2); //0 don't create, 1 create in left, 2 create in rigth
	Branch* branch;
	p2SString _direction;
	int x, y = tree_cubes_list.end->data->GetY();

	switch (rand) {
	case 1:	{
		x = tree_cubes_list.end->data->GetX() - (tree_cubes_list.end->data->GetWidth() / 2);
		branch = new Branch(iPoint(x, y), name.GetString());
		_direction.create("left");
		branch->ChangeDirection(_direction.GetString());
	}
		break;
	case 2: {
		x = tree_cubes_list.end->data->GetX() + (tree_cubes_list.end->data->GetWidth() / 2);
		branch = new Branch(iPoint(x, y), name.GetString());
		_direction.create("right");
		branch->ChangeDirection(_direction.GetString());
	}
		break;
	default:
		break;
	}

	if (rand != 0) {
		branch_list.add(branch);
		CreateNewFlower(x, y, _direction.GetString());
	}
}

// Update center_point_top
void Tree::UpdateCenterPointTop()
{
	if (tree_cubes_list.count() > 0)
	{
		center_point_top.x = tree_cubes_list.end->data->info.GetPos().x + (tree_cubes_list.end->data->GetWidth() / 2);
		center_point_top.y = tree_cubes_list.end->data->info.GetPos().y;
	}
}

// Takes the cubes higher
void Tree::MakeTreeGrow()
{
	// Update position of the last treecube
	tree_cubes_list.end->data->SetPos(tree_cubes_list.end->data->GetX(), tree_cubes_list.end->data->GetY() - speed);
	
	// Check if we have to create another treecube
	if (tree_cubes_list.end->data->GetY() <= distance_next_treecube) 
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

void Tree::LoadRects()
{
	pugi::xml_node node = doc.child("cube1");

	texture = App->tex->Load(node.attribute("texture").as_string());

	node = node.child("rects");
	for (; node != NULL; node = node.child("rects").next_sibling())
	{
		SDL_Rect* rect = new SDL_Rect();
		rect->x = node.attribute("rect_x").as_int();
		rect->y = node.attribute("rect_y").as_int();
		rect->w = node.attribute("rect_w").as_int();
		rect->h = node.attribute("rect_h").as_int();
		rects.add(rect);
	}
}
