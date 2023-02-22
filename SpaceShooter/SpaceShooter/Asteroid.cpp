#include "Asteroid.h"
#include "TickableObject.h"
#include "World.h"

Asteroid::Asteroid(float Speed, float Damage, World* givenWorld, string textureFilePath) 
	: Projectile(Speed, Damage, givenWorld, textureFilePath)
{

}

void Asteroid::Hit(ICollisionInterface* Instigator)
{
	if (Projectile* projectile = dynamic_cast<Projectile*>(Instigator))
	{
		TakeDamage(projectile->GetDamage());
	}
}

void Asteroid::OnHit(ICollisionInterface* HitObject)
{
	SetIsTickOn(false);
	bIsInstigatingCollision = false;
}

void Asteroid::OnHealthReachZero()
{

}
