#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1PathFinding.h"
#include "j1Gui.h"
#include "UIImage.h"
#include "UILabel.h"
#include "UIButton.h"
#include "UIInputText.h"
#include "j1Scene.h"
#include "UIWindow.h"
#include "UIScrollBar.h"
#include "UICheckBox.h"
#include "j1Console.h"
#include "FirstScene.h"
#include "Scene.h"
#include "IntroScene.h"
#include "LevelSelect.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	//first_scene = new FirstScene();
	intro_scene = new IntroScene();
	first_scene = new FirstScene();
	levelselect_scene = new LevelSelect();

	if (current_scene == nullptr)
	{
		current_scene = intro_scene;
		current_scene->Start();
	}

	App->console->AddCVar("scene.wind_speed", this, "Set wind speed to x value. Max Args: 1. Args: -10<x<10");
	App->console->AddCVar("scene.wind_gust", this, "Activate or desactivate wind gust event. Max Args: 1. Args: true, false");
	App->console->AddCVar("scene.storm", this, "Activate or desactivate storm event. Max Args: 1. Args: true, false");
	App->console->AddCVar("scene.against_wind", this, "Activate or desactivate against wind event. Max Args: 1. Args: true, false");

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	if (current_scene != nullptr)
		current_scene->PreUpdate();

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	if (current_scene != nullptr)
	{
		current_scene->Update(dt);
		current_scene->Draw();
	}

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if (current_scene != nullptr)
		current_scene->PostUpdate();


	// Jeje
	if (App->input->GetKey(SDL_SCANCODE_GRAVE) == KEY_DOWN)
		App->console->Activate();

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing current scene");

	if (current_scene != nullptr)
		current_scene->CleanUp();

	return true;
}

void j1Scene::UIReaction(UIElement * element, int react)
{
	current_scene->UIReaction(element, react);
}

void j1Scene::OnCVar(p2List<p2SString>& tokens)
{
	current_scene->OnCVar(tokens);
}

void j1Scene::ChangeScene(Scene * new_scene)
{
	current_scene->CleanUp();
	current_scene = new_scene;
	current_scene->Start();
}

float j1Scene::GetWindForce() const
{
	return current_scene->wind_force;
}

void j1Scene::AddBird()
{
	num_birds++;
}

void j1Scene::AddNested()
{
	nested++;
}

void j1Scene::RestartBirds()
{
	num_birds = 0;
	nested = 0;
}
