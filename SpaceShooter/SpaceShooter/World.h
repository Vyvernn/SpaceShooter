#pragma once

#include <vector>
#include <queue>
#include <map>
#include <SFML/Graphics.hpp>

class TickableObject;
class Projectile;

using namespace std;

/** This classes job is to keep a reference for all objects we have created, update them and draw them */
class World
{
public:

	World();

	void Update();

	void Draw(sf::RenderWindow* window);

	vector<TickableObject*>& GetObjectList() { return ObjectList; };

	queue<Projectile*>& GetProjectileList() { return ProjectileList; }

	static sf::Texture GetTexture(string filepath);

	static map<string, sf::Texture> TextureMap;


private:
	vector<TickableObject*> ObjectList;

	queue<Projectile*> ProjectileList;

	sf::Clock clock;

	sf::Time LastFrameTime;

	static bool LoadTexture(string filepath);

	bool bFirstTick = true;

};