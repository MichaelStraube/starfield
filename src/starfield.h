#ifndef STARFIELD_H
#define STARFIELD_H

#include <SFML/Graphics.hpp>

class Starfield
{
public:
	Starfield(sf::RenderWindow &window);
	void Draw();

private:
	sf::RenderWindow &window;
	sf::RectangleShape rect;
	sf::Clock clock;
	sf::Shader shader;
};

#endif // STARFIELD_H
