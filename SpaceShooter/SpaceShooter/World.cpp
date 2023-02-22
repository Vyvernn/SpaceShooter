#include "World.h"
#include "TickableObject.h"
#include "Ship.h"
#include "Projectile.h"
#include "CollisionComponent.h"

map<string, sf::Texture> World::TextureMap;

World::World()
{
	Ship* ship = new Ship(425, this);

	ObjectList.push_back(ship);

	int maxProjectiles = 40;
	for (int i = 0; i < maxProjectiles; i++)
	{
		Projectile* projA = new Projectile(750, 5, this);
		projA->sprite.move(20000, 20000);				// Moves outside of the screen
		ObjectList.push_back(projA);					// Put them in this list you will be drawing them
		ProjectileList.push(projA);				// This is a queue		// Putting in them here just stores them.
	}



	LastFrameTime = clock.getElapsedTime();
}


void World::Update()
{
	sf::Time NewFrameTime = clock.getElapsedTime();

	float deltaTime = NewFrameTime.asSeconds() - LastFrameTime.asSeconds();

	for (TickableObject* ObjectA : ObjectList)
	{
		if (ICollisionInterface* InterfaceA = dynamic_cast<ICollisionInterface*>(ObjectA))
		{
			if (InterfaceA->bIsInstigatingCollision)
			{
				for (TickableObject* ObjectB : ObjectList)
				{
					if (ObjectA != ObjectB)
					{
						if (ICollisionInterface* InterfaceB = dynamic_cast<ICollisionInterface*>(ObjectB))
						{
							if (InterfaceB->bCanBeHit)
							{
								InterfaceA->CheckCollisionWith(InterfaceB);
							}
						}
					}
				}
			}
			
		}
	}

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

		if (IHealthInterface* HealthInterface = dynamic_cast<IHealthInterface*>(NextObject))
		{
			if (HealthInterface->bShowHealthBar)
			{
				window->draw(*HealthInterface->HealthBarSprite);
				window->draw(*HealthInterface->HealthBarFillShape);
			}
		}
	}
}

bool World::LoadTexture(string filepath)
{
	//if we've already loaded this texture then just return
	if (TextureMap.count(filepath) == 1)
	{
		return true;
	}

	//else try load the texture
	sf::Texture texture;
	if (texture.loadFromFile(filepath))
	{
		TextureMap[filepath] = texture;
		return true;
	}

	//if we can't find it then return false
	return false;
}

sf::Texture World::GetTexture(string filepath)
{
	//Check whether we've loaded this texture first
	if (TextureMap.count(filepath) == 1)
	{
		return TextureMap[filepath];
	}

	//Attempt to load the texture next
	if (LoadTexture(filepath))
	{
		return TextureMap[filepath];
	}

	//"An attempt was made"
	return sf::Texture();
}
