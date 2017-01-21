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

	bool one_time = true;
	uint bird_creation_FX = NULL;
	uint bird_later_FX = NULL;

};

#endif // !_BIRD_
