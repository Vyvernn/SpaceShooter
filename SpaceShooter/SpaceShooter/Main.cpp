#if _DEBUG
#pragma comment(lib, "SFML-system-d")
#pragma comment(lib, "SFML-graphics-d")
#pragma comment(lib, "SFML-window-d")
#else
#pragma comment(lib, "SFML-system")
#pragma comment(lib, "SFML-graphics")
#pragma comment(lib, "SFML-window")
#endif // _DEBUG

#include <SFML/Graphics.hpp>
#include "World.h"

using namespace sf;

int main()
{
	sf::RenderWindow window(VideoMode::getDesktopMode(), "SFML");

    World* world = new World();

	while (window.isOpen())
	{
        // Clear
        window.clear();


        //Poll Events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        //Tick
        world->Update();

        world->Draw(&window);


        window.display();
	}
    return 0;
}