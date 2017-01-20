#ifndef _ENTITY_H_
#define _EMTITY_H_

#include "Sprite2D.h"

enum EntityType 
{
	Tree,
	Tree_Cube,
	Flower,
	Branch,
	NoType
};

class Entity
{
public:
	Entity();
	Entity(EntityType type);
	Entity(EntityType type, iPoint position, const char* entity_name);

	~Entity();

	virtual bool Update(float dt);

	virtual bool Draw();

	const char* GetName()const;

private:

public:
	Sprite2D info;

private:
	p2SString name;
	EntityType type;

};
#endif // !_ENTITY_H_

