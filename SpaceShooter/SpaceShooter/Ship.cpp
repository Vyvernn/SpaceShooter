#include "Ship.h"
#include <iostream>
#include "Projectile.h"
#include "ShooterFunction.h"

Ship::Ship(float givenSpeed, World* world) :
	TickableObject("Assets\\PNG\\playerShip1_red.png", world)
{
	speed = 425;
	speed = givenSpeed;
	Radius = max(sprite.getGlobalBounds().height, sprite.getGlobalBounds().width) / 2;

	bIsInstigatingCollision = false;

	InitHealthBar("Assets\\PNG\\UI\\buttonRed.png");
}

void Ship::Movement(float inputX, float inputY, float deltaTime)
{
	// Move up, down, left, and right
	sprite.move( (inputX * speed * deltaTime) , (inputY * speed * deltaTime) );
}

void Ship::Fire()
{
	isFiring = true;

	// Get the first element on the Queue (list) and enable and spawn it
	Projectile* projPtr = world->GetProjectileList().front();

	projPtr->SetIsTickOn(true);
	projPtr->sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y - 100.f);

	// Remove the first element and push that element to the last
	world->GetProjectileList().pop();
	world->GetProjectileList().push(projPtr);
}

void Ship::Tick(float deltaTime) 
{
	Position = sprite.getPosition();

	UpdateHealthBar();



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



	sf::Vector2i mousePositionInt = sf::Mouse::getPosition();
	sf::Vector2f mousePosition = sf::Vector2f(static_cast<float>(mousePositionInt.x), static_cast<float>(mousePositionInt.y));


	sf::Vector2f VectorTo = mousePosition - Position;
	VectorTo = Normalize(VectorTo);

	float DotProduct = Dot(VectorTo, sf::Vector2f(0, -1));


	float Radians = acos(DotProduct);

	float Angle = RadiansToDegrees(acos(DotProduct));

	if (VectorTo.x < 0)
	{
		Angle -= 180;
	}

	sprite.setRotation(Angle);






	Movement(horizontalValue, verticalValue, deltaTime);

	horizontalValue = 0;
	verticalValue = 0;


	// Essentially allow us to only use 1 mouse button 
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !isFiring)
	{
		Fire();
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		isFiring = false;
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

void Ship::OnHit(ICollisionInterface* HitObject)
{
	// Don't need to do anything here
}

void Ship::UpdateHealthBar()
{
	//Location
	HealthBarSprite->setPosition(Position + sf::Vector2f(0, 100));
	HealthBarFillShape->setPosition(HealthBarSprite->getPosition());

	//UI
	UpdateHealthbarUI();
}
