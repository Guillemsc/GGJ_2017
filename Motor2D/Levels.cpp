#include "Levels.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "Tree.h"
#include "p2Log.h"
#include "UILabel.h"
#include "j1Gui.h"
#include "Entity.h"
#include "j1Entities.h"
#include "j1Audio.h"
#include "j1Scene.h"

Levels::Levels(Tree* _tree, SDL_Texture* _texture, SDL_Rect _rect, SDL_Rect _rect2) : tree(_tree)
{
	texture = _texture;
	rect = { _rect.x, _rect.y, _rect.w, _rect.h };
	rect2 = { _rect2.x, _rect2.y, _rect2.w, _rect2.h };
	end_label = (UILabel*)App->gui->CreateUIElement(Label, 100, 200, nullptr, 400, 60);
	end_label->active = false;
}

Levels::~Levels()
{
}

bool Levels::Update(float dt)
{
	SDL_Rect to_blit = NULLRECT;

	if (one_time) {
		end_level_FX = App->audio->LoadFx("audio/fx/end_level_FX.wav");
		one_time = false;
	}
	if (tree->tree_cubes_list.count() < 3) {
		play = true;
	}

	// Is following the circuit ?
	if (GetCurrentLevelPoint() != -1 && !level_ended && tree->center_point_top.y <= starting_point)
	{
		accomplished_distance -= tree->center_point_top.y - last_point;
		last_point = tree->center_point_top.y;
		to_blit = { rect.x, rect.y, rect.w, rect.h };
	}
	else
	{
		last_point = tree->center_point_top.y;
		to_blit = { rect2.x, rect2.y, rect2.w, rect2.h };
	}

	// Circuit end
	if (tree->center_point_top.y <= starting_point - level_distance)
	{
		to_blit = { rect.x, rect.y, rect.w, rect.h };
		tree->speed = 0;
		level_ended = true;
		level_finished = true;

		if (play) {
			App->audio->PlayFx(end_level_FX);
			play = false;
		}

		if (App->scene->num_birds != 0) {
			int birds_not_nested = App->scene->num_birds - App->scene->nested;
			App->gui->CreateUIElement(Window, 50, 200, nullptr, 300, 300);
			iPoint pos(0, 0);
				while (App->scene->num_birds != 0) {
					if (App->scene->nested != 0) {
						App->scene->nested--;
					}
					else if (birds_not_nested != 0) {
						birds_not_nested--;
					}
					App->scene->num_birds--;
				}
		}
		


		if(accomplished_distance != 0)
			final_percentage = ((accomplished_distance * 100) / level_distance);
			
		//end_label->active = true;
		////p2SString txt("Level completed");
		//end_label->SetText(txt.GetString());
	}

	for (int i = 0; i < level_points_list.count(); i++)
	{
		SDL_Rect rect2; rect2 = { level_points_list[i].pos.x, level_points_list[i].pos.y, level_points_list[i].width, level_points_list[i].height };
		//App->render->DrawQuad(rect2, 0, 255, 0, 255, false);

		App->render->Blit(texture, level_points_list[i].pos.x, level_points_list[i].pos.y, &to_blit);
	}

	return true;
}

void Levels::SetLevel(int level)
{
	CleanLevel();
	current_level = level;
	level_ended = false;
	level_finished = false;
	final_percentage = 0.0f;
	accomplished_distance = 0;

	switch (level)
	{
	case 1:
		Level1();
		break;
	case 2:
		Level2();
		break;
	case 3:
		Level3();
		break;
	case 4:
		Level4();
		break;
	case 5:
		Level5();
		break;
	case 6:
		Level6();
		break;
	default:

		break;
	}

	starting_point = last_point = level_points_list.start->data.pos.y + level_points_list.start->data.height;
	level_distance = GetLevelDistance();
}

void Levels::CreateLevelPoint(iPoint pos, int w, int h)
{
	LevelPoint levelpoint(pos, w, h);
	level_points_list.add(levelpoint);
}

void Levels::CleanLevel()
{
	level_points_list.clear();
	ClearBirds();
}

