#include "Grass.h"
#include "j1App.h"
#include "j1Scene.h"

Grass::Grass(iPoint pos):Entity(grass,pos,"grass")
{
}

Grass::~Grass()
{
}

bool Grass::Update(float dt)
{
	
	return true;
}

bool Grass::Draw()
{
	return true;
}
