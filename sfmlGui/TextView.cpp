#include "TextView.h"

std::vector<std::string> gui::TextView::getStr(std::string text) const {
	std::vector <std::string> temp;
	std::string buf;
	for (int i = 0; i < text.length(); i++) {
		if ((buf.length() + 1) * TextSettings.textSize / 2 > Size.width + 1) {
			temp.push_back(buf);
			buf.clear();
		}
		if (buf.empty() && text.at(i) == ' ') { continue; }
		if (text.at(i) == '\n') { 
			temp.push_back(buf); 
			buf.clear();
			continue;
		}
		buf.push_back(text.at(i));
	}
	if (!buf.empty()) { temp.push_back(buf); }
	return temp;
}

int gui::TextView::biggestStr(std::vector<std::string> arr) const {
	int len = 0;
	for (const auto& iter : arr) {
		if (len < iter.length()) {
			len = iter.length();
		}
	}
	return len;
}

gui::TextView::TextView(std::string id, int width, int height, int x, int y, std::string text) : ViewElement(id, width, height) {
	setPosition(x, y);
	setText(text);
}

void gui::TextView::setLikeLabel(bool state) {
	label = state;
}

void gui::TextView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(Size.width, Size.height));
	shape.setFillColor(Color);
	shape.setOutlineColor(BorderColor);
	shape.setOutlineThickness(1);
	shape.setPosition(Position.x, Position.y);
	auto TEXTARR = getStr(this->text);
	sf::Text text;
	sf::Font font;
	text.setString(this->text);
	text.setFillColor(TextColor);
	font.loadFromFile("ARIAL.TTF");
	text.setFont(font);
	text.setCharacterSize(TextSettings.textSize);
	text.setPosition(TextSettings.x, TextSettings.y);
	if (!label) {
		target.draw(shape, states);
	}
	target.draw(text, states);
}

void gui::TextView::setText(std::string text) {
	this->text.clear();
	auto TEXTARR = getStr(text);
	for (const auto& iter : TEXTARR) {
		this->text = this->text + iter + "\n";
	}
	int len = biggestStr(TEXTARR);
	TextSettings.x = Position.x;
	TextSettings.y = Position.y;
}
