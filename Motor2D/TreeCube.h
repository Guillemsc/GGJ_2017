#ifndef _TREECUBE_H_
#define _TREECUBE_H_

#include "Sprite2D.h"
#include "Entity.h"

struct CubePart
{
	CubePart() {  };
	CubePart(iPoint _pos, SDL_Rect _rect)
	{
		pos = _pos; 
		rect = { _rect.x, _rect.y, _rect.w, _rect.h };
	};

	iPoint pos;
	SDL_Rect rect;
};

class TreeCube : public Entity
{
public:
	TreeCube(iPoint position, const char* entity_name, p2List<SDL_Rect> rects, SDL_Texture* texture);

	~TreeCube();

	bool Update(float dt);

	bool Draw();

	int GetX();
	int GetY();
	int GetHeight();
	int GetWidth();
	void SetPos(int x, int y);

public:
	SDL_Texture* texture = nullptr;

	p2List<CubePart> tree_cube_parts;

};
#endif // !_TREECUBE_H_