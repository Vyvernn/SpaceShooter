#include <vector>
#include <SFML/Graphics.hpp>

class TickableObject;

using namespace std;

/** This classes job is to keep a reference for all objects we have created, update them and draw them */
class World
{
public:

	World();

	void Update();

	void Draw(sf::RenderWindow* window);

	vector<TickableObject*> GetObjectList() { return ObjectList; };

private:
	vector<TickableObject*> ObjectList;

};