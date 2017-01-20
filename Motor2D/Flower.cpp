#include "Flower.h"

Flower::Flower() : Entity(EntityType::flower)
{
}

Flower::Flower(iPoint position, const char * entity_name) : Entity(EntityType::flower, position, entity_name)
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
