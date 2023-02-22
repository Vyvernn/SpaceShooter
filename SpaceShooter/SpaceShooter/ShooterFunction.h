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
};

static float Lerp(float A, float B, float Alpha)
{

	Alpha = std::max(0.f, Alpha);
	Alpha = std::min(1.f, Alpha);

	float Range = B-A;

	float t = Range * Alpha;


	return A+t;
}

static sf::Vector2f Normalize(sf::Vector2f vector)
{
	//Get unsigned values for both axis
	float magX = std::max(vector.x, -vector.x);
	float magY = std::max(vector.y, -vector.y);


	float total = magX + magY;


	return sf::Vector2f(vector.x / total, vector.y / total);
}

static float Dot(sf::Vector2f A, sf::Vector2f B)
{
	return (A.x * B.x) + (A.y * B.y);
}

static float RadiansToDegrees(float Radians)
{
	return Radians * (180.f / 3.14f);
}
