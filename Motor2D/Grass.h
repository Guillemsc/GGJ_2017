#ifndef _GRASS_H_
#define _GRASS_H_

#include "Entity.h"

class Grass : public Entity
{
	Grass(iPoint pos);
	~Grass();

	bool Update(float dt);

	bool Draw();

private:
	int CalculateAnimSpeed(float wind)const;

private:
	float speed = 0;
	float acumulated_dt = 0;

};

#endif // !_GRASS_H_

