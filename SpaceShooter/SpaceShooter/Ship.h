#pragma once
#include "TickableObject.h"
#include "Health.h"
#include "World.h"
#include "CollisionComponent.h"

class Ship : public TickableObject, public IHealthInterface, public ICollisionInterface
{
public:

	//Ship();

	Ship(float givenSpeed, World* world);

	~Ship();

	void Movement(float inputX, float inputY, float deltaTime);

	void Fire();


	virtual void Tick(float deltaTime) override;

	virtual void OnHealthReachZero() override;

	virtual void Hit(ICollisionInterface* Instigator) override;

	virtual void OnHit(ICollisionInterface* HitObject) override;

private:

	float speed;

	float verticalValue = 0;

	float horizontalValue = 0;

	void UpdateHealthBar();

	bool isFiring = false;

	void UpdateRotation();


};