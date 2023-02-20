#pragma once

#include <SFML/Graphics.hpp>

class TickableObject
{
public: 
	virtual void BeginPlay() = 0;
	virtual void Tick() = 0;

	sf::Sprite* Sprite;

};