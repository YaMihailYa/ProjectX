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

	void start();
	void options();
	void quit();
	void resume();
	void next_level();
	void level_selection();
	void home();
	void lev_1();
	void lev_2();
	void lev_3();

private:
	Static_Object* menu;
	std::vector<Button> buttons;
	bool temp;
};