#include "Button.h"

std::pair<int, int> gui::Button::findStrAmountAndBiggestLen(std::string text) {
	unsigned int counter = 1;
	std::string temp;
	int len = 0;
	for (unsigned int i = 0; i < text.length(); i++) {
		if (text.at(i) == '\n') {
			counter++;
			if (temp.length() > len) { len = temp.length(); }
			temp.clear();
		}
		temp.push_back(text.at(i));
	}
	if (temp.length() > len) { len = temp.length(); }
	return std::pair<int, int>(counter, len);
}

gui::Button::Button(std::string id, int width, int height, int x, int y, std::string text) : gui::ViewElement(id, width, height) {
	this->setPosition(x, y);
	this->setText(text);
}

void gui::Button::setText(std::string text) {
	this->text = text;
	if (adopt) {
		auto textInfo = findStrAmountAndBiggestLen(text);
		if (textInfo.first == 1) {
			setSize(TextSettings.textSize * text.length(), TextSettings.textSize * 2);
		}
		else {
			setSize(TextSettings.textSize * textInfo.second, TextSettings.textSize * 2 * textInfo.first);
		}
		TextSettings.x = Position.x + (Size.width - textInfo.second * TextSettings.textSize / 2) / 2;
	}
	else {
		TextSettings.x = Position.x + (Size.width - text.length() * TextSettings.textSize / 2) / 2;
	}
	TextSettings.y = Position.y + (Size.height - TextSettings.textSize) / 4;
}

void gui::Button::setFunction(std::function<void(void)> butFunc) {
	this->butFunc = butFunc;
}

bool gui::Button::onClick(int x, int y) {
	if (x >= Position.x && x <= Position.x + Size.width && y >= Position.y && y <= Position.y + Size.height) {
		butFunc();
		return true;
	}
	return false;
}

void gui::Button::setAdoptToText(bool adopt) {
	this->adopt = adopt;
	setText(text);
}
