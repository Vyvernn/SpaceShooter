#pragma once

#include <SFML/Graphics.hpp>

class TickableObject
{
	TickableObject() = delete;


public: 

	TickableObject(std::string spriteFilePath);

	virtual void Tick();

	sf::Sprite sprite;

	sf::Texture texture;

};