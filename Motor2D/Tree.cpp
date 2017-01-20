#include "Tree.h"

Tree::Tree(iPoint position, const char * entity_name, int _speed) : Entity(EntityType::Tree, position, entity_name), speed(_speed)
{
}

Tree::~Tree()
{
}

bool Tree::Update(float dt)
{
	return true;
}

bool Tree::Draw()
{
	return true;
}
