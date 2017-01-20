#include "IntroScene.h"
#include "j1Scene.h"
#include "j1Gui.h"
#include "UIButton.h"

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{
}

bool IntroScene::Start()
{
	//App->gui->CreateUIElement(Button, 360, 250);
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
}

void IntroScene::SaveCVar(p2SString & cvar_name, pugi::xml_node & node)
{
}

void IntroScene::OnCollision(PhysBody * bodyA, PhysBody * bodyB)
{
}
