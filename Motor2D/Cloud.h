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
	int GetTargetFrame(float speed) const;

private:
	float speed = 0;
	float acumulated_dt = 0;
	int element = 0;
	int curr_frame = 3;
	int target_frame = 3;

};

#endif // !_CLOUD_H_
