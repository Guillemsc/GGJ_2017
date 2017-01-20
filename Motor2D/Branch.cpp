#include "Branch.h"

Branch::Branch() : Entity(EntityType::Branch)
{
}

Branch::Branch(iPoint position, const char * entity_name) : Entity(EntityType::Branch, position, entity_name)
{
}

Branch::~Branch()
{
}

bool Branch::Update(float dt)
{
	return true;
}

bool Branch::Draw()
{
	return true;
}
