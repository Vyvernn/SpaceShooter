#pragma once

class HealthComponent
{
public:
	HealthComponent();

	HealthComponent(float givenHealth);

	void TakeDamage(float damage);

	virtual void OnHealthReachZero() = 0;

	float health;
};