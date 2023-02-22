#include "Health.h"
#include "World.h"
#include "ShooterFunction.h"

void IHealthInterface::InitHealthBar()
{
}

void IHealthInterface::InitHealthBar(string textureFilePath)
{
	CreateHealthbar(textureFilePath);
}

void IHealthInterface::InitHealthBar(float givenHealth)
{
	health = givenHealth;

	if (health > MaxHealth)
	{
		MaxHealth = health;
	}
}

void IHealthInterface::InitHealthBar(string textureFilePath, float givenHealth)
{
	health = givenHealth;

	if (health > MaxHealth)
	{
		MaxHealth = health;
	}

	CreateHealthbar(textureFilePath);

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

void IHealthInterface::CreateHealthbar(string textureFilePath)
{
	bShowHealthBar = true;
	sf::Texture texture = World::GetTexture(textureFilePath);

	if (&texture)
	{
		HealthBarWidth = static_cast<int>(texture.getSize().x);
		HealthBarHeight = static_cast<int>(texture.getSize().y);


		HealthBarSprite = new sf::Sprite();
		HealthBarSprite->setTexture(texture, true);
		HealthBarSprite->setOrigin(HealthBarWidth / 2, HealthBarHeight / 2);

	}

	HealthBarFillShape = new sf::RectangleShape();
}

void IHealthInterface::UpdateHealthbarUI()
{
	HealthBarFillShape->setFillColor(sf::Color::Green);

	float HealthbarRatio = health / MaxHealth;

	HealthBarFillShape->setSize(sf::Vector2f(Lerp(0, HealthBarWidth, HealthbarRatio), HealthBarHeight));
	HealthBarFillShape->setOrigin(HealthBarFillShape->getSize().x / 2, HealthBarHeight / 2);
}

