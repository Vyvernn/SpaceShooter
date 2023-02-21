#pragma once
#include "TickableObject.h"

class Projectile : public TickableObject, ICollisionInterface
{
public:
	Projectile(float speed, float damage);
	void Move(float deltaTime);

	virtual void Tick(float deltaTime) override;

	float GetDamage() { return damage; };
private:
	float speed;
	float damage;
};