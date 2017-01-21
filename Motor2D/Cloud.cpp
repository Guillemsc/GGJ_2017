#include "Cloud.h"
#include "j1App.h"
#include "j1Scene.h"
#include "j1Render.h"
#include <math.h>
#include <random>
#include <iostream>
using namespace std;


Cloud::Cloud(iPoint pos) : Entity(cloud,pos,"cloud")
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> random(0, 1);
	element = random(gen);
	info.GetAnim()->SetInitialFrame(2);
}

Cloud::~Cloud()
{
}

bool Cloud::Update(float dt)
{
	acumulated_dt += dt;
	if (acumulated_dt>dt * 10) {
		speed = CalculateSpeed(App->scene->GetWindForce());
		iPoint pos(info.GetPos().x+speed*dt, info.GetPos().y);
		info.SetPos(pos);
		target_frame = GetTargetFrame(App->scene->GetWindForce());
		info.GetAnim()->SetInitialFrame(target_frame);
		acumulated_dt = 0;
	}
	return true;
}

bool Cloud::Draw()
{
	SDL_Rect rect = {info.GetAnim()->GetActualFrameRect().x, element*info.GetAnim()->GetActualFrameRect().h+1, info.GetAnim()->GetActualFrameRect().w, info.GetAnim()->GetActualFrameRect().h };
	App->render->Blit(info.GetTexture(), info.GetPos().x, info.GetPos().y, &rect);
	return true;
}

int Cloud::CalculateSpeed(float wind) const
{
	return wind*15;
}

int Cloud::GetTargetFrame(float speed) const
{
	if (speed > 7.0f) return 0;
	if (speed > 1.5f) return 1;
	if (speed > -1.5f) return 2;
	if (speed > -7.0f) return 3;
	return 4;
}
