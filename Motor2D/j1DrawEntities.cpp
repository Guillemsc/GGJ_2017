#include "j1DrawEntities.h"
#include "j1Entities.h"
#include "Entity.h"

j1DrawEntities::j1DrawEntities()
{
	name.create("draw_entities");
}

j1DrawEntities::~j1DrawEntities()
{
}

bool j1DrawEntities::Update(float dt)
{
	for (p2List_item<Entity*>* entity = App->entities->GetFirstEntity(); entity; entity = entity->next) {
		if (entity->data->draw_order == AfterScene)
			entity->data->Draw();
	}
	return true;
}
