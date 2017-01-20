#include "IntroScene.h"
#include "j1Scene.h"
#include "j1Gui.h"
#include "UIButton.h"
#include "j1Console.h"

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

	options_button = (UIButton*)App->gui->CreateUIElement(Button, 360, 350, nullptr, 60, 30);
	options_button->SetRects({ 20,20,60,30 }, { 20,20,60,30 }, { 20,20,60,30 }); //ajust to final ones
	options_button->AddListener(App->scene);

	return true;
}

bool IntroScene::PreUpdate()
{
	return true;
}

bool IntroScene::Update(float dt)
{
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
