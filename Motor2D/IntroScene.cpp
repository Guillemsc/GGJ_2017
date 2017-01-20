#include "IntroScene.h"

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{
}

bool IntroScene::Start()
{
	return false;
}

bool IntroScene::PreUpdate()
{
	return false;
}

bool IntroScene::Update(float dt)
{
	return false;
}

bool IntroScene::PostUpdate()
{
	return false;
}

void IntroScene::Draw()
{
}

bool IntroScene::CleanUp()
{
	return false;
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
