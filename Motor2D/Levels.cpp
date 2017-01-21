#include "Levels.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "Tree.h"
#include "p2Log.h"
#include "UILabel.h"
#include "j1Gui.h"

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
	SDL_Rect to_blit;
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

		if(accomplished_distance != 0)
			final_percentage = ((accomplished_distance * 100) / level_distance);

		end_label->active = true;
		p2SString txt; txt.create("LEVEL %d COMPLETED WITH %.f PERCENT", current_level, final_percentage);
		end_label->SetText(txt.GetString());
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
	final_percentage = 0.0f;

	switch (level)
	{
	case 1:
		Level1();
		break;
	case 2:
		Level2();

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
				if (tree->center_point_top.y > level_points_list[i].pos.y -1 && tree->center_point_top.y < level_points_list[i].pos.y + level_points_list[i].height + 1)
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

void Levels::Level2()
{
	CreateLevelPoint(iPoint(300, 750), 100, 100);
	CreateLevelPoint(iPoint(300, 650), 100, 100);
	CreateLevelPoint(iPoint(300, 550), 100, 100);
}
