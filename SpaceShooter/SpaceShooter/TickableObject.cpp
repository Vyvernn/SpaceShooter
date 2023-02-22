#include "TickableObject.h"
//#include "World.h"
#include "CollisionComponent.h"

TickableObject::TickableObject(std::string textureFilePath, World* givenWorld)
{
	texture = World::GetTexture(textureFilePath);
	world = givenWorld;

	if (&texture)
	{
		sprite.setTexture(texture, true);
		sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	}
}


void TickableObject::Tick(float deltaTime)
{
}
