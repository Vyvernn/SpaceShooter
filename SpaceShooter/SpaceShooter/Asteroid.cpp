#include "Asteroid.h"
#include "TickableObject.h"
#include "World.h"

Asteroid::Asteroid(float Speed, float Damage, float defaultHealth,  World* givenWorld, string textureFilePath) 
	: Projectile(Speed, Damage, givenWorld, textureFilePath)
{
	bIsInstigatingCollision = true;
	bCanBeHit = true;
	Radius = max(sprite.getGlobalBounds().height, sprite.getGlobalBounds().width) / 2;

	MaxHealth = health = defaultHealth;
	
	//InitHealthBar("Assets\\PNG\\UI\\buttonRed.png");
}

void Asteroid::Hit(ICollisionInterface* Instigator)
{
	if (Asteroid* otherObj = dynamic_cast<Asteroid*>(Instigator))
	{
		return;
	}
	if (Projectile* projectile = dynamic_cast<Projectile*>(Instigator))
	{
		TakeDamage(projectile->GetDamage());
	}
}

void Asteroid::OnHit(ICollisionInterface* HitObject)
{
	if (Asteroid* otherObj = dynamic_cast<Asteroid*>(HitObject))
	{
		return;
	}
	SetIsTickOn(false);
	bIsInstigatingCollision = false;
	TakeDamage(health);

	Reset();
}

void Asteroid::OnHealthReachZero()
{
	SetIsTickOn(false);

	Reset();
}

void Asteroid::Tick(float deltaTime)
{
	Projectile::Tick(deltaTime);


	//Location
	if (HealthBarSprite && HealthBarFillShape)
	{
		HealthBarSprite->setPosition(Position + sf::Vector2f(0, 100));
		HealthBarFillShape->setPosition(HealthBarSprite->getPosition());

	}

	//UI
	UpdateHealthbarUI();
}

void Asteroid::OnExitedScreenSpace()
{
	Reset();
}

void Asteroid::Reset()
{
	int newStartingPositionX = rand() % 2000;
	int newStartingPositionY = rand() % 1100;

	int newDirectionX = rand() % 360 + (-180);
	int newDirectionY = rand() % 360 + (-180);

	sprite.setPosition(newStartingPositionX, newStartingPositionY);
	SetDirection(sf::Vector2f(newDirectionX, newDirectionY));
	SetIsTickOn(true);
	health = MaxHealth;
}
