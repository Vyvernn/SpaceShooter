#include "Projectile.h"
#include "ShooterFunction.h"

// The value passed here should be the ship's speed and damage
Projectile::Projectile(float givenSpeed, float givenDamage, World* world) 
	: TickableObject("Assets/PNG/Effects/BasicProjectile.png", world)
{
	speed = givenSpeed;
	damage = givenDamage;

	Radius = 5;

	// Also need to place the projectile in the position of the ship
}

void Projectile::Move(float deltaTime)
{

	// TO-DO: move in the facing direction
	// Move up every frame for now
	sprite.move(0.f, -speed * deltaTime);

	// Needs to have collision detection
}

void Projectile::Tick(float deltaTime)
{
	Position = sprite.getPosition();
	Move(deltaTime);
}

void Projectile::Hit(ICollisionInterface* Instigator)
{

}
