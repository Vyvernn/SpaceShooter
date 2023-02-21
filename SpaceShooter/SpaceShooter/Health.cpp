#include "Health.h"

HealthComponent::HealthComponent()
{
	health = 20.f;
}

HealthComponent::HealthComponent(float givenHealth)
{
	health = givenHealth;
}
// Call this when collision happens (Collision between ShipA and asteroid)
void HealthComponent::TakeDamage(float damage)
{
	health -= damage;

	// Call handle death logic when dead
	if (health <= 0)
	{
		OnHealthReachZero();
	}
}