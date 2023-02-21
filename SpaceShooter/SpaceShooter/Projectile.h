#pragma once
#include "TickableObject.h"
#include "CollisionComponent.h"
#include "World.h"

class Projectile : public TickableObject, public ICollisionInterface
{
public:
	Projectile(float givenSpeed, float givenDamage, World* world);
	void Move(float deltaTime);

	virtual void Tick(float deltaTime) override;

	virtual void Hit(ICollisionInterface* Instigator) override;

	float GetDamage() { return damage; };
private:
	float speed;
	float damage;
};