#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class IHealthInterface
{
public:
	void InitHealthBar();

	void InitHealthBar(string textureFilePath);

	void InitHealthBar(float givenHealth);


	void InitHealthBar(string textureFilePath, float givenHealth);

	void TakeDamage(float damage);

	virtual void OnHealthReachZero() = 0;

	void DrawHealthBar();

	sf::Vector2f HealthBarPosition;

	sf::Sprite HealthBarSprite;


	float health = 100.f;

	bool bShowHealthBar = false;
};