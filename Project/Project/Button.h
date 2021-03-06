#pragma once

enum menu_type_t { START, PAUSE, OPTIONS , LEVEL_END, LEVEL_FAILED, LEVEL_SELECTION, LOOT_BOX, SANTA_SUIT_SELECTION, LOOT_BOX_END, LEVEL_1, LEVEL_2, LEVEL_3, HELP_1, HELP_2, HELP_3 };
enum btn_type_t { BTN_START, BTN_OPTIONS, BTN_QUIT, BTN_RESUME, BTN_AGAIN,
	BTN_NEXT_LEVEL, BTN_LEVEL_SELECTION, BTN_HOME, BTN_LEV_1, BTN_LEV_2, BTN_LEV_3, BTN_LOOT_BOX, BTN_SANTA_SUIT, BTN_SANTA_OPTION_RED, BTN_SANTA_OPTION_BLUE,
	BTN_SANTA_OPTION_GREEN, BTN_SANTA_OPTION_PINK};

class Button
{
public:
	Button(int x0, int y0, int width, int height, menu_type_t m_menu_name, btn_type_t m_btn_name);
	~Button();

	int getX0();
	int getY0();

	int getX0Click();
	int getY0Click();

	int getWidth();
	int getHeight();

	menu_type_t getMenuName();
	btn_type_t getBtnName();

	bool isClicked();
	bool isHovered();

private:
	bool fl_clicked;

	int x0_click;
	int y0_click;

	sf::IntRect rectangle;
	menu_type_t m_menu_name;
	btn_type_t m_btn_name;
};