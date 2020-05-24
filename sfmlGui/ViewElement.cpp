#include "ViewElement.h"

gui::ViewElement::ViewElement(std::string id, int width, int height) : id(id) {
	Size.width = width;
	Size.height = height;
}

void gui::ViewElement::setColor(int color) {
	assert(color < gui::colors.size());
	this->Color = gui::colors.at(color);
}

void gui::ViewElement::setTextColor(int color) {
	assert(color < gui::colors.size());
	TextColor = gui::colors.at(color);
}

void gui::ViewElement::setBorderColor(int color) {
	assert(color < gui::colors.size());
	BorderColor = gui::colors.at(color);
}

void gui::ViewElement::setPosition(int x, int y) {
	Position.x = x;
	Position.y = y;
}

void gui::ViewElement::setText(std::string text) {
	this->text = text;
}

std::string gui::ViewElement::getText() const {
	return text;
}

bool gui::ViewElement::onClick(int x, int y) {
	if (x >= Position.x && x <= Position.x + Size.width && y >= Position.y && y <= Position.y + Size.height) { return true; }
	return false;
}

void gui::ViewElement::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(Size.width, Size.height));
	shape.setFillColor(Color);
	shape.setOutlineColor(BorderColor);
	shape.setOutlineThickness(1);
	shape.setPosition(Position.x, Position.y);
	sf::Text text;
	sf::Font font;
	text.setString(this->text);
	text.setFillColor(TextColor);
	font.loadFromFile("ARIAL.TTF");
	text.setFont(font);
	text.setCharacterSize(TextSettings.textSize);
	text.setPosition(TextSettings.x, TextSettings.y);
	target.draw(shape, states);
	target.draw(text, states);
}

void gui::ViewElement::setFontSize(unsigned int size) {
	TextSettings.textSize = size;
	setText(text);
}

void gui::ViewElement::setSize(int width, int height) {
	Size.height = height;
	Size.width = width;
}
