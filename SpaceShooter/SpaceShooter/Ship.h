#pragma once
#include "TickableObject.h"


class Ship : TickableObject
{
public:
	Ship();
	Ship(float& givenSpeed);
	void Movement(float inputX, float inputY, float deltaTime);

private:
	float speed;
};