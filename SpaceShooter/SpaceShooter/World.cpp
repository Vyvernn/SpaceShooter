#include "World.h"
#include "TickableObject.h"
#include "Ship.h"
#include "Projectile.h"

map<string, sf::Texture> World::TextureMap;

World::World()
{
	Ship* ship = new Ship();

	ObjectList.push_back(ship);

	ship = new Ship();
	ship->sprite.move(400, 200);
	ObjectList.push_back(ship);

	Projectile* projectile = new Projectile(0, 5);

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
