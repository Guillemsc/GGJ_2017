#include "WindOscillatingBar.h"
#include "UIWindow.h"
#include "UIImage.h"
#include "j1Input.h"
#include "Sprite2D.h"
#include "j1Audio.h"

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

	play = false;
}

WindOscillatingBar::~WindOscillatingBar()
{
}

void WindOscillatingBar::UpdateBar()
{
	wind_bar->position.x = (wind_window->position.w - wind_bar->position.w) / 2 + ((wind_window->position.w - wind_bar->position.w) / 2)*sin(angle) + offset;

	if (one_time) {
		soft_wind_FX = App->audio->LoadFx("audio/fx/soft_wind_FX.wav");
		hard_wind_FX = App->audio->LoadFx("audio/fx/hard_wind_FX.wav");
		one_time = false;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) {
		wind_power = 10 * sin(angle);
		play = true;
		if ((wind_power >= -10 && wind_power < -8) || (wind_power > 8 && wind_power <= 10)) {
			sprite->SetAnimation(Run);
			App->audio->PlayFx(hard_wind_FX);
		}
		else { 
			sprite->SetAnimation(Idle); 
			App->audio->PlayFx(soft_wind_FX);
		}
		sprite->GetAnim()->Reset();
	}
	
	if (!sprite->GetAnim()->Finished() && play) {
		App->render->Blit(sprite->GetTexture(), wind_bar->GetPosition().x - 60, wind_bar->GetPosition().y - 60, &sprite->GetAnim()->GetCurrentFrameRect(), false);
	}
	angle += 0.05;

}

iPoint WindOscillatingBar::GetPosition()
{
	return iPoint(wind_bar->position.x, wind_bar->position.y);
}

const float WindOscillatingBar::GetOffset() const
{
	return offset;
}

const void WindOscillatingBar::SetOffset(float _offset)
{
	offset = _offset;
}

const void WindOscillatingBar::ResetOffset() 
{
	offset = 0;
}
