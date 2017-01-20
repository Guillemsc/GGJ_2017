#ifndef _TREECUBE_H_
#define _TREECUBE_H_

#include "Sprite2D.h"
#include "Entity.h"

class TreeCube : public Entity
{
public:
	TreeCube(iPoint position, const char* entity_name);

	~TreeCube();

	bool Update(float dt);

	bool Draw();

	int GetHeight();
	int GetWidth();

public:
	p2List<Sprite2D> tree_cube_parts;

};
#endif // !_TREECUBE_H_