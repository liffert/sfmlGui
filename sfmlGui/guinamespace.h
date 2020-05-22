#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <cassert>

namespace gui {
	static const std::array<sf::Color, 3> colors = { sf::Color::Black, sf::Color::White, sf::Color::Yellow };
	enum Color {
		black,
		white,
		yellow
	};
}