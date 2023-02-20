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

void Ship::Tick(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		horizontalValue = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		horizontalValue = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// Pressing up needs to have negative value, otherwise it is moving down
		verticalValue = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		verticalValue = 1;
	}

	// Need delta time
	Movement(horizontalValue, verticalValue, 1.f); 

	horizontalValue = 0;
	verticalValue = 0;
}

void Ship::OnHealthReachZero()
{
	// Implement health zero logic here
}