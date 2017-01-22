#ifndef _LEVELSELECT_
#define _LEVELSELECT_

#include "Scene.h"

class LevelSelect :public Scene {
public:
	LevelSelect();
	~LevelSelect();

	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	void Draw();
	bool CleanUp();
};

#endif // !_LEVELSELECT_

