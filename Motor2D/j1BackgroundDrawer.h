#ifndef _J1BACKGROUNDRAWER_
#define _J1BACKGROUNDRAWER_

#include "j1Module.h"
#include "j1Render.h"

class j1BackgroundDrawer : public j1Module {
public:
	j1BackgroundDrawer();
	~j1BackgroundDrawer();

	bool Update(float dt);

	bool Start();

	bool CleanUp();

public:
	bool back1 = false;

private:
	SDL_Rect background;
	SDL_Texture* back_tex;

	int back1_1_y = -1881;
	int back1_2_y = -4587;
	int it = 0;
};

#endif // !_J1BACKGROWNDRAWER_
