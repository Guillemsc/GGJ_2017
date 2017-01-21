#ifndef _FIRSTSCENE_
#define _FIRSTSCENE_

#include "Scene.h"
#include "j1Render.h"

enum Events {
	bird_nest, storm, wind_gust, wind, against_wind, events_num
};

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
	int counter2 = 0;
	int force = 0;

	WindOscillatingBar*	wind_bar = nullptr;

	Levels* levels = nullptr;

	// Ground
	SDL_Rect ground_rect = NULLRECT;

	p2List<Cloud*> clouds;

private:

	Grass* grass1 = nullptr;
	Grass* grass2 = nullptr;
	Grass* grass3 = nullptr;
	Grass* grass4 = nullptr;
	Grass* grass5 = nullptr;

	int prev_cam_y = 0;
	bool gen_cloud = true;

	bool active_events[events_num];

	bool move_camera = false;

};

#endif