#ifndef _FLOWER_H_
#define _FLOWER_H_

#include "Sprite2D.h"
#include "Entity.h"

enum WindDirection {
	east,
	west,
	no_wind
};

class Flower : public Entity //Flowers will be created when the treecube is static
{
public:
	Flower();
	Flower(EntityType type, iPoint position, const char* entity_name, WindDirection direction = no_wind);

	~Flower();

	bool Update(float dt);

	bool Draw();

private:
	WindDirection direction;

};
#endif // !_FLOWER_H_
