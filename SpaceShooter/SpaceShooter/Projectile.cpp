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
	Position = sprite.getPosition();
	Move(deltaTime);
}

void Projectile::Hit(ICollisionInterface* Instigator)
{
}

void Projectile::SetIsTickOn(bool value)
{
	isTickOn = value;
}
