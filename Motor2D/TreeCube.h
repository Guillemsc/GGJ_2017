#ifndef _TREECUBE_H_
#define _TREECUBE_H_

#include "Sprite2D.h"
#include "Entity.h"

struct CubePart
{
	SDL_Texture* texture = nullptr;
	iPoint pos;
	SDL_Rect rect;
};

class TreeCube : public Entity
{
public:
	TreeCube(iPoint position, const char* entity_name);

	~TreeCube();

	bool Update(float dt);

	bool Draw();

	int GetX();
	int GetY();
	int GetHeight();
	int GetWidth();
	void SetPos(int x, int y);

public:
	p2List<Sprite2D> tree_cube_parts;

};
#endif // !_TREECUBE_H_