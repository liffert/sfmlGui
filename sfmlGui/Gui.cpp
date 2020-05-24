#include "Gui.h"
#include <iostream>

void gui::Gui::resetCurrent() {
	if (current == nullptr) { return; }
	current->setActive(false);
	current = nullptr;
}

gui::Gui::Gui(int width, int height, std::string name) : width(width), height(height), name(name) {}

void gui::Gui::start() {
	sf::RenderWindow window(sf::VideoMode(width, height), name);
	window.setFramerateLimit(0);
	std::string text;
	while (window.isOpen()) {
		sf::RectangleShape back;
		back.setFillColor(this->background);
		back.setSize(sf::Vector2f(width, height));
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					resetCurrent();
					auto pos = sf::Mouse::getPosition(window);
					for (auto &iter : buttons) {
						if (iter.second.onClick(pos.x, pos.y)) { break; }
					}
					for (auto &iter : textInputs) {
						if (iter.second.onClick(pos.x, pos.y)) {
							current = &iter.second;
							current->setActive(true);
						}
					}
				}
			}
			if (event.type == sf::Event::TextEntered) {
				if (current != nullptr) {
					current->addToText(event.text.unicode);
				}
			}
		}
	
		window.draw(back);
		for (const auto &iter : buttons) {
			window.draw(iter.second);
		}
		for (const auto& iter : textViews) {
			window.draw(iter.second);
		}
		for (const auto& iter : textInputs) {
			window.draw(iter.second);
		}
		window.display();
	}
}
void gui::Gui::setBackGroundColor(int color) {
	assert(color < gui::colors.size());
	background = gui::colors.at(color);
}

bool gui::Gui::addButton(std::string id, std::string text, int width, int height, int x, int y) {
	if (this->buttons.find(id) == this->buttons.end()) {
		gui::Button temp(id, width, height, x, y, text);
		buttons.insert({ id, temp });
		return true;
	}
	return false;
}

bool gui::Gui::addTextView(std::string id, int width, int height, int x, int y, std::string text) {
	if (this->textViews.find(id) == this->textViews.end()) {
		gui::TextView temp(id, width, height, x, y, text);
		textViews.insert({ id, temp });
		return true;
	}
	return false;
}

bool gui::Gui::addTextInput(std::string id, int width, int height, int x, int y) {
	if (this->textInputs.find(id) == this->textInputs.end()) {
		gui::TextInput temp(id, x, y, width, height);
		textInputs.insert({ id, temp });
		return true;
	}
	return false;
}

gui::Button& gui::Gui::button(std::string id) {
	auto temp = this->buttons.find(id);
	assert(temp != this->buttons.end());
	return temp->second;
}

gui::TextView& gui::Gui::textView(std::string id) {
	auto temp = this->textViews.find(id);
	assert(temp != this->textViews.end());
	return temp->second;
}

gui::TextInput& gui::Gui::textInput(std::string id) {
	auto temp = this->textInputs.find(id);
	assert(temp != this->textInputs.end());
	return temp->second;
}
