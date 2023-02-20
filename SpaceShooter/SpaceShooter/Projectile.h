#pragma once
#include "TickableObject.h"

class Projectile : public TickableObject
{
public:
	Projectile(float speed, float damage);
	void Move(float deltaTime);

	virtual void Tick(float deltaTime) override;
private:
	float speed;
	float damage;
};