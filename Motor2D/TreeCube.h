#ifndef _TREECUBE_H_
#define _TREECUBE_H_

#include "Sprite2D.h"
#include "Entity.h"

struct CubePart
{
	CubePart() {  };
	CubePart(iPoint _pos, SDL_Rect _rect, SDL_Rect _rect_green)
	{
		pos = _pos; 
		rect = { _rect.x, _rect.y, _rect.w, _rect.h };
		rect_green = _rect_green;
	};

	iPoint pos;
	SDL_Rect rect;
	SDL_Rect rect_green;
};

class TreeCube : public Entity
{
public:
	TreeCube(iPoint position, const char* entity_name, p2List<SDL_Rect> &rects, p2List<SDL_Rect> &rects_green, SDL_Texture* texture);

	~TreeCube();

	bool Update(float dt);

	bool Draw(int position);

	int GetX();
	int GetY();
	int GetHeight();
	int GetWidth();
	void SetPos(int x, int y);

public:
	SDL_Texture* texture = nullptr;

	p2List<CubePart*> tree_cube_parts;

};
#endif // !_TREECUBE_H_