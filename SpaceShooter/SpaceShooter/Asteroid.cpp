#include "Asteroid.h"
#include "TickableObject.h"
#include "World.h"

Asteroid::Asteroid(float Speed, float Damage, World* givenWorld, string textureFilePath) 
	: Projectile(Speed, Damage, givenWorld, textureFilePath)
{
	bIsInstigatingCollision = true;
	bCanBeHit = true;
	Radius = max(sprite.getGlobalBounds().height, sprite.getGlobalBounds().width) / 2;
	
	InitHealthBar("Assets\\PNG\\UI\\buttonRed.png");
}

void Asteroid::Hit(ICollisionInterface* Instigator)
{
	if (Projectile* projectile = dynamic_cast<Projectile*>(Instigator))
	{
		TakeDamage(projectile->GetDamage());
	}
}

void Asteroid::OnHit(ICollisionInterface* HitObject)
{
	SetIsTickOn(false);
	bIsInstigatingCollision = false;
	TakeDamage(health);

	int newStartingPositionX = rand() % 400 + 400;
	int newStartingPositionY = rand() % 200 + 400;

	int newDirectionX = rand() % 360 + (-180);
	int newDirectionY = rand() % 360 + (-180);

	sprite.setPosition(newStartingPositionX, newStartingPositionY);
	SetDirection(sf::Vector2f(newDirectionX, newDirectionY));
	SetIsTickOn(true);
	health = MaxHealth;
}

void Asteroid::OnHealthReachZero()
{
	SetIsTickOn(false);
}

void Asteroid::Tick(float deltaTime)
{
	Projectile::Tick(deltaTime);


	//Location
	HealthBarSprite->setPosition(Position + sf::Vector2f(0, 100));
	HealthBarFillShape->setPosition(HealthBarSprite->getPosition());

	//UI
	UpdateHealthbarUI();
}

void Asteroid::OnExitedScreenSpace()
{

	int newStartingPositionX = rand() % 400 + 400;
	int newStartingPositionY = rand() % 200 + 400;

	int newDirectionX = rand() % 360 + (-180);
	int newDirectionY = rand() % 360 + (-180);

	sprite.setPosition(newStartingPositionX, newStartingPositionY);
	SetDirection(sf::Vector2f(newDirectionX, newDirectionY));
	SetIsTickOn(true);
	health = MaxHealth;
}
