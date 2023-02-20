#pragma once

class Health
{
public:
	Health();

	Health(float givenHealth);

	void TakeDamage(float damage);

	virtual void OnHealthReachZero() = 0;

	float health;
};