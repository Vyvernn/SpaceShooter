#include "World.h"
#include "TickableObject.h"
#include "Ship.h"


void World::Initialise()
{
	Ship* ship = new Ship();

	ObjectList.push_back(ship);
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
