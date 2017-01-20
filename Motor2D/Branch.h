#ifndef _BRANCH_H_
#define _BRANCH_H_

#include "Sprite2D.h"
#include "Entity.h"

class Branch : public Entity //Branchs will be created when the treecube is static
{
public:
	Branch();

	Branch(iPoint position, const char* entity_name);

	~Branch();

	bool Update(float dt);

	bool Draw();

	void ChangeDirection(const char* _direction);
	p2SString GetDirection();

private:
	p2SString direction = nullptr;
};
#endif // !_BRANCH_H_
