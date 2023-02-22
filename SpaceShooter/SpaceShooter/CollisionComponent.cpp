#include "CollisionComponent.h"
#include "ShooterFunction.h"


void ICollisionInterface::CheckCollisionWith(ICollisionInterface* OtherObject)
{
	if (RadialSpriteCollision(Position, Radius, OtherObject->Position, Radius) && owner != OtherObject)
	{
		OtherObject->Hit(this);
		OnHit(OtherObject);
	}
}

void ICollisionInterface::SetOwner(ICollisionInterface* givenOwner)
{
	owner = givenOwner;
}
