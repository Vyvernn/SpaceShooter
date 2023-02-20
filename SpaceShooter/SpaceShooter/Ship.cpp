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

void Ship::BeginPlay()
{
}

void Ship::Tick()
{
}
