#include "j1BackgroundDrawer.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Render.h"

j1BackgroundDrawer::j1BackgroundDrawer()
{
	name.create("back_draw");
}

j1BackgroundDrawer::~j1BackgroundDrawer()
{
}

bool j1BackgroundDrawer::Update(float dt)
{
	if (back1){
		App->render->Blit(back_tex, 0, back1_1_y, &background);
		App->render->Blit(back_tex, 0, back1_2_y, &background);
		if (App->render->camera.y % 2090 == 0 && App->render->camera.y != 0) {
			it++;
			if (it % 2 == 0) 
				back1_2_y -= 2706;
			else back1_1_y -= 2706;
		}
	}
	return true;
}

bool j1BackgroundDrawer::Start()
{
	back_tex = App->tex->Load("Sprites/back2.png");
	background = { 0,0, 700,2708 };
	return true;
}

bool j1BackgroundDrawer::CleanUp()
{
	App->tex->UnLoad(back_tex);
	return true;
}
