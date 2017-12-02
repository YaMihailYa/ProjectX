#pragma once
#include "Static_Object.h"
#include "Button.h"
#include "Render.h"
#include <ctime>
#include <fstream>

class Menu
{
public:
	Menu(menu_type_t type);
	~Menu();

	void fillVectorButtons(menu_type_t type);
	void onClick();
	void onKeyClick();

	void display(sf::RenderWindow *window);

	void start();
	void options();
	void quit();
	void resume();
	void again();
	void next_level();
	void level_selection();
	void home();
	void lev_1();
	void lev_2();
	void lev_3();
	void loot_box();
	void santa_suit();

private:
	Static_Object* menu;
	std::vector<Button> buttons;
	bool temp;
	menu_type_t menuType;

	int last_x0_clicked;
	int last_y0_clicked;
};