#pragma once
#include "TickableObject.h"
#include "CollisionComponent.h"

class Projectile : public TickableObject, ICollisionInterface
{
public:
	Projectile(float speed, float damage);
	void Move(float deltaTime);

	virtual void Tick(float deltaTime) override;

	virtual void Hit(ICollisionInterface* Instigator) override;

	float GetDamage() { return damage; };
private:
	float speed;
	float damage;
};