#ifndef _GRASS_H_
#define _GRASS_H_

#include "Entity.h"

class Grass : public Entity
{
	Grass(iPoint pos);
	~Grass();

	bool Update(float dt);

	bool Draw();


};

#endif // !_GRASS_H_

