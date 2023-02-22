#include "Projectile.h"
#include "ShooterFunction.h"

// The value passed here should be the ship's speed and damage
Projectile::Projectile(float givenSpeed, float givenDamage, World* givenWorld, string filePath) 
	: TickableObject(filePath, givenWorld)
{
	speed = givenSpeed;
	damage = givenDamage;
	isTickOn = false;		// Turn this on when we call Ship.Fire
	//Radius = 5;
	bIsInstigatingCollision = false;
	bCanBeHit = false;

	direction = sf::Vector2f(0, -1);

	Radius = max(sprite.getGlobalBounds().height, sprite.getGlobalBounds().width) / 2;
}

void Projectile::Move(float deltaTime)
{
	// TO-DO: move in the facing direction
	// Move up every frame for now
	sprite.move(direction * speed * deltaTime);
	//sprite.move(0.f, -speed * deltaTime);
}

void Projectile::Tick(float deltaTime)
{
	if (!isTickOn) { return; }
	bIsInstigatingCollision = true;
	Position = sprite.getPosition();
	Move(deltaTime);
	
	if (Position.y < -200.f || Position.x > 2120.f || Position.x < -200.f || Position.y > 1280.f)
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

	sprite.setPosition(20000, 20000);
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

void Projectile::SetDirection(sf::Vector2f newDirection)
{
	direction = Normalize(newDirection);
}


void Projectile::UpdateRotation()
{
	sf::Vector2f VectorTo = Normalize(direction);

	float DotProduct = Dot(VectorTo, sf::Vector2f(0, -1));


	float Radians = acos(DotProduct);

	float Angle = RadiansToDegrees(acos(DotProduct));

	if (VectorTo.x < 0)
	{
		Angle *= -1;
	}

	sprite.setRotation(Angle);
}
