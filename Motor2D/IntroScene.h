#ifndef _INTROSCENE_H_
#define _INTROSCENE_H_

#include "Scene.h"

class UIButton;
class Cloud;
class UIWindow;
class UICheckBox;
class UIImage;
class WindOscillatingBar;

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

	Cloud* test_cloud;

	UIWindow*		options_window;
	UICheckBox*		music_check;

	WindOscillatingBar*	wind_bar;
public:

private:

};


#endif // !_INTROSCENE_H_

