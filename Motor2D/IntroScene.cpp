#include "IntroScene.h"
#include "j1Scene.h"
#include "j1Gui.h"
#include "UIImage.h"
#include "UIButton.h"
#include "UIWindow.h"
#include "UICheckBox.h"
#include "j1Console.h"
#include "j1Entities.h"

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{
}

bool IntroScene::Start()
{
	start_button = (UIButton*)App->gui->CreateUIElement(Button, 360, 250,nullptr,60,30);
	start_button->SetRects({ 20,20,60,30 }, { 20,20,60,30 }, { 20,20,60,30 }); //ajust to final ones
	start_button->AddListener(App->scene);

	options_button = (UIButton*)App->gui->CreateUIElement(Button, 450, 50, nullptr, 30, 30);
	options_button->SetRects({ 20,20,60,30 }, { 20,20,60,30 }, { 20,20,60,30 }); //ajust to final ones
	options_button->AddListener(App->scene);

	test_cloud = (Cloud*)App->entities->CreateEntity(cloud, 50, 50);
	test_grass = (Grass*)App->entities->CreateEntity(grass, 50, 600);

	options_window = (UIWindow*)App->gui->CreateUIElement(Window, 175, 200, nullptr, 300, 400);
	options_window->SetRect({ 20,20,60,30 }); //ajust to final one
	options_window->active = false;

	music_check = (UICheckBox*)App->gui->CreateUIElement(CheckBox, 75, 150, options_window, 30, 30);
	music_check->SetRects({ 20,20,60,30 }, { 20,20,60,30 }, { 20,20,60,30 }); //adjust to final ones
	music_check->AddListener(App->scene);
	music_check->active = false;

	wind_window = (UIWindow*)App->gui->CreateUIElement(Window, 175, 200, nullptr, 200, 20);
	options_window->SetRect({ 20,20,60,30 }); //adjust to final one

	wind_bar = (UIImage*)App->gui->CreateUIElement(Image, 0, 0, wind_window, 10, 20);
	wind_bar->SetRect({ 20,20,60,30 }); //adjust to final one
	wind_bar->AddListener(App->scene);

	return true;
}

bool IntroScene::PreUpdate()
{
	return true;
}

bool IntroScene::Update(float dt)
{
	wind_bar->position.x = (wind_window->position.w - 10)/2 + ((wind_window->position.w - 10) /2)*sin(angle);
	angle += 0.05;

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
