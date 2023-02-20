#pragma once
#include "TickableObject.h"


class Ship : public TickableObject
{
public:
	Ship();
	Ship(float givenSpeed);
	void Movement(float inputX, float inputY, float deltaTime);
	void Fire();

	virtual void Tick() override;

private:
	float speed;

	
	
};