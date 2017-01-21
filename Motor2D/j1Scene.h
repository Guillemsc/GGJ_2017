#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"

struct SDL_Texture;

class Scene;
class FirstScene;
class IntroScene;

class UIImage;
class UILabel;
class UIButton;
class UIWindow;
class UIInputText;
class UIScrollBar;
class UICheckBox;

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void UIReaction(UIElement* element, int react);
	void OnCVar(p2List<p2SString>& tokens);

	void ChangeScene(Scene* new_scene);

	float GetWindForce()const;

public:

	Scene* current_scene = nullptr;

	FirstScene* first_scene = nullptr;
	IntroScene* intro_scene = nullptr;

private:
	SDL_Texture* debug_tex = nullptr;

	UIImage* banner = nullptr;
	UILabel* text = nullptr;
	UILabel* text2 = nullptr;
	UIButton* button = nullptr;
	UIButton* button2 = nullptr;
	UIWindow* window = nullptr;
	UIInputText* input_text = nullptr;
	UIScrollBar* horizontal = nullptr;
	UIScrollBar* vertical = nullptr;
	UICheckBox* option1 = nullptr;
	UICheckBox* option2 = nullptr;
	UICheckBox* multi_option1 = nullptr;
	UICheckBox* multi_option2 = nullptr;
	UIWindow* vis = nullptr;
};

#endif // __j1SCENE_H__