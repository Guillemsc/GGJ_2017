#ifndef _DRAWENTITIES_
#define _DRAWENTITIES_

#include "j1Module.h"

class j1DrawEntities : public j1Module {
public:
	j1DrawEntities();
	~j1DrawEntities();

	bool Update(float dt);
	bool PostUpdate();
};


#endif // !_DRAWENTITIES_