int Levels::GetLevelDistance()
{
	int distance = 0;

	for (int i = 0; i < level_points_list.count(); i++)
	{
		distance += level_points_list[i].height;
	}

	return distance;
}

int Levels::GetCurrentLevelPoint()
{
	if (tree->center_point_top.y <= starting_point)
	{
		int i = 0;
		for (; i < level_points_list.count(); i++)
		{
			if (tree->center_point_top.x > level_points_list[i].pos.x && tree->center_point_top.x < level_points_list[i].pos.x + level_points_list[i].width)
			{
				if (tree->center_point_top.y > level_points_list[i].pos.y -1 && tree->center_point_top.y < level_points_list[i].pos.y + level_points_list[i].height + 1)
				{
					return i;
				}
			}
		}
	}

	return -1;
}

void Levels::ClearBirds() const
{
	for (p2List_item<Entity*>* bird_ent = App->entities->GetFirstEntity(); bird_ent; bird_ent = bird_ent->next) {
		if (bird_ent->data->GetType() == bird){
			App->entities->DeleteEntity(bird_ent->data);
		}
	}
}

void Levels::Level1()
{
	CreateLevelPoint(iPoint(300, 750), 100, 100);
	CreateLevelPoint(iPoint(300, 650), 100, 100);
	CreateLevelPoint(iPoint(300, 550), 100, 100);
	CreateLevelPoint(iPoint(300, 450), 100, 100);
	CreateLevelPoint(iPoint(310, 350), 100, 100);
	CreateLevelPoint(iPoint(320, 250), 100, 100);
	CreateLevelPoint(iPoint(320, 150), 100, 100);
	CreateLevelPoint(iPoint(320, 50), 100, 100);
	CreateLevelPoint(iPoint(320, -50), 100, 100);
	CreateLevelPoint(iPoint(320, -150), 100, 100);
	CreateLevelPoint(iPoint(300, -250), 100, 100);
	CreateLevelPoint(iPoint(290, -350), 100, 100);
	CreateLevelPoint(iPoint(280, -450), 100, 100);
	CreateLevelPoint(iPoint(260, -550), 100, 100);
	CreateLevelPoint(iPoint(250, -650), 100, 100);
	CreateLevelPoint(iPoint(230, -750), 100, 100);
	CreateLevelPoint(iPoint(230, -850), 100, 100);
	CreateLevelPoint(iPoint(230, -950), 100, 100);
	CreateLevelPoint(iPoint(230, -1050), 100, 100);
	CreateLevelPoint(iPoint(240, -1150), 100, 100);
	CreateLevelPoint(iPoint(250, -1250), 100, 100);
	CreateLevelPoint(iPoint(260, -1350), 100, 100);
}

void Levels::Level2()
{
	CreateLevelPoint(iPoint(300, 750), 100, 100);
	CreateLevelPoint(iPoint(300, 650), 100, 100);
	CreateLevelPoint(iPoint(300, 550), 100, 100);
	CreateLevelPoint(iPoint(310, 450), 100, 100);
	CreateLevelPoint(iPoint(330, 350), 100, 100);
	CreateLevelPoint(iPoint(360, 250), 100, 100);
	CreateLevelPoint(iPoint(360, 150), 100, 100);
	CreateLevelPoint(iPoint(330, 50), 100, 100);
	CreateLevelPoint(iPoint(300, -50), 100, 100);
	CreateLevelPoint(iPoint(270, -150), 100, 100);
	CreateLevelPoint(iPoint(250, -250), 100, 100);
	CreateLevelPoint(iPoint(240, -350), 100, 100);
	CreateLevelPoint(iPoint(260, -450), 100, 100);
	CreateLevelPoint(iPoint(280, -550), 100, 100);
	CreateLevelPoint(iPoint(310, -650), 100, 100);
	CreateLevelPoint(iPoint(350, -750), 100, 100);
	CreateLevelPoint(iPoint(380, -850), 100, 100);
	CreateLevelPoint(iPoint(400, -950), 100, 100);
	CreateLevelPoint(iPoint(410, -1050), 100, 100);
	CreateLevelPoint(iPoint(410, -1150), 100, 100);
	CreateLevelPoint(iPoint(390, -1250), 100, 100);
	CreateLevelPoint(iPoint(370, -1350), 100, 100);
	CreateLevelPoint(iPoint(360, -1450), 100, 100);
	CreateLevelPoint(iPoint(360, -1550), 100, 100);
	CreateLevelPoint(iPoint(380, -1650), 100, 100);
	CreateLevelPoint(iPoint(400, -1750), 100, 100);
	CreateLevelPoint(iPoint(410, -1850), 100, 100);
	CreateLevelPoint(iPoint(410, -1950), 100, 100);

}

