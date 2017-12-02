#include "Menu.h"

#define _CRT_SECURE_NO_WARNINGS

Menu* Menu::m_this = nullptr;

Menu::Menu(menu_type_t type) 
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);

	m_this = this;
	menu = nullptr;
	fillVectorButtons(type);
	last_x0_clicked = -1;
	last_y0_clicked = -1;
}

Menu::~Menu() { }

void Menu::fillVectorButtons(menu_type_t type)
{
	menuType = type;

	temp = false;

	if (menu != nullptr)
	{
		delete menu;
		menu = nullptr;
	}

	if (buttons.size() != 0)
	{
		buttons.clear();
	}

	switch (type)
	{
	case START:
	{
		menu = new Static_Object(9);

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
		menu = new Static_Object(10);

		Button btn1 = Button(626, 772, 140, 92, PAUSE, BTN_RESUME);
		Button btn2 = Button(890, 767, 140, 92, PAUSE, BTN_LEVEL_SELECTION);
		Button btn3 = Button(1153, 767, 140, 92, PAUSE, BTN_HOME);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);

		break;
	}
	case LEVEL_END:
	{
		menu = new Static_Object(17);

		Button btn1 = Button(626, 772, 140, 92, LEVEL_END, BTN_NEXT_LEVEL);
		Button btn2 = Button(890, 767, 140, 92, LEVEL_END, BTN_LEVEL_SELECTION);
		Button btn3 = Button(1153, 767, 140, 92, LEVEL_END, BTN_HOME);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);
		
		break;
	}
	case LEVEL_FAILED:
	{
		menu = new Static_Object(11);

		Button btn1 = Button(626, 772, 140, 92, LEVEL_FAILED, BTN_AGAIN);
		Button btn2 = Button(890, 767, 140, 92, LEVEL_FAILED, BTN_LEVEL_SELECTION);
		Button btn3 = Button(1153, 767, 140, 92, LEVEL_FAILED, BTN_HOME);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);

		break;
	}
	case LEVEL_SELECTION:
	{
		menu = new Static_Object(13);

		Button btn1 = Button(670, 271, 184, 128, LEVEL_SELECTION, BTN_LEV_1);
		Button btn2 = Button(871, 271, 184, 128, LEVEL_SELECTION, BTN_LEV_2);
		Button btn3 = Button(1072, 271, 184, 128, LEVEL_SELECTION, BTN_LEV_3);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);

		break;
	}
	case LOOT_BOX:
	{
		menu = new Static_Object(86);

		Button btn1 = Button(561, 134, 797, 813, LOOT_BOX, BTN_LOOT_BOX);
		buttons.push_back(btn1);

		break;
	}
	case SANTA_SUIT_SELECTION:
	{
		srand(time(NULL));
		int suitNum = rand() % 3;
		switch (suitNum)
		{
		case 0: { suitNum = 87; break; }
		case 1: { suitNum = 88; break; }
		case 2: { suitNum = 89; break; }
		}

		menu = new Static_Object(suitNum);

		Button btn1 = Button(723, 729, 450, 138, SANTA_SUIT_SELECTION, BTN_SANTA_SUIT);
		buttons.push_back(btn1);

		break;
	}
	case LOOT_BOX_END:
	{
		menu = new Static_Object(21);

		Button btn1 = Button(626, 772, 140, 92, LEVEL_FAILED, BTN_AGAIN);
		Button btn2 = Button(890, 767, 140, 92, LEVEL_FAILED, BTN_LEVEL_SELECTION);
		Button btn3 = Button(1153, 767, 140, 92, LEVEL_FAILED, BTN_HOME);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);

		break;
	}
	}
}

