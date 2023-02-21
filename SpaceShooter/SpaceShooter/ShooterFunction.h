#pragma once


#include <SFML/Graphics.hpp>

static bool RadialSpriteCollision(sf::Vector2f PositionA, float RadiusA,  sf::Vector2f PositionB, float RadiusB)
{
	// X^2 + Y^2 = Dist^2
	// .. if X^2 + Y^2 < (r1+r2)^2 -> Collision = true
	float xDist = PositionA.x - PositionB.x;
	float yDist = PositionA.y - PositionB.y;

	float xDistSqrd = xDist * xDist;
	float yDistSqrd = yDist * yDist;

	float DistSqrd = xDistSqrd + yDistSqrd;

	float MinDistSqrd = (RadiusA + RadiusB) * (RadiusA + RadiusB);

	return DistSqrd < MinDistSqrd;
}
;