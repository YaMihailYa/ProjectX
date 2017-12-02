#pragma once

enum menu_type_t { START, PAUSE, LEVEL_END, LEVEL_FAILED, LEVEL_SELECTION };
enum btn_type_t { BTN_START, BTN_OPTIONS, BTN_QUIT, BTN_RESUME, BTN_AGAIN,
	BTN_NEXT_LEVEL, BTN_LEVEL_SELECTION, BTN_HOME, BTN_LEV_1, BTN_LEV_2, BTN_LEV_3 };

class Button
{
public:
	Button(int x0, int y0, int width, int height, menu_type_t m_menu_name, btn_type_t m_btn_name);
	~Button();

	int getX0();
	int getY0();
	int getWidth();
	int getHeight();

	menu_type_t getMenuName();
	btn_type_t getBtnName();

	bool isClicked();

private:
	bool fl_clicked;
	sf::IntRect rectangle;
	menu_type_t m_menu_name;
	btn_type_t m_btn_name;
};