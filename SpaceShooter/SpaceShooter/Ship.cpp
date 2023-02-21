#include "Ship.h"
#include <iostream>
#include "Projectile.h"


Ship::Ship() :
	TickableObject("Assets\\PNG\\playerShip1_red.png")
{
	// Default speed for now is 425
	speed = 425.f;

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

void Ship::Fire(World* world)
{
	//Projectile* proj = world->GetProjectiles()[0];
	//world->GetObjectList().push_back(proj);
	std::cout << "Position of sprite: ";
	//std::cout << sprite.getPosition().x << "," << sprite.getPosition().y << std::endl;

 	//Projectile* proj = world->GetProjectiles()[0];
	for (int i = 0; i; i++)
	{

	}
}

void Ship::Tick(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		horizontalValue = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		horizontalValue = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		// Pressing up needs to have negative value, otherwise it is moving down
		verticalValue = -1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		verticalValue = 1;
	}

	// Need delta time
	Movement(horizontalValue, verticalValue, deltaTime);

	horizontalValue = 0;
	verticalValue = 0;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		//Fire();
	}
}

void Ship::OnHealthReachZero()
{
	// Implement health zero logic here
}

void Ship::Hit(ICollisionInterface* Instigator)
{
	if (Projectile* projectile = dynamic_cast<Projectile*>(Instigator))
	{
		TakeDamage(projectile->GetDamage());
	}
}
