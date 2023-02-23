#pragma once

#include <vector>
#include <queue>
#include <map>
#include <SFML/Graphics.hpp>

class TickableObject;
class Projectile;

using namespace std;

static vector<string> BigAsteroidImageFilePaths
{
	"Assets/PNG/Meteors/meteorBrown_big1.png",
	"Assets/PNG/Meteors/meteorBrown_big2.png",
	"Assets/PNG/Meteors/meteorBrown_big3.png",
	"Assets/PNG/Meteors/meteorBrown_big4.png",
	"Assets/PNG/Meteors/meteorGrey_big1.png" ,
	"Assets/PNG/Meteors/meteorGrey_big2.png" ,
	"Assets/PNG/Meteors/meteorGrey_big3.png" ,
	"Assets/PNG/Meteors/meteorGrey_big4.png"
};

static vector<string> MediumAsteroidImageFilePaths
{
	"Assets/PNG/Meteors/meteorBrown_med1.png",
	"Assets/PNG/Meteors/meteorBrown_med2.png",
	"Assets/PNG/Meteors/meteorGrey_med1.png",
	"Assets/PNG/Meteors/meteorGrey_med2.png"
};

static vector<string> SmallAsteroidImageFilePaths
{

	"Assets/PNG/Meteors/meteorBrown_small1.png",
	"Assets/PNG/Meteors/meteorBrown_small2.png",
	"Assets/PNG/Meteors/meteorGrey_small1.png" ,
	"Assets/PNG/Meteors/meteorGrey_small2.png"
};

static vector<string> TinyAsteroidImageFilePaths
{
	"Assets/PNG/Meteors/meteorBrown_tiny1.png",
	"Assets/PNG/Meteors/meteorBrown_tiny2.png",
	"Assets/PNG/Meteors/meteorGrey_tiny1.png",
	"Assets/PNG/Meteors/meteorGrey_tiny2.png"
};


/** This classes job is to keep a reference for all objects we have created, update them and draw them */
class World
{
public:

	World();

	~World();

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