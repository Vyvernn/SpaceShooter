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
