#include "Levels.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "Tree.h"
#include "p2Log.h"
#include "UILabel.h"
#include "j1Gui.h"

Levels::Levels(Tree* _tree) : tree(_tree)
{
	//texture = App->tex->Load("")
	end_label = (UILabel*)App->gui->CreateUIElement(Label, 100, 200, nullptr, 400, 60);
	end_label->active = true;
}

Levels::~Levels()
{
}

bool Levels::Update(float dt)
{
	for (int i = 0; i < level_points_list.count(); i++)
	{
		SDL_Rect rect; rect = { level_points_list[i].pos.x, level_points_list[i].pos.y, level_points_list[i].width, level_points_list[i].height };
		App->render->DrawQuad(rect, 0, 255, 0, 255, false);
	}

	// Is following the circuit ?
	if (GetCurrentLevelPoint() != -1 && !level_ended && tree->center_point_top.y <= starting_point)
	{
		accomplished_distance -= tree->center_point_top.y - last_point;
		last_point = tree->center_point_top.y;
	}
	else
	{
		last_point = tree->center_point_top.y;
	}

	// Circuit end
	if (tree->center_point_top.y <= starting_point - level_distance)
	{
		tree->speed = 0;
		level_ended = true;

		if(accomplished_distance != 0)
			final_percentage = ((accomplished_distance * 100) / level_distance);

		end_label->active = true;
		p2SString txt; txt.create("LEVEL %d COMPLETED WITH %.f PERCENT", current_level, final_percentage);
		end_label->SetText(txt.GetString());
	}

	return true;
}

void Levels::SetLevel(int level)
{
	CleanLevel();
	current_level = level;
	level_ended = false;
	final_percentage = 0.0f;

	switch (level)
	{
	case 1:
		Level1();
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
				if (tree->center_point_top.y > level_points_list[i].pos.y && tree->center_point_top.y < level_points_list[i].pos.y + level_points_list[i].height)
				{
					return i;
				}
			}
		}
	}

	return -1;
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