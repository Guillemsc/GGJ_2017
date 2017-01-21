#include "FirstScene.h"
#include "WindOscillatingBar.h"
#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Gui.h"
#include "UIImage.h"
#include "UILabel.h"
#include "UIButton.h"
#include "UIInputText.h"
#include "UIWindow.h"
#include "UIScrollBar.h"
#include "UICheckBox.h"
#include "j1Console.h"
#include "j1Scene.h"
#include "Tree.h"
#include "j1Entities.h"
#include "Cloud.h"
#include "Grass.h"
#include "Levels.h"
#include "j1BackgroundDrawer.h"
#include <random>
#include <iostream>

#define CAMERA_SCROLL 300

FirstScene::FirstScene()
{
}

FirstScene::~FirstScene()
{
}

bool FirstScene::Start()
{
	// XML load test
	pugi::xml_document doc; App->LoadXML("test.xml", doc);
	int value = doc.child("test").attribute("value").as_int();

	t1 = (Tree*)App->entities->CreateEntity(tree, 291, 750);
	t1->Set(3);
	t1->StartGrowing();

	clouds.add((Cloud*)App->entities->CreateEntity(cloud, 275, 125));

	grass1 = (Grass*)App->entities->CreateEntity(grass, 25, 680);
	//grass2 = (Grass*)App->entities->CreateEntity(grass, 230, 670);
	//grass3 = (Grass*)App->entities->CreateEntity(grass, 450, 650);

	wind_bar = new WindOscillatingBar(30, 30, 200, 20);

	levels = new Levels(t1);
	levels->SetLevel(1);

	// Background
	pugi::xml_node node = t1->doc.child("ground");
	ground_rect = { node.attribute("rect_x").as_int(), node.attribute("rect_y").as_int(), node.attribute("rect_w").as_int(), node.attribute("rect_h").as_int()};
	App->back->back1 = true;

	return true;
}

bool FirstScene::PreUpdate()
{
	return true;
}

bool FirstScene::Update(float dt)
{
	// Tree movement
	if (counter == 15)
	{
		if(!levels->level_ended)
			t1->WindForceOnTree(wind_force);
		counter = 0;
	}
	counter++;

	// Camera
	if(t1->center_point_top.y <= CAMERA_SCROLL)
	App->render->camera.y = -t1->center_point_top.y + CAMERA_SCROLL;

	// Wind Bar
	wind_bar->UpdateBar();
	wind_force = wind_bar->wind_power;

	// Levels
	levels->Update(dt);

	if ((App->render->camera.y % 110) == 0 && App->render->camera.y != prev_cam_y && !gen_cloud){
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> random(0, 20);
		if(random(gen)<15)
			gen_cloud = true;
	}
	prev_cam_y = App->render->camera.y;

	if (gen_cloud) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> random(0, 600);
		int pos_x = random(gen);
		clouds.add((Cloud*)App->entities->CreateEntity(cloud, pos_x, -App->render->camera.y - 75));
		gen_cloud = false;
	}

	return true;
}

bool FirstScene::PostUpdate()
{
	return true;
}

void FirstScene::Draw()
{
	App->render->Blit(t1->texture, 0, 700, &ground_rect);
}

bool FirstScene::CleanUp()
{
	delete wind_bar;
	App->back->back1 = false;
	return true;
}

void FirstScene::UIReaction(UIElement * element, int react)
{
}

void FirstScene::OnCommand(p2List<p2SString>& tokens)
{
}

void FirstScene::OnCVar(p2List<p2SString>& tokens)
{
}

void FirstScene::SaveCVar(p2SString & cvar_name, pugi::xml_node & node) const
{
}

void FirstScene::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
}
