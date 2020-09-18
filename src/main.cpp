#include <SFML/Graphics.hpp>
#include "starfield.h"
#include <iostream>

int main(int argc, char *argv[])
{
	constexpr int width = 1280;
	constexpr int height = 720;
	constexpr int fps = 120;
	bool fullscreen = false;
	std::string title = "Starfield";

	if (argc > 1 && std::string(argv[1]) == "-f") {
		fullscreen = true;
	}

	sf::RenderWindow window;
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

	if (fullscreen) {
		window.create(desktop, title, sf::Style::Fullscreen);
		sf::View defaultView = window.getDefaultView();
		defaultView.setSize(width, height);
		defaultView.setCenter(width / 2, height / 2);
		window.setView(defaultView);
		window.setMouseCursorVisible(false);
	} else {
		window.create(sf::VideoMode(width, height, desktop.bitsPerPixel), title, sf::Style::Close);
	}
	window.setFramerateLimit(fps);

	try {
		auto starfield = std::make_unique<Starfield>(window);

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Escape) {
						window.close();
					}
				}
			}

			window.clear();

			starfield->Draw();

			window.display();
		}
	}
	catch (const std::runtime_error &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
