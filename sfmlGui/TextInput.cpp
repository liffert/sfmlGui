#include "TextInput.h"

gui::TextInput::TextInput(std::string id, int x, int y, int width, int height) : gui::ViewElement(id, width, height) {
	setPosition(x, y);
	TextSettings.x = x;
	TextSettings.y = y;
}

void gui::TextInput::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(Size.width, Size.height));
	shape.setFillColor(Color);
	shape.setOutlineColor(BorderColor);
	shape.setOutlineThickness(1);
	shape.setPosition(Position.x, Position.y);
	sf::Text text;
	sf::Font font;
	text.setFillColor(TextColor);
	font.loadFromFile("ARIAL.TTF");
	text.setFont(font);
	text.setCharacterSize(TextSettings.textSize);
	text.setPosition(TextSettings.x, TextSettings.y);
	if (active) {
		text.setString(this->text + "|");
	}
	else {
		text.setString(this->text);
	}
	target.draw(shape, states);
	target.draw(text, states);
}

void gui::TextInput::setActive(bool active) {
	this->active = active;
}

void gui::TextInput::addToText(const unsigned int symb) {
	if (symb == 8) {
		if (!text.empty()) {
			text.pop_back();
		}
	}
	else if (symb == 13 || symb == 10) {
		text.push_back('\n');
	}
	else {
		text.push_back(symb);
	}
}
