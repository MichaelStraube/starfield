#include "starfield.h"
#include "shader.h"

Starfield::Starfield(sf::RenderWindow &window) : window(window)
{
	if (!sf::Shader::isAvailable()) {
		throw std::runtime_error("Shaders are not available");
	}

	if (!shader.loadFromMemory(shader::starShaderF, sf::Shader::Fragment)) {
		throw std::runtime_error("Failed to load shaders from memory");
	}

	sf::Vector2u size = window.getSize();
	shader.setUniform("iResolution", sf::Glsl::Vec2(size.x, size.y));

	rect.setSize(sf::Vector2f(size.x, size.y));
	rect.setPosition(0, 0);

	clock.restart();
}

void Starfield::Draw()
{
	shader.setUniform("iTime", clock.getElapsedTime().asSeconds());
	window.draw(rect, &shader);
}
