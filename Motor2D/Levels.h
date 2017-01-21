#ifndef _LEVELS_H_
#define _LEVELS_H_

#include "Sprite2D.h"
#include "Entity.h"

class Tree;

struct LevelPoint
{
	LevelPoint() {  };
	LevelPoint(iPoint _pos, int _width, int _height, SDL_Rect _rect)
	{
		pos = _pos;
		width = _width;
		height = _height;
		rect = _rect;
	}

	iPoint pos;
	int width = 0;
	int height = 0;
	SDL_Rect rect;
};

class Levels
{
public:
	Levels(Tree* tree);

	~Levels();

	bool Update(float dt);

	void SetLevel(int level);
	void CreateLevelPoint(iPoint pos, int w, int h, SDL_Rect rect);
	void CleanLevel();
	int GetLevelDistance();
	int GetCurrentLevelPoint();

private:
	void Level1();
	SDL_Texture* texture = nullptr;

public:
	int current_level = 0;
	int level_distance = 0;
	int starting_point = 0;
	int accomplished_distance = 0;

	int last_point = 0;

	bool level_ended = false;

	float final_percentage = 0.0f;

private:
	bool debug = true;
	p2List<LevelPoint> level_points_list;
	Tree* tree = nullptr;


};
#endif // !_LEVELS_H_