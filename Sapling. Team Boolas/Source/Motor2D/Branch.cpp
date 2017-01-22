#include "Branch.h"
#include "j1Render.h"
#include "j1Scene.h"

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
	acumulated_dt += dt;
	if (acumulated_dt>dt * 10) {
		speed = CalculateAnimSpeed(App->scene->GetWindForce());
		info.GetAnim()->SetSpeed(speed);
		acumulated_dt = 0;
	}
	return true;
}

bool Branch::Draw()
{
	App->render->Blit(info.GetTexture(), info.GetPos().x, info.GetPos().y, &info.GetAnim()->GetCurrentFrameRect());

	return true;
}

int Branch::CalculateAnimSpeed(float wind) const
{
	return wind / 15.0f;
}
