#include "Bird.h"
#include "j1App.h"
#include "j1Scene.h"
#include "j1Render.h"

Bird::Bird(iPoint pos):Entity(bird,pos,"bird")
{
	info.SetAnimation(Run);
	draw_order = AfterAll;
}

Bird::~Bird()
{
}

bool Bird::Update(float dt)
{
	if(!nested){
		int pos_y = info.GetPos().y;
		if(info.GetPos().y<680)
			 pos_y = info.GetPos().y + speed*dt;
		int pos_x = info.GetPos().x + App->scene->GetWindForce()*20*dt;
		info.SetPos(iPoint(pos_x, pos_y));
	}
	if (!nested && info.GetPos().x > target_nest->info.GetPos().x - target_nest->info.GetAnim()->GetFrame(0).w / 4 +80 && info.GetPos().x < target_nest->info.GetPos().x + target_nest->info.GetAnim()->GetFrame(0).w / 4 + 80) {
		if (info.GetPos().y > target_nest->info.GetPos().y - target_nest->info.GetAnim()->GetFrame(0).h / 2 && info.GetPos().y < target_nest->info.GetPos().y + target_nest->info.GetAnim()->GetFrame(0).h / 2) {
			info.SetAnimation(Idle);
			iPoint bird_pos = target_nest->info.GetPos();
			bird_pos.x += 65;
			bird_pos.y -= 45;
			info.SetPos(bird_pos);
			nested = true;
		}
	}
	if (info.GetPos().y >= 680){
		info.SetAnimation(Idle);
		nested = true;
	}
	return true;
}

bool Bird::Draw()
{
	App->render->Blit(info.GetTexture(), info.GetPos().x, info.GetPos().y, &info.GetAnim()->GetCurrentFrameRect());
	return true;
}

void Bird::SetNest(Entity * nest)
{
	target_nest = nest;
}
