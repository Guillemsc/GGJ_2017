#ifndef _J1GROUNDDRAWER_
#define _J1GROUNDDRAWER_

#include "j1Module.h"
#include "j1Render.h"

class j1GroundDrawer : public j1Module {
public:
	j1GroundDrawer();
	~j1GroundDrawer();

	bool Update(float dt);

	bool Start();

	bool CleanUp();

public:

private:

};

#endif // !_J1GROUNDDRAWER_