void Menu::onClick()
{
	if (temp == false)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			//BTN_START, BTN_OPTIONS, BTN_QUIT, BTN_NEXT_LEVEL, BTN_LEVEL_SELECTION, BTN_HOME, BTN_LEV_1, BTN_LEV_2, BTN_LEV_3

			if (!buttons[i].isClicked()) { continue; }
			else {
				if (buttons[i].getX0Click() == last_x0_clicked && buttons[i].getY0Click() == last_y0_clicked)
				{
					break;
				}
				else {
					last_x0_clicked = buttons[i].getX0Click();
					last_y0_clicked = buttons[i].getY0Click();
				}
			}

			btn_type_t btn = buttons[i].getBtnName();

			switch (btn)
			{
			case BTN_START:
			{
				temp = true;
				start();
				break;
			}
			case BTN_OPTIONS:
			{
				//temp = true;
				options();
				break;
			}
			case BTN_QUIT:
			{
				temp = true;
				quit();
				exit(0);
				break;
			}
			case BTN_RESUME:
			{
				temp = true;
				resume();
				break;
			}
			case BTN_AGAIN:
			{
				temp = true;
				again();
				break;
			}
			case BTN_NEXT_LEVEL:
			{
				temp = true;
				next_level();
				break;
			}
			case BTN_LEVEL_SELECTION:
			{
				temp = true;
				level_selection();
				break;
			}
			case BTN_HOME:
			{
				temp = true;
				home();
				break;
			}
			case BTN_LEV_1:
			{
				temp = true;
				lev_1();
				break;
			}
			case BTN_LEV_2:
			{
				temp = true;
				lev_2();
				break;
			}
			case BTN_LEV_3:
			{
				temp = true;
				lev_3();
				break;
			}
			case BTN_LOOT_BOX:
			{
				temp = true;
				loot_box();
				break;
			}
			case BTN_SANTA_SUIT:
			{
				temp = true;
				santa_suit();
				break;
			}
			}

			break;
		}
	}
}

void Menu::onKeyClick()
{
	switch (menuType)
	{
	case START:
		break;
	case PAUSE:
		break;
	case LEVEL_END:
		break;
	case LEVEL_FAILED:
		break;
	case LEVEL_SELECTION: {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			fillVectorButtons(START);
		break;
	}
	default:
		break;
	}
}

menu_type_t Menu::getMenuType()
{
	return menuType;
}

void Menu::display(sf::RenderWindow *window)
{
	//if (menu == nullptr) { return; }
	menu->display(window);
	if (menuType == LEVEL_SELECTION)
	{
		int count_cookies1;
		int count_cookies2;
		int count_cookies3;
		
		std::ifstream myfile("achievements.txt");
		if (myfile.is_open())
		{
			myfile >> count_cookies1;
			myfile >> count_cookies2;
			myfile >> count_cookies3;
			
			myfile.close();
		}

		Static_Object* cook1 = nullptr;
		Static_Object* cook2 = nullptr;
		Static_Object* cook3 = nullptr;

		switch (count_cookies1)
		{
		case 0: {
			cook1 = new Static_Object(67);
			break;
		}
		case 1: {
			cook1 = new Static_Object(68);
			break;
		}
		case 2: {
			cook1 = new Static_Object(69);
			break;
		}
		case 3: {
			cook1 = new Static_Object(70);
			break;
		}
		}

		switch (count_cookies2)
		{
		case 0: {
			cook2 = new Static_Object(67);
			break;
		}
		case 1: {
			cook2 = new Static_Object(68);
			break;
		}
		case 2: {
			cook2 = new Static_Object(69);
			break;
		}
		case 3: {
			cook2 = new Static_Object(70);
			break;
		}
		}

		switch (count_cookies3)
		{
		case 0: {
			cook3 = new Static_Object(67);
			break;
		}
		case 1: {
			cook3 = new Static_Object(68);
			break;
		}
		case 2: {
			cook3 = new Static_Object(69);
			break;
		}
		case 3: {
			cook3 = new Static_Object(70);
			break;
		}
		}

		cook1->setPosition(671, 357);
		cook2->setPosition(871, 357);
		cook3->setPosition(1071, 357);

		cook1->display(window);
		cook2->display(window);
		cook3->display(window);
	}
}

void Menu::start()
{
	printf("BTN_START\n");
	//*this = Menu(LEVEL_SELECTION);
	fillVectorButtons(LEVEL_SELECTION);
}

void Menu::options()
{
	printf("BTN_OPTIONS\n");
}

void Menu::quit()
{
	printf("BTN_QUIT\n");
	//Render stop, exit game!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void Menu::resume()
{
	printf("BTN_RESUME\n");
}

void Menu::again()
{
	printf("BTN_AGAIN\n");
}


void Menu::next_level()
{
	printf("BTN_NEXT_LEVEL\n");
}

void Menu::level_selection()
{
	printf("BTN_LEVEL_SELECTION\n");
}

void Menu::home()
{
	printf("BTN_HOME\n");
}

void Menu::lev_1()
{
	printf("BTN_LEV_1\n");
	fillVectorButtons(LOOT_BOX);
}

void Menu::lev_2()
{
	printf("BTN_LEV_2\n");
}

void Menu::lev_3()
{
	printf("BTN_LEV_3\n");
}

void Menu::loot_box()
{
	fillVectorButtons(SANTA_SUIT_SELECTION);
}

void Menu::santa_suit()
{
	fillVectorButtons(LOOT_BOX_END);
}





