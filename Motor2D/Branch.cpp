#include "Branch.h"

Branch::Branch() : Entity(EntityType::branch)
{
}

Branch::Branch(iPoint position, const char * entity_name) : Entity(EntityType::branch, position, entity_name)
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
