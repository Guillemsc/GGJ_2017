#include "j1App.h"
#include "j1GroundDrawer.h"
#include "j1Scene.h"
#include "FirstScene.h"
#include "j1Scene.h"
#include "j1Render.h"
#include "Tree.h"


j1GroundDrawer::j1GroundDrawer()
{
}

j1GroundDrawer::~j1GroundDrawer()
{
}

bool j1GroundDrawer::Update(float dt)
{
	if(App->scene->current_scene == App->scene->first_scene)
		App->render->Blit(App->scene->first_scene->t1->texture, 0, 700, &App->scene->first_scene->ground_rect);
	return true;
}

bool j1GroundDrawer::Start()
{
	return true;
}

bool j1GroundDrawer::CleanUp()
{
	return true;
}
