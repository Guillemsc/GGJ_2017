#include "Branch.h"
#include "j1Render.h"

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
	float angle;
	if (GetDirection() == "left") angle = 180;
	else if (GetDirection() == "right") angle = 0;
	
	App->render->Blit(info.GetTexture(), info.GetPos().x, info.GetPos().y, &info.GetAnim()->GetCurrentFrameRect(), true, 1.0F, angle);

	return true;
}

void Branch::ChangeDirection(const char * _direction)
{
	direction = _direction;
}

p2SString Branch::GetDirection()
{
	return direction;
}
