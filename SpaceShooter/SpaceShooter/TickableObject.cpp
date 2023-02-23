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
		sprite.setOrigin(static_cast<float>(texture.getSize().x) / 2.f, static_cast<float>(texture.getSize().y) / 2.f);
	}
}


void TickableObject::Tick(float deltaTime)
{
}
