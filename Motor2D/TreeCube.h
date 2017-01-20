#ifndef _TREECUBE_H_
#define _TREECUBE_H_

#include "Sprite2D.h"
#include "Entity.h"

class TreeCube : public Entity
{
public:
	TreeCube(iPoint position, const char* entity_name, int speed);

	~TreeCube();

	bool Update(float dt);

	bool Draw();

public:


};
#endif // !_TREECUBE_H_