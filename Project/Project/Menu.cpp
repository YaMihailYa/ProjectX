#include "Menu.h"
#include "Room_Tree.h"
#include "Room_Grandma.h"
#include "Room_Dog.h"
#include "Static_Object_Storage.h"
#include "Door_front.h"
#include "Door_rooms.h"

#define _CRT_SECURE_NO_WARNINGS

Menu* Menu::m_this = nullptr;

Menu::Menu(menu_type_t type) 
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);

	bool isAvailable1;
	bool isAvailable2;
	bool isAvailable3;

	std::ifstream myfile("availables_santa_suits.txt");
	if (myfile.is_open())
	{
		myfile >> isAvailable1;
		myfile >> isAvailable2;
		myfile >> isAvailable3;

		available_santas[0] = isAvailable1;
		available_santas[1] = isAvailable2;
		available_santas[2] = isAvailable3;

		myfile.close();
	}


	m_this = this;
	menu = nullptr;

	selected_option_id = 0;

	available_santas[0] = true;
	available_santas[1] = true;
	available_santas[2] = true;

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
	case OPTIONS:
	{
		menu = new Static_Object(94);

		Button btn1 = Button(84, 406, 413, 550, OPTIONS, BTN_SANTA_OPTION_RED);
		Button btn2 = Button(547, 406, 413, 550, OPTIONS, BTN_SANTA_OPTION_GREEN);
		Button btn3 = Button(1010, 406, 413, 550, OPTIONS, BTN_SANTA_OPTION_PINK);
		Button btn4 = Button(1473, 406, 413, 550, OPTIONS, BTN_SANTA_OPTION_BLUE);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);
		buttons.push_back(btn4);

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
				temp = true;
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
			case BTN_SANTA_OPTION_RED:
			{
				//temp = true;
				santa_option_selected(0);
				break;
			}
			case BTN_SANTA_OPTION_GREEN:
			{
				//temp = true;
				santa_option_selected(1);
				break;
			}
			case BTN_SANTA_OPTION_PINK:
			{
				//temp = true;
				santa_option_selected(2);
				break;
			}
			case BTN_SANTA_OPTION_BLUE:
			{
				//temp = true;
				santa_option_selected(3);
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
	case OPTIONS: {
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
	else if (menuType == OPTIONS) {
		Static_Object* sel_ball = new Static_Object(90);
		switch (selected_option_id)
		{
		case 0: {
			sel_ball->setPosition(264, 264);
			break;
		}
		case 1: {
			sel_ball->setPosition(724, 264);
			break;
		}
		case 2: {
			sel_ball->setPosition(1184, 264);
			break;
		}
		case 3: {
			sel_ball->setPosition(1644, 264);
			break;
		}
		}
		sel_ball->display(window);

		for (int i = 0; i < 3; i++) {
			if (available_santas[i] == true) {
				Static_Object* santa = new Static_Object(91 + i);
				switch (i)
				{
				case 0: {
					santa->setPosition(547, 406);
					break;
				}
				case 1: {
					santa->setPosition(1010, 406);
					break;
				}
				case 2: {
					santa->setPosition(1473, 406);
					break;
				}
				}
				santa->display(window);
			}
		}

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
	fillVectorButtons(OPTIONS);
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
	
	// Preparing to creating the level
	// Creating the background
	Static_Object *background = new Static_Object(64);

	// Creating the rooms
	// Creating the array of rooms
	std::vector<Room*> rooms;

	// Room 0
	Room *room0 = new Room(REGULAR, 0, sf::IntRect(1326, 24, 473, 285));

	std::vector<Static_Object_Hovered*> staticObjects;
	std::vector<Animated_Object*> animatedObjects;

	std::vector<Item_t> items;
	items.push_back(Item_t(COOKIE, YELLOW));
	items.push_back(Item_t(KEY, GREEN));

	Static_Object_Storage *currStaticObject = new Static_Object_Storage(50, 51, items);		// Tumbochka
	currStaticObject->setPosition(1453, 166);
	staticObjects.push_back(currStaticObject);

	room0->setStaticObjects(staticObjects);
	room0->setAnimatedObjects(animatedObjects);


	// Room 1
	Room_Tree *room1 = new Room_Tree(TREE, 1, sf::IntRect(568, 24, 606, 285));

	staticObjects.clear();
	animatedObjects.clear();

	room1->setStaticObjects(staticObjects);
	room1->setAnimatedObjects(animatedObjects);

	// Christmas tree
	room1->setTreePosition(796, 28);


	// Room 2
	Room *room2 = new Room(REGULAR, 2, sf::IntRect(568, 332, 606, 285));

	staticObjects.clear();
	animatedObjects.clear();

	items.clear();
	items.push_back(Item_t(COOKIE, YELLOW));
	items.push_back(Item_t(COOKIE, YELLOW));

	currStaticObject = new Static_Object_Storage(48, 49, items);		// Sofa
	currStaticObject->setPosition(766, 361);
	staticObjects.push_back(currStaticObject);

	room2->setStaticObjects(staticObjects);
	room2->setAnimatedObjects(animatedObjects);


	// Setting the links
	room0->Set_left_room(room1);
	room1->Set_down_room(room2);
	room1->Set_right_room(room0);
	room2->Set_top_room(room1);

	// Creating the array of doors
	std::vector<Door*> doors;

	// Door 0
	Door_rooms *door0 = new Door_rooms(0, false, YELLOW, 1, 0);
	door0->Set_pos(sf::Vector2u(1118, 24));

	// Door 1 and 2
	Door_front *door1 = new Door_front(1, true, GREEN, DOWN, 1, 2);
	Door_front *door2 = new Door_front(2, true, GREEN, TOP, 2, 1);

	door1->Set_pos(sf::Vector2u(618, 34));
	door2->Set_pos(sf::Vector2u(618, 341));

	// Setting the links
	door1->Set_adj_door_id(2);
	door2->Set_adj_door_id(1);

	room0->Set_left_door(door0);
	room1->Set_right_door(door0);
	room1->Set_down_door(door1);
	room2->Set_top_door(door2);

	// Adding rooms to the array
	rooms.push_back(room0);
	rooms.push_back(room1);
	rooms.push_back(room2);

	// Adding doors to the array
	doors.push_back(door0);
	doors.push_back(door1);
	doors.push_back(door2);

	Level *level = new Level(1, background, rooms, doors);

	Render::Get()->setStatus(RENDER_STATUS_GAME);
	Render::Get()->setLevel(level);
}

void Menu::lev_2()
{
	// Preparing to creating the level
	// Creating the background
	Static_Object *background = new Static_Object(65);

	// Creating the rooms
	// Creating the array of rooms
	std::vector<Room*> rooms;

	// Room 0
	Room *room0 = new Room(REGULAR, 0, sf::IntRect(1326, 24, 473, 285));

	std::vector<Static_Object_Hovered*> staticObjects;
	std::vector<Animated_Object*> animatedObjects;

	room0->setStaticObjects(staticObjects);
	room0->setAnimatedObjects(animatedObjects);


	// Room 1
	Room *room1 = new Room(TREE, 1, sf::IntRect(568, 24, 606, 285));

	staticObjects.clear();
	animatedObjects.clear();

	std::vector<Item_t> items;
	items.push_back(Item_t(COOKIE, YELLOW));
	items.push_back(Item_t(KEY, GREEN));
	items.push_back(Item_t(KEY, RED));

	Static_Object_Storage *currStaticObject = new Static_Object_Storage(48, 49, items);		// Sofa
	currStaticObject->setPosition(850, 52);
	staticObjects.push_back(currStaticObject);

	room1->setStaticObjects(staticObjects);
	room1->setAnimatedObjects(animatedObjects);


	// Room 2
	Room_Grandma *room2 = new Room_Grandma(REGULAR, 2, sf::IntRect(568, 332, 606, 285), 6000000);

	staticObjects.clear();
	animatedObjects.clear();

	items.clear();
	items.push_back(Item_t(COOKIE, YELLOW));

	currStaticObject = new Static_Object_Storage(50, 51, items);		// Tumbochka
	currStaticObject->setPosition(1017, 475);
	staticObjects.push_back(currStaticObject);

	room2->setStaticObjects(staticObjects);
	room2->setAnimatedObjects(animatedObjects);

	room2->setGrandmaPosition(792, 412);


	// Room 3
	Room_Tree *room3 = new Room_Tree(TREE, 1, sf::IntRect(1326, 332, 471, 285));

	staticObjects.clear();
	animatedObjects.clear();

	items.clear();
	items.push_back(Item_t(COOKIE, YELLOW));

	currStaticObject = new Static_Object_Storage(48, 49, items);		// Tumbochka
	currStaticObject->setPosition(1017, 475);
	staticObjects.push_back(currStaticObject);

	room1->setStaticObjects(staticObjects);
	room1->setAnimatedObjects(animatedObjects);

	// Christmas tree
	room3->setTreePosition(1553, 338);


	// Setting the links
	room0->Set_left_room(room1);
	room1->Set_down_room(room2);
	room1->Set_right_room(room0);
	room2->Set_top_room(room1);

	// Creating the array of doors
	std::vector<Door*> doors;

	// Door 0
	Door_rooms *door0 = new Door_rooms(0, false, YELLOW, 1, 0);
	door0->Set_pos(sf::Vector2u(1118, 24));

	// Door 1 and 2
	Door_front *door1 = new Door_front(1, true, GREEN, DOWN, 1, 2);
	Door_front *door2 = new Door_front(2, true, GREEN, TOP, 2, 1);

	door1->Set_pos(sf::Vector2u(618, 34));
	door2->Set_pos(sf::Vector2u(618, 341));

	// Setting the links
	door1->Set_adj_door_id(2);
	door2->Set_adj_door_id(1);

	room0->Set_left_door(door0);
	room1->Set_right_door(door0);
	room1->Set_down_door(door1);
	room2->Set_top_door(door2);

	// Adding rooms to the array
	rooms.push_back(room0);
	rooms.push_back(room1);
	rooms.push_back(room2);

	// Adding doors to the array
	doors.push_back(door0);
	doors.push_back(door1);
	doors.push_back(door2);

	Level *level = new Level(1, background, rooms, doors);

	Render::Get()->setStatus(RENDER_STATUS_GAME);
	Render::Get()->setLevel(level);
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

void Menu::santa_option_selected(int selectedSantaId)
{
	if (selectedSantaId == 0) { selected_option_id = 0; return; }
	if (available_santas[selectedSantaId - 1] == true) { selected_option_id = selectedSantaId; }
}





