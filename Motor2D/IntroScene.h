#ifndef _INTROSCENE_H_
#define _INTROSCENE_H_

#include "Scene.h"
#include "j1Render.h"

class UIButton;
class UIWindow;
class UICheckBox;
class UIImage;
class WindOscillatingBar;

class Grass;
class Cloud;

class IntroScene: public Scene{
public:
	IntroScene();
	~IntroScene();

	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	void Draw();
	bool CleanUp();

	void UIReaction(UIElement* element, int react);
	void OnCommand(p2List<p2SString>& tokens);

	void OnCVar(p2List<p2SString>& tokens);

	void SaveCVar(p2SString& cvar_name, pugi::xml_node& node);

	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

private:

	UIButton* start_button = nullptr;
	UIButton* options_button = nullptr;

	SDL_Rect ground = NULLRECT;

	UIImage* sabling = nullptr;

	Grass* grass1 = nullptr;
	Grass* grass2 = nullptr;
	Grass* grass3 = nullptr;
	Grass* grass4 = nullptr;
	Grass* grass5 = nullptr;
	Grass* grass6 = nullptr;

	Cloud* cloud1 = nullptr;
	Cloud* cloud2 = nullptr;
	Cloud* cloud3 = nullptr;

	float accumulted_dt = 0;

	bool start = true;
public:

private:

};


#endif // !_INTROSCENE_H_

