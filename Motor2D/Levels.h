#ifndef _LEVELS_H_
#define _LEVELS_H_

#include "Sprite2D.h"
#include "Entity.h"

class Tree;
class UILabel;

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

private:
	void Level1();
	void Level2();
	void Level3();
	void Level4();
	void Level5();
	void Level6();

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

private:
	bool debug = true;
	p2List<LevelPoint> level_points_list;
	Tree* tree = nullptr;

	UILabel* end_label = nullptr;

};
#endif // !_LEVELS_H_