void Levels::Level3()
{
	CreateLevelPoint(iPoint(300, 750), 100, 100);
	CreateLevelPoint(iPoint(300, 650), 100, 100);
	CreateLevelPoint(iPoint(300, 550), 100, 100);
	CreateLevelPoint(iPoint(270, 450), 100, 100);
	CreateLevelPoint(iPoint(230, 350), 100, 100);
	CreateLevelPoint(iPoint(190, 250), 100, 100);
	CreateLevelPoint(iPoint(140, 150), 100, 100);
	CreateLevelPoint(iPoint(130, 50), 100, 100);
	CreateLevelPoint(iPoint(140, -50), 100, 100);
	CreateLevelPoint(iPoint(170, -150), 100, 100);
	CreateLevelPoint(iPoint(220, -250), 100, 100);
	CreateLevelPoint(iPoint(270, -350), 100, 100);
	CreateLevelPoint(iPoint(310, -450), 100, 100);
	CreateLevelPoint(iPoint(370, -550), 100, 100);
	CreateLevelPoint(iPoint(440, -650), 100, 100);
	CreateLevelPoint(iPoint(500, -750), 100, 100);
	CreateLevelPoint(iPoint(500, -850), 100, 100);
	CreateLevelPoint(iPoint(440, -950), 100, 100);
	CreateLevelPoint(iPoint(370, -1050), 100, 100);
	CreateLevelPoint(iPoint(310, -1150), 100, 100);
	CreateLevelPoint(iPoint(260, -1250), 100, 100);
	CreateLevelPoint(iPoint(260, -1350), 100, 100);
	CreateLevelPoint(iPoint(310, -1450), 100, 100);
	CreateLevelPoint(iPoint(360, -1550), 100, 100);
	CreateLevelPoint(iPoint(400, -1650), 100, 100);
	CreateLevelPoint(iPoint(430, -1750), 100, 100);
	CreateLevelPoint(iPoint(370, -1850), 100, 100);
	CreateLevelPoint(iPoint(340, -1950), 100, 100);
	CreateLevelPoint(iPoint(340, -2050), 100, 100);
	CreateLevelPoint(iPoint(380, -2150), 100, 100);
	CreateLevelPoint(iPoint(410, -2250), 100, 100);
	CreateLevelPoint(iPoint(400, -2350), 100, 100);
	CreateLevelPoint(iPoint(400, -2450), 100, 100);
}

