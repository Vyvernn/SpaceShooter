#include "World.h"
#include "TickableObject.h"


void World::Initialise()
{

}

void World::Update()
{
	for (TickableObject* NextObject : ObjectList)
	{
		NextObject->Tick();
	}
}

void World::Draw(sf::RenderWindow* window)
{
	for (TickableObject* NextObject : ObjectList)
	{
		window->draw(*NextObject->Sprite);
	}
}
