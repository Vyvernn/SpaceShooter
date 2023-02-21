#include "Health.h"
#include "World.h"

void IHealthInterface::InitHealthBar()
{
}

void IHealthInterface::InitHealthBar(string textureFilePath)
{
	bShowHealthBar = true;
	sf::Texture texture = World::GetTexture(textureFilePath);

	if (&texture)
	{
		HealthBarSprite.setTexture(texture, true);
		HealthBarSprite.setOrigin(HealthBarSprite.getGlobalBounds().width / 2, HealthBarSprite.getGlobalBounds().height / 2);
	}
}

void IHealthInterface::InitHealthBar(float givenHealth)
{
	health = givenHealth;
}

void IHealthInterface::InitHealthBar(string textureFilePath, float givenHealth)
{
	bShowHealthBar = true;
	sf::Texture texture = World::GetTexture(textureFilePath);

	if (&texture)
	{
		HealthBarSprite.setTexture(texture, true);
		HealthBarSprite.setOrigin(HealthBarSprite.getGlobalBounds().width / 2, HealthBarSprite.getGlobalBounds().height / 2);
	}


	health = givenHealth;
}


// Call this when collision happens (Collision between ShipA and asteroid)
void IHealthInterface::TakeDamage(float damage)
{
	health -= damage;

	// Call handle death logic when dead
	if (health <= 0)
	{
		OnHealthReachZero();
	}
}

void IHealthInterface::DrawHealthBar()
{
	if (bShowHealthBar)
	{

	}
}
