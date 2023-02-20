#include "World.h"
#include "TickableObject.h"
#include "Ship.h"


World::World()
{
	Ship* ship = new Ship();

	ObjectList.push_back(ship);

	ship = new Ship();
	ship->sprite.move(400, 200);
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
		window->draw(NextObject->sprite);
	}
}
