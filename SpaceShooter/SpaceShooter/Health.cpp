#include "Health.h"

IHealthInterface::IHealthInterface()
{
	health = 20.f;
}

IHealthInterface::IHealthInterface(float givenHealth)
{
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