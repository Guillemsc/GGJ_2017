#ifndef _LEVELS_H_
#define _LEVELS_H_

#include "Sprite2D.h"
#include "Entity.h"

class Tree;
class UILabel;
class UIImage;
class UIButton;

struct LevelPoint
{
	LevelPoint() {  };
	LevelPoint(iPoint _pos, int _width, int _height)
	{
		pos = _pos;
		width = _width;
		height = _height;
	}

	iPoint pos;
	int width = 0;
	int height = 0;

};

class Levels
{
public:
	Levels(Tree* tree, SDL_Texture* texture, SDL_Rect shadow, SDL_Rect shadow_red);

	~Levels();

	bool Update(float dt);

	void SetLevel(int level);
	void CreateLevelPoint(iPoint pos, int w, int h);
	void CleanLevel();
	int GetLevelDistance();
	int GetCurrentLevelPoint();

	void ClearBirds() const;
	void ActiveStars() const;
	void CanChangeLevel(bool boolean);
	const bool GetCanChangeLevel() const;
private:
	void Level1();
	void Level2();
	void Level3();
	void Level4();
	void Level5();
	void Level6();

	void ResetStars();
public:
	int current_level = 0;
	int level_distance = 0;
	int starting_point = 0;
	int accomplished_distance = 0;

	int last_point = 0;

	bool level_ended = false;
	bool level_finished = false;

	float final_percentage = 0.0f;

	SDL_Texture* texture = nullptr;
	SDL_Rect rect = NULLRECT;
	SDL_Rect rect2 = NULLRECT;

	UIButton*	next_level_button = nullptr;
	UIButton*	retry_button = nullptr;
	UIButton*	menu_button = nullptr;

	UIImage*	star1 = nullptr;
	UIImage*	star2 = nullptr;
	UIImage*	star3 = nullptr;

	UIImage*	birds = nullptr;
	UIImage*	nest_birds = nullptr;
	UILabel*	num_birds = nullptr;
	UILabel*	num_nest_birds = nullptr;

	SDL_Rect	highlight = NULLRECT;
	SDL_Rect	standard = NULLRECT;
private:
	bool debug = true;
	p2List<LevelPoint> level_points_list;
	Tree* tree = nullptr;

	UILabel* end_label = nullptr;

	bool play = true;
	bool one_time = true;
	uint end_level_FX = NULL;

	bool can_change_level = false;
};
#endif // !_LEVELS_H_