#include "Cloud.h"

Cloud::Cloud(iPoint pos) : Entity(cloud,pos,"cloud")
{
}

Cloud::~Cloud()
{
}

bool Cloud::Update(float dt)
{
	return true;
}

bool Cloud::Draw()
{
	return true;
}

int Cloud::CalculateSpeed(float wind) const
{
	return wind*15;
}
