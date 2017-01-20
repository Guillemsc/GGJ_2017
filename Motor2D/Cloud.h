#ifndef _CLOUD_H_
#define _CLOUD_H_

#include "Entity.h"

class Cloud : public Entity {
public:
	Cloud(iPoint pos);
	~Cloud();

	bool Update(float dt);

	bool Draw();

private:
	int CalculateSpeed(float wind) const;

};

#endif // !_CLOUD_H_
