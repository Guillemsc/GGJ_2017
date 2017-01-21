#ifndef _WINDOSCILLATINGBAR_
#define _WINDOSCILLATINGBAR_

class UIWindow;
class UIImage;

class WindOscillatingBar {
public:
	WindOscillatingBar(int x, int y, int w, int h);
	~WindOscillatingBar();

	void UpdateBar();

private:
	UIWindow*		wind_window;
	UIImage*		wind_bar;

	float			angle = 0;
};

#endif _WINDOSCILLATINGBAR_