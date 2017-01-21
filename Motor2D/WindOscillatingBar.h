#ifndef _WINDOSCILLATINGBAR_
#define _WINDOSCILLATINGBAR_

#include "j1Render.h"

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
private:
	UIWindow*		wind_window;
	UIImage*		wind_bar;


	float			angle = 0;

	SDL_Rect		window_rect;
	SDL_Rect		bar_rect;
	
	bool play = false;

public:
	float wind_power = 0;	
	Sprite2D*		sprite;
};

#endif _WINDOSCILLATINGBAR_