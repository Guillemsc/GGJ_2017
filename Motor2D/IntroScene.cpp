#include "IntroScene.h"
#include "j1Scene.h"
#include "j1Gui.h"
#include "UIImage.h"
#include "UIButton.h"
#include "UIWindow.h"
#include "UICheckBox.h"
#include "j1Console.h"
#include "j1Entities.h"
#include "WindOscillatingBar.h"
#include "j1BackgroundDrawer.h"
#include "Cloud.h"
#include "FirstScene.h"
#include "Grass.h"

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{
}

bool IntroScene::Start()
{
	ground = { 0,1120,700,159 };

	sabling = (UIImage*)App->gui->CreateUIElement(Image, 75, 202);
	sabling->SetRect({ 0,567,550,421 });

	App->back->back2 = true;

	start_button = (UIButton*)App->gui->CreateUIElement(Button, 360, 400,nullptr,211,75);
	start_button->SetRects({ 255,424,211,75 },{ 255,424,211,75 }, { 242,271,211,75 }); //ajust to final ones
	start_button->AddListener(App->scene);

	options_button = (UIButton*)App->gui->CreateUIElement(Button, 112, 462, nullptr, 147, 64);
	options_button->SetRects({ 0,496,147,64 }, { 1,192,147,64 }, { 0,336,147,64 }); //ajust to final ones
	options_button->AddListener(App->scene);

	options_window = (UIWindow*)App->gui->CreateUIElement(Window, 175, 200, nullptr, 300, 400);
	options_window->SetRect({ 20,20,60,30 }); //ajust to final one
	options_window->active = false;

	music_check = (UICheckBox*)App->gui->CreateUIElement(CheckBox, 75, 150, options_window, 30, 30);
	music_check->SetRects({ 20,20,60,30 }, { 20,20,60,30 }, { 20,20,60,30 }); //adjust to final ones
	music_check->AddListener(App->scene);
	music_check->active = false;

	grass1 = (Grass*)App->entities->CreateEntity(grass, 10, 630);
	grass2 = (Grass*)App->entities->CreateEntity(grass, 540, 630);
	grass3 = (Grass*)App->entities->CreateEntity(grass, 70, 680);
	grass4 = (Grass*)App->entities->CreateEntity(grass, 480, 680);
	grass5 = (Grass*)App->entities->CreateEntity(grass, 40, 720);
	grass6 = (Grass*)App->entities->CreateEntity(grass, 520, 720);
	
	cloud1 = (Cloud*)App->entities->CreateEntity(cloud, 150, 50);
	cloud2 = (Cloud*)App->entities->CreateEntity(cloud, 350, 10);
	cloud3 = (Cloud*)App->entities->CreateEntity(cloud, 500, 125);

	return true;
}

bool IntroScene::PreUpdate()
{	
	return true;
}

bool IntroScene::Update(float dt)
{
	accumulted_dt += dt;

	if (start) {
		start = false;
		App->console->AddText("scene.wind_speed 6", Input);
	}
	
	if (cloud1->info.GetPos().x > 700) {
		iPoint new_pos(-200, cloud1->info.GetPos().y);
		cloud1->info.SetPos(new_pos);
	}

	if (cloud2->info.GetPos().x > 700) {
		iPoint new_pos(-200, cloud2->info.GetPos().y);
		cloud2->info.SetPos(new_pos);
	}
	if (cloud3->info.GetPos().x > 700) {
		iPoint new_pos(-200, cloud3->info.GetPos().y);
		cloud3->info.SetPos(new_pos);
	}

	if (accumulted_dt > 5) {
		accumulted_dt = 0;
		wind_force = -wind_force;
	}

	App->render->Blit(App->gui->GetAtlas(), 0, 700, &ground);
	return true;
}

bool IntroScene::PostUpdate()
{
	return true;
}

void IntroScene::Draw()
{
}

bool IntroScene::CleanUp()
{
	App->gui->DeleteUIElement(start_button);
	App->gui->DeleteUIElement(options_button);
	App->gui->DeleteUIElement(options_window);
	App->gui->DeleteUIElement(music_check);
	App->gui->DeleteUIElement(sabling);
	App->entities->DeleteEntity(cloud1);
	App->entities->DeleteEntity(cloud2);
	App->entities->DeleteEntity(cloud3);
	App->entities->DeleteEntity(grass1);
	App->entities->DeleteEntity(grass2);
	App->entities->DeleteEntity(grass3);
	App->entities->DeleteEntity(grass4);
	App->entities->DeleteEntity(grass5);
	App->entities->DeleteEntity(grass6);
	return true;
}

void IntroScene::UIReaction(UIElement * element, int react)
{
	switch (react) {
	case LeftClick:
		if (element == options_button) {
			options_button->Clicked();
			options_window->active = !options_window->active;
			music_check->active = !music_check->active;
		}
		else if (element == music_check) {
			music_check->Clicked();
		}
		break;
	case LeftClickUp:
		if (element == options_button) {
			options_button->Standard();
		}
		else if (element == music_check) {
			music_check->Standard();
		}
		else if (element == start_button) {
			App->scene->ChangeScene(App->scene->first_scene);
		}
		break;
	case MouseEnter:
		if (element == options_button) {
			options_button->Highlight();
		}
		else if (element == music_check) {
			music_check->Highlight();
		}
		break;
	case MouseLeave:
		if (element == options_button) {
			options_button->Standard();
		}
		else if (element == music_check) {
			music_check->Standard();
		}
		break;
	}
}

void IntroScene::OnCommand(p2List<p2SString>& tokens)
{
}

void IntroScene::OnCVar(p2List<p2SString>& tokens)
{
	switch (tokens.count())
	{
	case 1:
		if (tokens[0] == "scene.wind_speed"){
			p2SString speed("wind speed: %.2f", wind_force);
			App->console->AddText(speed.GetString(), Output);
		}
		break;
	case 2:
		if (tokens[0] == "scene.wind_speed") {
			wind_force = atof(tokens[1].GetString());
			p2SString speed("wind speed set to %.2f", wind_force);
			App->console->AddText(speed.GetString(), Output);
		}
		break;
	default:
		break;
	}
}

void IntroScene::SaveCVar(p2SString & cvar_name, pugi::xml_node & node)
{
}

void IntroScene::OnCollision(PhysBody * bodyA, PhysBody * bodyB)
{
}
