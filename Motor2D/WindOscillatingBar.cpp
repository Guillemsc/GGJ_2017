#include "WindOscillatingBar.h"
#include "UIWindow.h"
#include "UIImage.h"

WindOscillatingBar::WindOscillatingBar(int x, int y, int w, int h)
{
	wind_window = (UIWindow*)App->gui->CreateUIElement(Window, x, y, nullptr, w, h);
	wind_window->SetRect({ 20,20,60,30 }); //adjust to final one

	wind_bar = (UIImage*)App->gui->CreateUIElement(Image, 0, 0, wind_window, w/20, h);
	wind_bar->SetRect({ 20,20,60,30 }); //adjust to final one
}

WindOscillatingBar::~WindOscillatingBar()
{
}

void WindOscillatingBar::UpdateBar()
{
	wind_bar->position.x = (wind_window->position.w - wind_bar->position.w) / 2 + ((wind_window->position.w - wind_bar->position.w) / 2)*sin(angle);
	angle += 0.05;
}
