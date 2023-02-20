#include "TickableObject.h"

TickableObject::TickableObject(std::string spriteFilePath)
{
	if (texture.loadFromFile(spriteFilePath))
	{
		
		sprite.setTexture(texture, true);
		sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	}
}

void TickableObject::Tick(float deltaTime)
{
}
