#include "Ship.h"

Ship::Ship() :
	TickableObject("Assets\\PNG\\playerShip1_red.png")
{
	// Default speed for now is 5
	speed = 5.f;
}

Ship::Ship(float givenSpeed) :
	TickableObject("Assets\\PNG\\playerShip1_red.png")
{
	speed = givenSpeed;
}

void Ship::Movement(float inputX, float inputY, float deltaTime)
{
	// Move up, down, left, and right
	sprite.move( (inputX * speed * deltaTime) , (inputY * speed * deltaTime) );
}

void Ship::Fire()
{
}

void Ship::Tick()
{

}
