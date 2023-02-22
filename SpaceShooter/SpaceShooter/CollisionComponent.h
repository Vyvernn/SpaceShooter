#pragma once
#include <SFML/Graphics.hpp>

class TickableObject;

class ICollisionInterface
{

public:

	/** Called when this object is hit by another object */
	virtual void Hit(ICollisionInterface* Instigator) = 0;

	/** Called when this object hits another object */
	virtual void OnHit(ICollisionInterface* Instigator) = 0;

	float Radius = 5;

	sf::Vector2f Position;


	bool bIsInstigatingCollision = true;

	bool bCanBeHit = true;


	void CheckCollisionWith(ICollisionInterface* OtherObject);


};

class CCollisionComponent
{
	

	
	
};

