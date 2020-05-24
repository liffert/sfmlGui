#pragma once
#include <string>
#include "ViewElement.h"
#include "guinamespace.h"
#include "TextView.h"
#include "Button.h"
#include "TextInput.h"
#include <vector>
#include <map>

namespace gui {
	class Gui {
	private:
		std::map<std::string, gui::Button> buttons;
		std::map<std::string, gui::TextView> textViews;
		std::map<std::string, gui::TextInput> textInputs;
		gui::TextInput * current = nullptr;
		std::string name;
		sf::Color background = sf::Color::White;
		int width;
		int height;
		void resetCurrent();

	public:
		Gui(int width, int height, std::string name);
		gui::Button& button(std::string id);
		gui::TextView& textView(std::string id);
		gui::TextInput& textInput(std::string id);
		bool addButton(std::string id, std::string text, int width, int height, int x, int y);
		bool addTextView(std::string id, int width, int height, int x, int y, std::string text);
		bool addTextInput(std::string id, int width, int height, int x, int y);
		void setBackGroundColor(int color);//use gui::Color
		void start();
		
	};
}