void Levels::Level4()
{
	CreateLevelPoint(iPoint(300, 750), 100, 100);
	CreateLevelPoint(iPoint(300, 650), 100, 100);
	CreateLevelPoint(iPoint(300, 550), 100, 100);
	CreateLevelPoint(iPoint(250, 450), 100, 100);
	CreateLevelPoint(iPoint(200, 350), 100, 100);
	CreateLevelPoint(iPoint(150, 250), 100, 100);
	CreateLevelPoint(iPoint(100, 150), 100, 100);
	CreateLevelPoint(iPoint(50, 50), 100, 100);
	CreateLevelPoint(iPoint(50, -50), 100, 100);
	CreateLevelPoint(iPoint(100, -150), 100, 100);
	CreateLevelPoint(iPoint(150, -250), 100, 100);
	CreateLevelPoint(iPoint(200, -350), 100, 100);
	CreateLevelPoint(iPoint(180, -450), 100, 100);
	CreateLevelPoint(iPoint(130, -550), 100, 100);
	CreateLevelPoint(iPoint(60, -650), 100, 100);
	CreateLevelPoint(iPoint(40, -750), 100, 100);
	CreateLevelPoint(iPoint(40, -850), 100, 100);
	CreateLevelPoint(iPoint(40, -950), 100, 100);
	CreateLevelPoint(iPoint(60, -1050), 100, 100);
	CreateLevelPoint(iPoint(80, -1150), 100, 100);
	CreateLevelPoint(iPoint(100, -1250), 100, 100);
	CreateLevelPoint(iPoint(120, -1350), 100, 100);
	CreateLevelPoint(iPoint(140, -1450), 100, 100);
	CreateLevelPoint(iPoint(180, -1550), 100, 100);
	CreateLevelPoint(iPoint(230, -1650), 100, 100);
	CreateLevelPoint(iPoint(280, -1750), 100, 100);
	CreateLevelPoint(iPoint(260, -1850), 100, 100);
	CreateLevelPoint(iPoint(210, -1950), 100, 100);
	CreateLevelPoint(iPoint(200, -2050), 100, 100);
	CreateLevelPoint(iPoint(230, -2150), 100, 100);
	CreateLevelPoint(iPoint(280, -2250), 100, 100);
	CreateLevelPoint(iPoint(300, -2350), 100, 100);
	CreateLevelPoint(iPoint(360, -2450), 100, 100);
	CreateLevelPoint(iPoint(370, -2550), 100, 100);
	CreateLevelPoint(iPoint(400, -2650), 100, 100);
	CreateLevelPoint(iPoint(450, -2750), 100, 100);
	CreateLevelPoint(iPoint(480, -2850), 100, 100);
	CreateLevelPoint(iPoint(480, -2950), 100, 100);
	CreateLevelPoint(iPoint(480, -3050), 100, 100);
	CreateLevelPoint(iPoint(480, -3150), 100, 100);
}

void Levels::Level5()
{
	CreateLevelPoint(iPoint(300, 750), 100, 100);
	CreateLevelPoint(iPoint(300, 650), 100, 100);
	CreateLevelPoint(iPoint(300, 550), 100, 100);
	CreateLevelPoint(iPoint(250, 450), 100, 100);
	CreateLevelPoint(iPoint(200, 350), 100, 100);
	CreateLevelPoint(iPoint(175, 250), 100, 100);
	CreateLevelPoint(iPoint(150, 150), 100, 100);
	CreateLevelPoint(iPoint(175, 50), 100, 100);
	CreateLevelPoint(iPoint(200, -50), 100, 100);
	CreateLevelPoint(iPoint(250, -150), 100, 100);
	CreateLevelPoint(iPoint(300, -250), 100, 100);
	CreateLevelPoint(iPoint(350, -350), 100, 100);
	CreateLevelPoint(iPoint(410, -450), 100, 100);
	CreateLevelPoint(iPoint(450, -550), 100, 100);
	CreateLevelPoint(iPoint(475, -650), 100, 100);
	CreateLevelPoint(iPoint(450, -750), 100, 100);
	CreateLevelPoint(iPoint(410, -850), 100, 100);
	CreateLevelPoint(iPoint(350, -950), 100, 100);
	CreateLevelPoint(iPoint(300, -1050), 100, 100);
	CreateLevelPoint(iPoint(300, -1150), 100, 100);
	CreateLevelPoint(iPoint(320, -1250), 100, 100);
	CreateLevelPoint(iPoint(350, -1350), 100, 100);
	CreateLevelPoint(iPoint(390, -1450), 100, 100);
	CreateLevelPoint(iPoint(450, -1550), 100, 100);
	CreateLevelPoint(iPoint(490, -1650), 100, 100);
	CreateLevelPoint(iPoint(530, -1750), 100, 100);
	CreateLevelPoint(iPoint(560, -1850), 100, 100);
	CreateLevelPoint(iPoint(580, -1950), 100, 100);
	CreateLevelPoint(iPoint(590, -2050), 100, 100);
	CreateLevelPoint(iPoint(590, -2150), 100, 100);
	CreateLevelPoint(iPoint(585, -2250), 100, 100);
	CreateLevelPoint(iPoint(570, -2350), 100, 100);
	CreateLevelPoint(iPoint(490, -2450), 100, 100);
	CreateLevelPoint(iPoint(400, -2550), 100, 100);
	CreateLevelPoint(iPoint(330, -2650), 100, 100);
	CreateLevelPoint(iPoint(280, -2750), 100, 100);
	CreateLevelPoint(iPoint(280, -2850), 100, 100);
	CreateLevelPoint(iPoint(300, -2950), 100, 100);
	CreateLevelPoint(iPoint(320, -3050), 100, 100);
	CreateLevelPoint(iPoint(300, -3150), 100, 100);
}

