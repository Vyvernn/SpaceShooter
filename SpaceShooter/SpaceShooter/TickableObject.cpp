#include "TickableObject.h"
//#include "World.h"
#include "CollisionComponent.h"

TickableObject::TickableObject(std::string textureFilePath, World* world)
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
	if (ICollisionInterface* CollisionInterface = dynamic_cast<ICollisionInterface*>(this))
	{
		CollisionInterface->Position = sprite.getPosition();
	}
}
