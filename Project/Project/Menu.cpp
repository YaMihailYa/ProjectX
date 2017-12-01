#include "Menu.h"

Menu::Menu(unsigned int id) { menu = new Static_Object(id); }

Menu::~Menu() { }

void Menu::fillVectorButtons(menu_type_t type)
{
	switch (type)
	{
	case START:
	{
		Button btn1 = Button(760, 335, 458, 140, START, BTN_START);
		Button btn2 = Button(760, 551, 458, 140, START, BTN_OPTIONS);
		Button btn3 = Button(760, 769, 458, 140, START, BTN_QUIT);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);

		break;
	}
	case PAUSE:
	{
		Button btn1 = Button(626, 772, 140, 92, PAUSE, BTN_NEXT_LEVEL);
		Button btn2 = Button(890, 767, 140, 92, PAUSE, BTN_LEVEL_SELECTION);
		Button btn3 = Button(1153, 767, 140, 92, PAUSE, BTN_HOME);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);

		break;
	}
	case LEVEL_END:
	{
		Button btn1 = Button(626, 772, 140, 92, LEVEL_END, BTN_NEXT_LEVEL);
		Button btn2 = Button(890, 767, 140, 92, LEVEL_END, BTN_LEVEL_SELECTION);
		Button btn3 = Button(1153, 767, 140, 92, LEVEL_END, BTN_HOME);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);

		break;
	}
	case LEVEL_SELECTION:
	{
		Button btn1 = Button(670, 271, 184, 128, LEVEL_SELECTION, BTN_LEV_1);
		Button btn2 = Button(871, 271, 184, 128, LEVEL_SELECTION, BTN_LEV_2);
		Button btn3 = Button(1072, 271, 184, 128, LEVEL_SELECTION, BTN_LEV_3);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);

		break;
	}
	}
}

void Menu::onClick()
{
	for (int i = 0; i < buttons.size(); i++) 
	{
		//BTN_START, BTN_OPTIONS, BTN_QUIT, BTN_NEXT_LEVEL, BTN_LEVEL_SELECTION, BTN_HOME, BTN_LEV_1, BTN_LEV_2, BTN_LEV_3

		if (!buttons[i].isClicked()) { continue; }

		if (buttons[i].getBtnName() == BTN_START) { printf("BTN_START\n"); }
		else if (buttons[i].getBtnName() == BTN_OPTIONS) { printf("BTN_OPTIONS\n"); }
		else if (buttons[i].getBtnName() == BTN_QUIT) { printf("BTN_QUIT\n"); }
		
		/*switch (buttons[i].getBtnName()) 
		{
		case BTN_START:
		{
			printf("BTN_START\n");
			break;
		}
		case BTN_OPTIONS:
		{
			printf("BTN_OPTIONS\n");
			break;
		}
		case BTN_QUIT:
		{
			printf("BTN_QUIT\n");
			break;
		}
		case BTN_NEXT_LEVEL: 
		{
			printf("BTN_NEXT_LEVEL\n");
			break;
		}
		case BTN_LEVEL_SELECTION: 
		{
			printf("BTN_LEVEL_SELECTION\n");
			break;
		}
		case BTN_HOME:
		{
			printf("BTN_HOME\n");
			break;
		}
		case BTN_LEV_1: 
		{
			printf("BTN_LEV_1\n");
			break;
		}
		case BTN_LEV_2: 
		{
			printf("BTN_LEV_2\n");
			break;
		}
		case BTN_LEV_3: 
		{
			printf("BTN_LEV_3\n");
			break;
		}
		}*/
	}
}

void Menu::display(sf::RenderWindow *window)
{
	menu->display(window);
}