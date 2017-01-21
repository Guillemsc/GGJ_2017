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

	UIButton* start_button;
	UIButton* options_button;

	SDL_Rect ground;

	UIImage* sabling;

	UIWindow*		options_window;
	UICheckBox*		music_check;

	Grass* grass1;
	Grass* grass2;
	Grass* grass3;
	Grass* grass4;
	Grass* grass5;
	Grass* grass6;

	Cloud* cloud1;
	Cloud* cloud2;
	Cloud* cloud3;

	float accumulted_dt = 0;

	bool start = true;
public:

private:

};


#endif // !_INTROSCENE_H_

