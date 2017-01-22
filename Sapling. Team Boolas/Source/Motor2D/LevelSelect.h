#ifndef _LEVELSELECT_
#define _LEVELSELECT_

#include "Scene.h"
#include "j1Render.h"

#define X_ 35
#define Y_ 100
#define W_ 204
#define H_ 159

class UIButton;

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

	void UIReaction(UIElement * element, int react);
private:
	UIButton* level1 = nullptr;		UIButton* level2 = nullptr;		UIButton* level3 = nullptr;
	UIButton* level4 = nullptr;		UIButton* level5 = nullptr;		UIButton* level6 = nullptr;
	UIButton* level7 = nullptr;		UIButton* level8 = nullptr;		UIButton* level9 = nullptr;

	SDL_Rect	standard = NULLRECT;
	SDL_Rect	highlighted = NULLRECT;
	SDL_Rect	clicked = NULLRECT;
};

#endif // !_LEVELSELECT_

