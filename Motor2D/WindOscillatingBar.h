#ifndef _WINDOSCILLATINGBAR_
#define _WINDOSCILLATINGBAR_

#include "j1Render.h"

class UIWindow;
class UIImage;
class SDL_Rect;

class WindOscillatingBar {
public:
	WindOscillatingBar(int x, int y, int w, int h);
	~WindOscillatingBar();

	void UpdateBar();

private:
	UIWindow*		wind_window;
	UIImage*		wind_bar;

	float			angle = 0;

	SDL_Rect		window_rect;
	SDL_Rect		bar_rect;


public:
	float wind_power = 0;
};

#endif _WINDOSCILLATINGBAR_