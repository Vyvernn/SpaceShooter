#include "Ship.h"

Ship::Ship()
{
	// Default speed for now is 5
	speed = 5.f;
}

Ship::Ship(float& givenSpeed)
{
	speed = givenSpeed;
}

void Ship::Movement(float inputX, float inputY, float deltaTime)
{
	// Move up, down, left, and right
	Sprite->move( (inputX * speed * deltaTime) , (inputY * speed * deltaTime) );
}

void Ship::Fire()
{
	// Fire projectile from current position (and fire in that direction)
	// Move the projectile
	// Destroy the projectile for N seconds OR when it collides with another GameObject

	// Fire projectile is essentially
	// Instantiate projectile obj
	// Draw a projectile sprite
	// Set its values (TimeAlive, damage, speed)
	// Move the projectile

	// no longer within the game screen or collision 

}

void Ship::BeginPlay()
{
}

void Ship::Tick()
{
}
