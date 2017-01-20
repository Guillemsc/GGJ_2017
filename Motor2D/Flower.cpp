#include "Flower.h"
#include "j1Render.h"

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
	float angle;
	if (GetDirection() == "left") angle = 180;
	else if (GetDirection() == "right") angle = 0;

	App->render->Blit(info.GetTexture(), info.GetPos().x, info.GetPos().y, &info.GetAnim()->GetCurrentFrameRect(), true, 1.0F, angle);
	
	return true;
}

void Flower::ChangeDirection(const char * _direction)
{
	direction = _direction;
}

p2SString Flower::GetDirection()
{
	return direction;
}
