#include "World.h"
#include "TickableObject.h"
#include "Ship.h"
#include "CollisionComponent.h"
#include "Asteroid.h"
#include <stdlib.h>
#include <time.h>

map<string, sf::Texture> World::TextureMap;

World::World()
{


	/*vector<string> BigAsteroidImageFilePaths;
	
	BigAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_big1.png");
	BigAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_big2.png");
	BigAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_big3.png");
	BigAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_big4.png");
	BigAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_big1.png");
	BigAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_big2.png");
	BigAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_big3.png");
	BigAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_big4.png");
	

	vector<string> MediumAsteroidImageFilePaths;

	MediumAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_med1.png");
	MediumAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_med2.png");
	MediumAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_med1.png");
	MediumAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_med2.png");
	

	vector<string> SmallAsteroidImageFilePaths;

	SmallAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_small1.png");
	SmallAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_small2.png");
	SmallAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_small1.png");
	SmallAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_small2.png");
		

	vector<string> TinyAsteroidImageFilePaths;

	TinyAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_tiny1.png");
	TinyAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorBrown_tiny2.png");
	TinyAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_tiny1.png");
	TinyAsteroidImageFilePaths.push_back("Assets/PNG/Meteors/meteorGrey_tiny2.png");*/



	Ship* ship = new Ship(425, this);
	ship->sprite.setPosition(960, 540);

	ObjectList.push_back(ship);

	int maxProjectiles = 40;
	for (int i = 0; i < maxProjectiles; i++)
	{
		Projectile* projectile = new Projectile(750, 5, this, "Assets/PNG/Effects/BasicProjectile.png");

		// Set starting position to outside of the screen
		projectile->sprite.move(20000, 20000);

		// Put them in this list and it will be drawn and shown in the screen
		ObjectList.push_back(projectile);

		// Keep track of ship projectiles seperately (in a queue)
		ProjectileList.push(projectile);
	}

	// Initialize random seed
	srand(0);


	//Big Asteroids
	int maxBigAsteroids = 50;
	for (int i = 0; i < maxBigAsteroids; i++)
	{

		int asteroidSpeed = rand() % 150 + 100;
		int ImageIndex = rand() % BigAsteroidImageFilePaths.size();

		Asteroid* asteroid = new Asteroid(static_cast<float>(asteroidSpeed), 30, 35, this, BigAsteroidImageFilePaths[ImageIndex]);
		asteroid->Reset();
		ObjectList.push_back(asteroid);
	}


	//Medium Asteroids
	int maxMediumAsteroids = 40;
	for (int i = 0; i < maxMediumAsteroids; i++)
	{

		int asteroidSpeed = rand() % 150 + 150;
		int ImageIndex = rand() % MediumAsteroidImageFilePaths.size();

		Asteroid* asteroid = new Asteroid(static_cast<float>(asteroidSpeed), 10, 20, this, MediumAsteroidImageFilePaths[ImageIndex]);
		asteroid->Reset();
		ObjectList.push_back(asteroid);
	}

	//Small Asteroids
	int maxSmallAsteroids = 30;
	for (int i = 0; i < maxSmallAsteroids; i++)
	{


		int asteroidSpeed = rand() % 150 + 200;
		int ImageIndex = rand() % SmallAsteroidImageFilePaths.size();

		Asteroid* asteroid = new Asteroid(static_cast<float>(asteroidSpeed), 3, 10, this, SmallAsteroidImageFilePaths[ImageIndex]);
		asteroid->Reset();
		ObjectList.push_back(asteroid);
	}

	//tiny Asteroids
	int maxTinyAsteroids = 75;
	for (int i = 0; i < maxSmallAsteroids; i++)
	{

		int asteroidSpeed = rand() % 150 + 600;
		int ImageIndex = rand() % TinyAsteroidImageFilePaths.size();

		Asteroid* asteroid = new Asteroid(static_cast<float>(asteroidSpeed), 0, 5, this, TinyAsteroidImageFilePaths[0]);
		asteroid->Reset();
		ObjectList.push_back(asteroid);
	}


	

	LastFrameTime = clock.getElapsedTime();
}

World::~World()
{
	for (TickableObject* obj : ObjectList)
	{
		delete obj;
	}
}


void World::Update()
{
	sf::Time NewFrameTime = clock.getElapsedTime();

	float deltaTime = NewFrameTime.asSeconds() - LastFrameTime.asSeconds();

	//In case we need to cap framerate
	/*if (deltaTime > 16)
	{*/

	if (!bFirstTick)
	{
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
	}

	for (TickableObject* NextObject : ObjectList)
	{
		NextObject->Tick(deltaTime);
	}

	LastFrameTime = NewFrameTime;

	bFirstTick = false;
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
