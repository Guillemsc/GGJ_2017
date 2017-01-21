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
	if(acumulated_dt>dt*5){
		speed = CalculateAnimSpeed(App->scene->GetWindForce());
		info.GetAnim()->SetSpeed(speed);
		if (speed > 0.6) info.SetAnimation(Jump);
		else if (speed > 0.2) info.SetAnimation(Run);
		else if (speed > -.2) info.SetAnimation(Idle);
		else if (speed > -.6)info.SetAnimation(Shoot);
		else info.SetAnimation(Hit);
		acumulated_dt = 0;
	}
	return true;
}

bool Grass::Draw()
{
	App->render->Blit(info.GetTexture(), info.GetPos().x, info.GetPos().y, &info.GetAnim()->GetCurrentFrameRect());
	return true;
}

int Grass::CalculateAnimSpeed(float wind) const
{
	return wind/15.0f;
}
