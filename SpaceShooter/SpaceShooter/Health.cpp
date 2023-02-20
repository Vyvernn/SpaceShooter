#include "Health.h"

Health::Health()
{
	health = 20.f;
}

Health::Health(float givenHealth)
{
	health = givenHealth;
}
// Call this when collision happens (Collision between ShipA and asteroid)
void Health::TakeDamage(float damage)
{
	health -= damage;

	// Call handle death logic when dead
	if (health <= 0)
	{
		OnHealthReachZero();
	}
}