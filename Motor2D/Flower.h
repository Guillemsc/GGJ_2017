#ifndef _FLOWER_H_
#define _FLOWER_H_

#include "Sprite2D.h"
#include "Entity.h"

class Flower : public Entity //Flowers will be created when the treecube is static
{
public:
	Flower();

	Flower(iPoint position, const char* entity_name);

	~Flower();

	bool Update(float dt);

	bool Draw(); //Afegir angle al blit

private:

};
#endif // !_FLOWER_H_
