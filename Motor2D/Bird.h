#ifndef _BIRD_
#define _BIRD_

#include "Entity.h"

class Bird : public Entity {
public:
	Bird(iPoint pos);
	~Bird();

	bool Update(float dt);

	bool Draw();
	
	void SetNest(Entity* nest);

private:

	int speed = 150;
	bool nested = false;;
	Entity* target_nest;
};

#endif // !_BIRD_
