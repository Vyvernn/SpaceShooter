#pragma once

#include <SFML/Graphics.hpp>
#include "World.h"
class TickableObject
{
	TickableObject() = delete;


public: 

	TickableObject(std::string spriteFilePath, World* world);

	virtual void Tick(float deltaTime);

	sf::Sprite sprite;

	sf::Texture texture;

};