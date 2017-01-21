#ifndef _WINDOSCILLATINGBAR_
#define _WINDOSCILLATINGBAR_

#include "j1Render.h"
#include "j1Timer.h"

class UIWindow;
class UIImage;
class SDL_Rect;
class Sprite2D;

class WindOscillatingBar {
public:
	WindOscillatingBar(int x, int y, int w, int h);
	~WindOscillatingBar();

	void UpdateBar();

	iPoint GetPosition();

	const float GetOffset() const;
	const void SetOffset(float _offset);
	const void ResetOffset();
private:
	UIWindow*		wind_window = nullptr;
	UIImage*		wind_bar = nullptr;


	float			angle = 0;

	SDL_Rect		window_rect = NULLRECT;
	SDL_Rect		bar_rect = NULLRECT;
	
	bool play = false;

	bool one_time = true;
	uint soft_wind_FX = NULL;
	uint hard_wind_FX = NULL;
	uint light_wind_FX = NULL;

	float offset = 0;

	j1Timer timer;
	int random_num;
	bool start_timer = true;
public:

	float wind_power = 0;	
	Sprite2D*		sprite;
};

#endif _WINDOSCILLATINGBAR_