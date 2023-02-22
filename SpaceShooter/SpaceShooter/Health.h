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

	void CreateHealthbar(string textureFilePath);

	void UpdateHealthbarUI();

	sf::Vector2f HealthBarPosition;

	sf::Sprite* HealthBarSprite;

	sf::RectangleShape* HealthBarFillShape;


	float health = 100.f;
	float MaxHealth = 100.f;
	float HealthBarWidth = 0.f;
	float HealthBarHeight = 0.f;

	bool bCanTakeDamage = false;

	bool bShowHealthBar = false;
};