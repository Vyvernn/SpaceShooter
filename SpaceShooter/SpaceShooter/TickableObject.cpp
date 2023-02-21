#include "TickableObject.h"
#include "World.h"

TickableObject::TickableObject(std::string textureFilePath)
{
	texture = World::GetTexture(textureFilePath);

	if (&texture)
	{
		sprite.setTexture(texture, true);
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	}
}


void TickableObject::Tick(float deltaTime)
{
}
