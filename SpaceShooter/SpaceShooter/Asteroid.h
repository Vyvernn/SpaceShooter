#pragma once
#include "Projectile.h"
#include "Health.h"

class World;


class Asteroid : public Projectile, public IHealthInterface
{
public:

	Asteroid(float Speed, float Damage, World* world, string textureFilePath);
	

	virtual void Hit(ICollisionInterface* Instigator) override;

	virtual void OnHit(ICollisionInterface* HitObject) override;

	virtual void OnHealthReachZero() override;
};

