#include "LevelSelect.h"
#include "j1App.h"
#include "j1Gui.h"
#include "UIButton.h"
#include "j1Scene.h"
#include "FirstScene.h"

LevelSelect::LevelSelect()
{
}

LevelSelect::~LevelSelect()
{
}

bool LevelSelect::Start()
{
	standard = { 639, 488, 202, 157 };
	highlighted = { 639, 488, 202, 157 };
	clicked = { 639, 488, 202, 157 };
	
	level1 = (UIButton*)App->gui->CreateUIElement(Button, X_, Y_, nullptr, 202, 157);
	level1->SetRects(standard, highlighted, clicked);
	level1->AddListener(App->scene);
	level2 = (UIButton*)App->gui->CreateUIElement(Button, X_ + W_, Y_, nullptr, 202, 157);
	level2->SetRects(standard, highlighted, clicked);
	level2->AddListener(App->scene);
	level3 = (UIButton*)App->gui->CreateUIElement(Button, X_ + W_ * 2, Y_, nullptr, 202, 157);
	level3->SetRects(standard, highlighted, clicked);
	level3->AddListener(App->scene);
	level4 = (UIButton*)App->gui->CreateUIElement(Button, X_, Y_ + H_, nullptr, 202, 157);
	level4->SetRects(standard, highlighted, clicked);
	level4->AddListener(App->scene);
	level5 = (UIButton*)App->gui->CreateUIElement(Button, X_ + W_, Y_ + H_, nullptr, 202, 157);
	level5->SetRects(standard, highlighted, clicked);
	level5->AddListener(App->scene);
	level6 = (UIButton*)App->gui->CreateUIElement(Button, X_ + W_ * 2, Y_ + H_, nullptr, 202, 157);
	level6->SetRects(standard, highlighted, clicked);
	level6->AddListener(App->scene);
	level7 = (UIButton*)App->gui->CreateUIElement(Button, X_, Y_ + H_ * 2, nullptr, 202, 157);
	level7->SetRects(standard, highlighted, clicked);
	level7->AddListener(App->scene);
	level8 = (UIButton*)App->gui->CreateUIElement(Button, X_ + W_, Y_ + H_ * 2, nullptr, 202, 157);
	level8->SetRects(standard, highlighted, clicked);
	level8->AddListener(App->scene);
	level9 = (UIButton*)App->gui->CreateUIElement(Button, X_ + W_ * 2, Y_ + H_ * 2, nullptr, 202, 157);
	level9->SetRects(standard, highlighted, clicked);
	level9->AddListener(App->scene);

	return true;
}

bool LevelSelect::PreUpdate()
{
	return true;
}

bool LevelSelect::Update(float dt)
{
	return true;
}

bool LevelSelect::PostUpdate()
{
	return true;
}

void LevelSelect::Draw()
{
}

bool LevelSelect::CleanUp()
{
	App->gui->DeleteUIElement(level1);
	App->gui->DeleteUIElement(level2);
	App->gui->DeleteUIElement(level3);
	App->gui->DeleteUIElement(level4);
	App->gui->DeleteUIElement(level5);
	App->gui->DeleteUIElement(level6);
	App->gui->DeleteUIElement(level7);
	App->gui->DeleteUIElement(level8);
	App->gui->DeleteUIElement(level9);
	return true;
}

void LevelSelect::UIReaction(UIElement * element, int react)
{
	switch (react) {
	case LeftClick:
		if (element == level1) {
			level1->Clicked();
		}
		else if (element == level2) {
			level2->Clicked();
		}
		else if (element == level3) {
			level3->Clicked();
		}
		else if (element == level4) {
			level4->Clicked();
		}
		else if (element == level5) {
			level5->Clicked();
		}
		else if (element == level6) {
			level6->Clicked();
		}
		else if (element == level7) {
			level7->Clicked();
		}
		else if (element == level8) {
			level8->Clicked();
		}
		else if (element == level9) {
			level9->Clicked();
		}
		break;
	case LeftClickUp:
		if (element == level1) {
			level1->Standard();
		}
		else if (element == level2) {
			level2->Standard();
		}
		else if (element == level3) {
			level3->Standard();
		}
		else if (element == level4) {
			level4->Standard();
		}
		else if (element == level5) {
			level5->Standard();
		}
		else if (element == level6) {
			level6->Standard();
		}
		else if (element == level7) {
			level7->Standard();
		}
		else if (element == level8) {
			level8->Standard();
		}
		else if (element == level9) {
			level9->Standard();
		}
		break;
	case MouseEnter:
		if (element == level1) {
			level1->Highlight();
		}
		else if (element == level2) {
			level2->Highlight();
		}
		else if (element == level3) {
			level3->Highlight();
		}
		else if (element == level4) {
			level4->Highlight();
		}
		else if (element == level5) {
			level5->Highlight();
		}
		else if (element == level6) {
			level6->Highlight();
		}
		else if (element == level7) {
			level7->Highlight();
		}
		else if (element == level8) {
			level8->Highlight();
		}
		else if (element == level9) {
			level9->Highlight();
		}
		break;
	case MouseLeave:
		if (element == level1) {
			level1->Standard();
		}
		else if (element == level2) {
			level2->Standard();
		}
		else if (element == level3) {
			level3->Standard();
		}
		else if (element == level4) {
			level4->Standard();
		}
		else if (element == level5) {
			level5->Standard();
		}
		else if (element == level6) {
			level6->Standard();
		}
		else if (element == level7) {
			level7->Standard();
		}
		else if (element == level8) {
			level8->Standard();
		}
		else if (element == level9) {
			level9->Standard();
		}
		break;
	}
}
