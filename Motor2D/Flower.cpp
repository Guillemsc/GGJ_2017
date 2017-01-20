#include "Flower.h"

Flower::Flower() : Entity(EntityType::Flower)
{
}

Flower::Flower(iPoint position, const char * entity_name) : Entity(EntityType::Flower, position, entity_name)
{
}

Flower::~Flower()
{
}

bool Flower::Update(float dt)
{
	return true;
}

bool Flower::Draw()
{
	return true;
}
