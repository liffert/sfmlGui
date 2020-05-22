#include "Gui.h"
#include <iostream>
gui::Gui app(600, 600, "Test");

void func() {
	app.button("but1").setText("some text");
}

int main() {
	app.setBackGroundColor(gui::Color::black);
	app.addButton("but1", "but", 100, 50, 0, 0);
	app.button("but1").setColor(gui::yellow);
	app.button("but1").setBorderColor(gui::white);
	app.button("but1").setTextColor(gui::black);
	app.button("but1").setFunction(func);
	app.button("but1").setFontSize(30);
	app.button("but1").setAdoptToText(true);

	app.addButton("but2", "but", 50, 50, 100, 100);
	app.button("but2").setColor(gui::white);
	app.button("but2").setBorderColor(gui::yellow);
	app.button("but2").setTextColor(gui::black);
	app.button("but2").setFunction([]() {app.button("but2").setText(std::to_string(std::rand() % 100)); });

	app.addButton("but3", "LT", 50, 50, 400, 100);
	app.button("but3").setFunction([]() {app.textView("text1").setText("Yes you can."); });

	app.addTextView("text1", 100, 300, 200, 200, "Hello world guys. How are you. Fine?\n It`s good. Really good. Can I ask us?");
	app.start();
}