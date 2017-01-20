#include "Grass.h"
#include "j1App.h"
#include "j1Scene.h"
#include "j1Render.h"
#include <math.h>

Grass::Grass(iPoint pos):Entity(grass,pos,"grass")
{
}

Grass::~Grass()
{
}

bool Grass::Update(float dt)
{
	acumulated_dt += dt;
	if(acumulated_dt>dt*10){
		speed = CalculateAnimSpeed(App->scene->GetWindForce());
		info.GetAnim()->SetSpeed(speed);
		acumulated_dt = 0;
	}
	return true;
}

bool Grass::Draw()
{
	App->render->Blit(info.GetTexture(), info.GetPos().x, info.GetPos().y, &info.GetAnim()->GetCurrentFrameRect(), true, 1.0f, (speed > 0) ? 0 : 180);
	return true;
}

int Grass::CalculateAnimSpeed(float wind) const
{
	return wind/15.0f;
}
