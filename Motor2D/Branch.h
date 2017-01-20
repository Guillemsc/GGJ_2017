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

private:

};
#endif // !_BRANCH_H_
