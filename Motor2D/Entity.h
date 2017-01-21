#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Sprite2D.h"

enum EntityType 
{
	tree,
	tree_Cube,
	branch,
	grass,
	cloud,
	bird,
	NoType
};

enum DrawOrder
{
	BeforeScene,
	AfterScene
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

	EntityType GetType()const;

private:

public:
	Sprite2D info;
	DrawOrder draw_order = BeforeScene;

private:
	p2SString name;
	EntityType type;

};
#endif // !_ENTITY_H_

