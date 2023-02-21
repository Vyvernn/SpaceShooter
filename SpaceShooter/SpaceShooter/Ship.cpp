#include "Ship.h"
#include <iostream>
#include "Projectile.h"

Ship::Ship(float givenSpeed, World* world) :
	TickableObject("Assets\\PNG\\playerShip1_red.png", world)
{
	speed = 425;
	speed = givenSpeed;
	Radius = max(sprite.getGlobalBounds().height, sprite.getGlobalBounds().width) / 2;

	InitHealthBar("Assets\\PNG\\UI\\buttonRed.png");
}

void Ship::Movement(float inputX, float inputY, float deltaTime)
{
	// Move up, down, left, and right
	sprite.move( (inputX * speed * deltaTime) , (inputY * speed * deltaTime) );
}

void Ship::Fire()
{
	// Enable the projectile Tick
	world->GetProjectileList()[0]->SetIsTickOn(true);
	// "Spawn" projectiles from the player's position
	world->GetProjectileList()[0]->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y );

	
}

void Ship::Tick(float deltaTime) 
{
	Position = sprite.getPosition();
	HealthBarSprite.setPosition(Position + sf::Vector2f(0,100));

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

	Movement(horizontalValue, verticalValue, deltaTime);

	horizontalValue = 0;
	verticalValue = 0;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		Fire();
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
