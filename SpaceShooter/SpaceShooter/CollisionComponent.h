#pragma once
#include <SFML/Graphics.hpp>

class TickableObject;

class ICollisionInterface
{

public:

	/** Called when this object is hit by another object */
	virtual void Hit(ICollisionInterface* Instigator) = 0;

	float Radius;

	sf::Vector2f Position;


	bool bIsInstigatingCollision;


	void CheckCollisionWith(ICollisionInterface* OtherObject);


};

class CCollisionComponent
{
	

	
	
};

