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
		if (speed > 0.3) info.SetAnimation(Jump);
		else if (speed > 0.1) info.SetAnimation(Run);
		else if (speed > -.1) info.SetAnimation(Idle);
		else if (speed > -.3)info.SetAnimation(Shoot);
		else info.SetAnimation(Hit);
		info.GetAnim()->SetSpeed(abs(speed));
		acumulated_dt = 0;
	}
	return true;
}

bool Grass::Draw()
{
	App->render->Blit(info.GetTexture(), info.GetPos().x, info.GetPos().y, &info.GetAnim()->GetCurrentFrameRect());
	return true;
}

float Grass::CalculateAnimSpeed(float wind) const
{
	return wind/30.0f;
}
