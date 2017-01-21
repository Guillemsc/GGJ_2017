#ifndef _FIRSTSCENE_
#define _FIRSTSCENE_

#include "Scene.h"
#include "j1Render.h"

class Tree;
class Grass;
class Cloud;
class WindOscillatingBar;
class Levels;

struct SDL_Texture;

class FirstScene : public Scene 
{
public:
	FirstScene();

	~FirstScene();

	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	void Draw();
	bool CleanUp();

	void UIReaction(UIElement* element, int react);
	void OnCommand(p2List<p2SString>& tokens);

	void OnCVar(p2List<p2SString>& tokens);

	void SaveCVar(p2SString& cvar_name, pugi::xml_node& node) const;

	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:
	Tree* t1 = nullptr;

	int counter = 0;
	int force = 0;

	WindOscillatingBar*	wind_bar;

	Levels* levels = nullptr;

private:
	p2List<Cloud*> clouds;

	Grass* grass1;
	Grass* grass2;
	Grass* grass3;

	// Ground
	SDL_Rect ground_rect;

	int prev_cam_y;

};

#endif