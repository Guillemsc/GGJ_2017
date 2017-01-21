#include "Tree.h"
#include "TreeCube.h"
#include "Flower.h"
#include "Branch.h"
#include <random>
#include <iostream>
#include "j1FileSystem.h"
#include "p2Log.h"
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
	int position = 0;

	if (end_tree_steps != 0)
		position -= end_tree_steps;
	for (int i = tree_cubes_list.count()-1; i >= 0; i--)
	{
		tree_cubes_list[i]->Draw(position);
		position++;
	}
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
		tree_cube = new TreeCube(iPoint(info.GetPos().x, info.GetPos().y), name.GetString(), rects, rects_green, texture);
		center_point_top.y = info.GetPos().y;
	}
	else
		// Create tree cube on the center point
		tree_cube = new TreeCube(iPoint(center_point_top.x - (tree_cubes_list.end->data->GetWidth() / 2), center_point_top.y), name.GetString(), rects, rects_green, texture);

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
		center_point_top.x = tree_cubes_list.end->data->GetX() + (tree_cubes_list.end->data->GetWidth() / 2);
		center_point_top.y = tree_cubes_list.end->data->GetY();
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

void Tree::WindForceOnTree(float force)
{
	if (force == 0.0f)
		return;

	int general_counter = 1;
	int cube_counter = 1;
	p2List_item<TreeCube*>* current_cube = tree_cubes_list.end;
	p2List_item<TreeCube*>* to_copy = current_cube;
	
	for (cube_counter; cube_counter < 3; cube_counter++)
	{
		if (current_cube->prev != nullptr)
		{
			current_cube = current_cube->prev;
		}
		else
			break;
	}

	for(int i = 0; i < cube_counter; i++)
	{
		p2List_item<CubePart*>* current_part = current_cube->data->tree_cube_parts.end;

		if (current_cube == to_copy && current_cube->prev != nullptr)
		{
			for (; current_part != nullptr; current_part = current_part->prev)
			{
				if (current_part != current_cube->data->tree_cube_parts.end && current_part != current_cube->data->tree_cube_parts.end->prev)
				{
					current_part->data->pos.x += general_counter;

					general_counter += force / 1.3f;
				}
			}
		}
		else
		{
			for (; current_part != nullptr; current_part = current_part->prev)
			{
				current_part->data->pos.x += general_counter;

				general_counter += force / 1.3f;
			}
		}

		current_cube = current_cube->next;
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
	pugi::xml_node node = doc.child("config").child("cube1");

	texture = App->tex->Load(node.attribute("texture").as_string());

	node = node.child("rects");
	for (; node != NULL; node = node.next_sibling("rects"))
	{
		SDL_Rect rect = {0, 0, 0, 0};
		rect.x = node.attribute("rect_x").as_int();
		rect.y = node.attribute("rect_y").as_int();
		rect.w = node.attribute("rect_w").as_int();
		rect.h = node.attribute("rect_h").as_int();
		rects.add(rect);
	}

	node = doc.child("config").child("cube2").child("rects");
	for (; node != NULL; node = node.next_sibling("rects"))
	{
		SDL_Rect rect_green = { 0, 0, 0, 0 };
		rect_green.x = node.attribute("rect_x").as_int();
		rect_green.y = node.attribute("rect_y").as_int();
		rect_green.w = node.attribute("rect_w").as_int();
		rect_green.h = node.attribute("rect_h").as_int();
		rects_green.add(rect_green);
	}
}

float Tree::abs(float value)
{
	float ret = value;

	if (ret < 0)
		ret = -ret;

	return ret;
}

void Tree::Reset()
{
	growing = false;
	create_cube = true;

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
