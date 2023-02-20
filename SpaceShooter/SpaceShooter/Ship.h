#pragma once
#include "TickableObject.h"


class Ship : public TickableObject
{
public:
	Ship();
	Ship(float givenSpeed);
	void Movement(float inputX, float inputY, float deltaTime);

	virtual void Tick() override;

private:
	float speed;
};