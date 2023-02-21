#pragma once

class IHealthInterface
{
public:
	IHealthInterface();

	IHealthInterface(float givenHealth);

	void TakeDamage(float damage);

	virtual void OnHealthReachZero() = 0;

	float health;
};