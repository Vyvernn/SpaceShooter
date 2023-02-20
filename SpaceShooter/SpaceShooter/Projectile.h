#pragma once
#include "TickableObject.h"

class Projectile : TickableObject
{
public:
	Projectile(float& speed, float& damage);
	void Move(float& deltaTime);
private:
	float speed;
	float damage;
};