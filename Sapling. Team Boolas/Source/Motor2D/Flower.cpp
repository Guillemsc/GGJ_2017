#include "Flower.h"
#include "j1Render.h"
#include "j1Scene.h"

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
	acumulated_dt += dt;
	if (acumulated_dt>dt * 10) {
		speed = CalculateAnimSpeed(App->scene->GetWindForce());
		info.GetAnim()->SetSpeed(speed);
		acumulated_dt = 0;
	}
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

int Flower::CalculateAnimSpeed(float wind) const
{
	return wind / 15.0f;
}
