#include "World.h"
#include "TickableObject.h"
#include "Ship.h"
#include "Projectile.h"
#include "CollisionComponent.h"
#include <stdlib.h>
#include <time.h>

map<string, sf::Texture> World::TextureMap;

World::World()
{
	Ship* ship = new Ship(425, this);

	ObjectList.push_back(ship);

	int maxProjectiles = 40;
	for (int i = 0; i < maxProjectiles; i++)
	{
		Projectile* projectile = new Projectile(750, 5, this);

		// Set starting position to outside of the screen
		projectile->sprite.move(20000, 20000);

		// Put them in this list and it will be drawn and shown in the screen
		ObjectList.push_back(projectile);

		// Keep track of ship projectiles seperately (in a queue)
		ProjectileList.push(projectile);
	}

	// Initialize random seed
	srand(time(NULL));

	int maxAsteroids = 5;
	for (int i = 0; i < maxAsteroids; i++)
	{
		// Random between 0 and 1919
		int randNumX = rand() % 1920;								
		int randNumY = rand() % 1080;

		// Random between 1 and 250
		int asteroidSpeed = rand() % 250 + 1;
		int asteroidDirectionX = rand() % 360 + (-180);
		int asteroidDirectionY = rand() % 360 + (-180);
		Projectile* asteroid = new Projectile(asteroidSpeed, 10, this);
		asteroid->SetDirection(sf::Vector2f(asteroidDirectionX, asteroidDirectionY));

		// Randomly set the starting position of each asteroid
		asteroid->sprite.move(randNumX, randNumY);
		asteroid->SetIsTickOn(true);
		//asteroid->bIsInstigatingCollision = true;

		// Add to the list so it can be drawn and seen in the world
		ObjectList.push_back(asteroid);
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
