#include "CollisionComponent.h"
#include "ShooterFunction.h"


void ICollisionInterface::CheckCollisionWith(ICollisionInterface* OtherObject)
{
	if (RadialSpriteCollision(Position, Radius, OtherObject->Position, Radius))
	{
		OtherObject->Hit(this);
	}
}
