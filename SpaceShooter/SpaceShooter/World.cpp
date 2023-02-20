#include "World.h"
#include "TickableObject.h"
#include "Ship.h"
#include "Projectile.h"


World::World()
{
	Ship* ship = new Ship();

	ObjectList.push_back(ship);

	ship = new Ship();
	ship->sprite.move(400, 200);
	ObjectList.push_back(ship);

	Projectile* projectile = new Projectile(20, 5);

	projectile->sprite.move(600, 400);

	ObjectList.push_back(projectile);


	LastFrameTime = clock.getElapsedTime();
}


void World::Update()
{
	sf::Time NewFrameTime = clock.getElapsedTime();

	float deltaTime = NewFrameTime.asSeconds() - LastFrameTime.asSeconds();

	//In case we need to cap framerate
	/*if (deltaTime > 16)
	{*/

		for (TickableObject* NextObject : ObjectList)
		{
			NextObject->Tick(deltaTime);
		}

		LastFrameTime = NewFrameTime;
	/*}*/

}

void World::Draw(sf::RenderWindow* window)
{
	for (TickableObject* NextObject : ObjectList)
	{
		window->draw(NextObject->sprite);
	}
}
