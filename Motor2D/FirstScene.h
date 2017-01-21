#ifndef _FIRSTSCENE_
#define _FIRSTSCENE_

#include "Scene.h"
#include "j1Render.h"
#include "j1Timer.h"


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

	bool wait_for_menu = false;

	int birds = 0;
	int nested_birds = 0;

private:

	Grass* grass1 = nullptr;
	Grass* grass2 = nullptr;
	Grass* grass3 = nullptr;
	Grass* grass4 = nullptr;
	Grass* grass5 = nullptr;

	int prev_cam_y = 0;
	bool gen_cloud = true;

	bool active_event = false;;

	bool move_camera = false;

	bool activate_wind_gust = false;

	j1Timer event_time;
	float event_reset_time;

};

#endif