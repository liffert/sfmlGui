#pragma once
#include <string>
#include "guinamespace.h"

namespace gui {
	class ViewElement : public sf::Drawable{
	protected:
		const std::string id;
		std::string text;
		struct size {
			int width;
			int height;
		};
		struct position {
			int x;
			int y;
		};
		struct textSettings {
			int x = 0;
			int y = 0;
			int textSize = fontSize;
		};
		struct size Size;
		struct position Position;
		struct textSettings TextSettings;
		sf::Color Color = sf::Color::White;
		sf::Color TextColor = sf::Color::Black;
		sf::Color BorderColor = sf::Color::Black;
		static const int fontSize = 20;

	public:
		ViewElement(std::string id, int width, int height);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void setText(std::string text);
		void setSize(int width, int height);
		void setPosition(int x, int y);
		void setColor(int color);
		void setTextColor(int color);
		void setBorderColor(int color);
		void setFontSize(unsigned int size);
	};
}

