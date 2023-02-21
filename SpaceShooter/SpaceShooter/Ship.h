#pragma once
#include "TickableObject.h"
#include "Health.h"
#include "World.h"

class Ship : public TickableObject, Health
{
public:

	Ship();

	Ship(float givenSpeed);

	void Movement(float inputX, float inputY, float deltaTime);

	void Fire(World* world);

	virtual void Tick(float deltaTime) override;

	virtual void OnHealthReachZero() override;

private:

	float speed;

	float verticalValue = 0;

	float horizontalValue = 0;
	
};