void Levels::Level6()
{
	CreateLevelPoint(iPoint(300, 750), 100, 100);
	CreateLevelPoint(iPoint(300, 650), 100, 100);
	CreateLevelPoint(iPoint(300, 550), 100, 100);
	CreateLevelPoint(iPoint(250, 450), 100, 100);
	CreateLevelPoint(iPoint(200, 350), 100, 100);
	CreateLevelPoint(iPoint(140, 250), 100, 100);
	CreateLevelPoint(iPoint(90, 150), 100, 100);
	CreateLevelPoint(iPoint(140, 50), 100, 100);
	CreateLevelPoint(iPoint(200, -50), 100, 100);
	CreateLevelPoint(iPoint(260, -150), 100, 100);
	CreateLevelPoint(iPoint(280, -250), 100, 100);
	CreateLevelPoint(iPoint(230, -350), 100, 100);
	CreateLevelPoint(iPoint(160, -450), 100, 100);
	CreateLevelPoint(iPoint(100, -550), 100, 100);
	CreateLevelPoint(iPoint(50, -650), 100, 100);
	CreateLevelPoint(iPoint(40, -750), 100, 100);
	CreateLevelPoint(iPoint(80, -850), 100, 100);
	CreateLevelPoint(iPoint(130, -950), 100, 100);
	CreateLevelPoint(iPoint(180, -1050), 100, 100);
	CreateLevelPoint(iPoint(230, -1150), 100, 100);
	CreateLevelPoint(iPoint(280, -1250), 100, 100);
	CreateLevelPoint(iPoint(330, -1350), 100, 100);
	CreateLevelPoint(iPoint(380, -1450), 100, 100);
	CreateLevelPoint(iPoint(430, -1550), 100, 100);
	CreateLevelPoint(iPoint(480, -1650), 100, 100);
	CreateLevelPoint(iPoint(540, -1750), 100, 100);
	CreateLevelPoint(iPoint(590, -1850), 100, 100);
	CreateLevelPoint(iPoint(540, -1950), 100, 100);
	CreateLevelPoint(iPoint(500, -2050), 100, 100);
	CreateLevelPoint(iPoint(520, -2150), 100, 100);
	CreateLevelPoint(iPoint(570, -2250), 100, 100);
	CreateLevelPoint(iPoint(600, -2350), 100, 100);
	CreateLevelPoint(iPoint(570, -2450), 100, 100);
	CreateLevelPoint(iPoint(520, -2550), 100, 100);
	CreateLevelPoint(iPoint(470, -2650), 100, 100);
	CreateLevelPoint(iPoint(470, -2750), 100, 100);
	CreateLevelPoint(iPoint(420, -2850), 100, 100);
	CreateLevelPoint(iPoint(400, -2950), 100, 100);
	CreateLevelPoint(iPoint(370, -3050), 100, 100);
	CreateLevelPoint(iPoint(320, -3150), 100, 100);
	CreateLevelPoint(iPoint(300, -3250), 100, 100);
	CreateLevelPoint(iPoint(260, -3350), 100, 100);
	CreateLevelPoint(iPoint(240, -3450), 100, 100);
	CreateLevelPoint(iPoint(260, -3550), 100, 100);
	CreateLevelPoint(iPoint(280, -3650), 100, 100);
	CreateLevelPoint(iPoint(300, -3750), 100, 100);
	CreateLevelPoint(iPoint(300, -3850), 100, 100);
	CreateLevelPoint(iPoint(300, -3950), 100, 100);
}
