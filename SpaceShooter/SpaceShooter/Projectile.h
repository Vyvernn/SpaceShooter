#pragma once
#include "TickableObject.h"
#include "CollisionComponent.h"
#include "World.h"

class Projectile : public TickableObject, public ICollisionInterface
{
public:
	Projectile(float givenSpeed, float givenDamage, World* givenWorld);
	void Move(float deltaTime);

	virtual void Tick(float deltaTime) override;

	virtual void Hit(ICollisionInterface* Instigator) override;

	virtual void OnHit(ICollisionInterface* HitObject) override;

	virtual void OnExitedScreenSpace();

	float GetDamage() { return damage; };

	void SetIsTickOn(bool value);
private:
	float speed;
	float damage;
	bool isTickOn;
};