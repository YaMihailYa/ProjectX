#pragma once
#include "Static_Object.h"
#include "Button.h"

class Menu
{
public:
	Menu(unsigned int id);
	~Menu();

	void fillVectorButtons(menu_type_t type);
	void onClick();

	void display(sf::RenderWindow *window);

private:
	Static_Object* menu;
	std::vector<Button> buttons;
};