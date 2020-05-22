#pragma once
#include "ViewElement.h"
#include <vector>

namespace gui {
	class TextView : public gui::ViewElement {
	private:
		std::vector<std::string> getStr(std::string text)const;
		int biggestStr(std::vector<std::string> arr) const;
		bool label = false;
	public:
		TextView(std::string id, int width, int height, int x, int y, std::string text);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void setText(std::string text) override;
		void setLikeLabel(bool state);
	};
}
