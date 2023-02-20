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

using namespace sf;

int main()
{
	RenderWindow window(VideoMode::getDesktopMode(), "SFML");

	while (window.isOpen())
	{
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
        window.display();
	}
    return 0;
}