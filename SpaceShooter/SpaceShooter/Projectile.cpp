#include "Projectile.h"
#include "ShooterFunction.h"

// The value passed here should be the ship's speed and damage
Projectile::Projectile(float givenSpeed, float givenDamage, World* givenWorld) 
	: TickableObject("Assets/PNG/Effects/BasicProjectile.png", givenWorld)
{
	speed = givenSpeed;
	damage = givenDamage;
	isTickOn = false;		// Turn this on when we call Ship.Fire
	Radius = 5;
	bIsInstigatingCollision = false;
	bCanBeHit = false;
}

void Projectile::Move(float deltaTime)
{
	// TO-DO: move in the facing direction
	// Move up every frame for now
	sprite.move(0.f, -speed * deltaTime);
}

void Projectile::Tick(float deltaTime)
{
	if (!isTickOn) { return; }
	bIsInstigatingCollision = true;
	Position = sprite.getPosition();
	Move(deltaTime);
	if (Position.y < -20.f)
	{
		OnExitedScreenSpace();
	}
}

void Projectile::Hit(ICollisionInterface* Instigator)
{
}

void Projectile::OnHit(ICollisionInterface* HitObject)
{
	//We don't really care if we're hit
	isTickOn = false;
	bIsInstigatingCollision = false;
}

void Projectile::OnExitedScreenSpace()
{
	isTickOn = false;
	bIsInstigatingCollision = false;
}

void Projectile::SetIsTickOn(bool value)
{
	isTickOn = value;
}
