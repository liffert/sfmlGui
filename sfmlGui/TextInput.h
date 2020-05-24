#pragma once
#include "ViewElement.h"
namespace gui {
	class TextInput : public gui::ViewElement {
	private:
		bool active = false;
		std::string id;

	public:
		TextInput(std::string id, int x, int y, int width, int height);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void addToText(const unsigned int symb);
		void setActive(bool active);

	};
}

