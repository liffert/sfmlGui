#pragma once
#include "ViewElement.h"
#include <functional>

namespace gui {

	class Button : public gui::ViewElement {
	private:
		std::pair<int, int> findStrAmountAndBiggestLen(std::string text);
		std::function<void(void)> butFunc;
		bool adopt = false;
	public:
		Button(std::string id, int width, int height, int x, int y, std::string text);
		void setText(std::string text) override;
		void setFunction(std::function<void(void)> butFunc);//use std::bind for a class methods
		bool onClick(int x, int y);
		void setAdoptToText(bool adopt);
	};
}

