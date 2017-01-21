#include "WindOscillatingBar.h"
#include "UIWindow.h"
#include "UIImage.h"
#include "j1Input.h"
#include "Sprite2D.h"

WindOscillatingBar::WindOscillatingBar(int x, int y, int w, int h)
{
	pugi::xml_document doc;
	App->LoadXML("wind_oscillating_bar.xml", doc);

	pugi::xml_node node = doc.child("config");

	window_rect = { node.child("window").attribute("x").as_int(), node.child("window").attribute("y").as_int(),
				   node.child("window").attribute("w").as_int(), node.child("window").attribute("h").as_int() };

	bar_rect = { node.child("bar").attribute("x").as_int(),	bar_rect.y = node.child("bar").attribute("y").as_int(),
				 node.child("bar").attribute("w").as_int(),	bar_rect.h = node.child("bar").attribute("h").as_int() };

	wind_window = (UIWindow*)App->gui->CreateUIElement(Window, x, y, nullptr, window_rect.w, window_rect.h);
	wind_window->SetRect(window_rect); //adjust to final one

	wind_bar = (UIImage*)App->gui->CreateUIElement(Image, 0, 0, wind_window, bar_rect.w, bar_rect.h);
	wind_bar->SetRect(bar_rect); //adjust to final one

	sprite = new Sprite2D();
	sprite->LoadTexture("Sprites/UIsheet.png");
	sprite->LoadAnimations(node);
}

WindOscillatingBar::~WindOscillatingBar()
{
}

void WindOscillatingBar::UpdateBar()
{
	wind_bar->position.x = (wind_window->position.w - wind_bar->position.w) / 2 + ((wind_window->position.w - wind_bar->position.w) / 2)*sin(angle);

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
		wind_power = 10 * sin(angle);
		
		sprite->SetAnimation(Idle);

		sprite->GetAnim()->Reset();
	}
	if (!sprite->GetAnim()->Finished()) {
		App->render->Blit(sprite->GetTexture(), wind_bar->position.x, wind_bar->position.y, &sprite->GetAnim()->GetCurrentFrameRect(), false);
	}
	angle += 0.05;

}
