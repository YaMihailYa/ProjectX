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

	fillVectorButtons(type);
	last_x0_clicked = -1;
	last_y0_clicked = -1;
}

Menu::~Menu() { }

void Menu::fillVectorButtons(menu_type_t type, int rate)
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

		cntr_1 = 0;
		cntr_2 = 0;
		cntr_3 = 0;

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
		switch (rate)
		{
		case 0: { menu = new Static_Object(18); break; }
		case 1: { menu = new Static_Object(19); break; }
		case 2: { menu = new Static_Object(20); break; }
		}

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
		case 0: { suitNum = 88; available_santas[0] = true; break; }
		case 1: { suitNum = 89; available_santas[1] = true; break; }
		case 2: { suitNum = 87; available_santas[2] = true; break; }
		}

		std::ofstream myfile2("availables_santa_suits.txt", std::ios::out);
		if (myfile2.is_open())
		{
			myfile2 << available_santas[0] << " ";
			myfile2 << available_santas[1] << " ";
			myfile2 << available_santas[2] << " ";

			myfile2.close();
		}
		
		menu = new Static_Object(suitNum);

		Button btn1 = Button(723, 729, 450, 138, SANTA_SUIT_SELECTION, BTN_SANTA_SUIT);
		buttons.push_back(btn1);

		break;
	}
	case LOOT_BOX_END:
	{
		menu = new Static_Object(21);

		Button btn1 = Button(626, 772, 140, 92, LOOT_BOX_END, BTN_AGAIN);
		Button btn2 = Button(890, 767, 140, 92, LOOT_BOX_END, BTN_LEVEL_SELECTION);
		Button btn3 = Button(1153, 767, 140, 92, LOOT_BOX_END, BTN_HOME);

		buttons.push_back(btn1);
		buttons.push_back(btn2);
		buttons.push_back(btn3);

		break;
	}
	case HELP_1:
	{
		menu = new Static_Object(99);
		break;
	}
	case HELP_2:
	{
		menu = new Static_Object(100);
		break;
	}
	case HELP_3:
	{
		menu = new Static_Object(101);
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
				//printf("home\n");
				//exit(1);
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
	temp = false;

	switch (menuType)
	{
	case START:
		break;
	case PAUSE: {
		if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_PAUSE && buttons[0].isClicked()) {
			if (Render::Get()->Get_c_level()->Get_level_id() == 1) { menuType = LEVEL_1; }
			if (Render::Get()->Get_c_level()->Get_level_id() == 2) { menuType = LEVEL_2; }
			if (Render::Get()->Get_c_level()->Get_level_id() == 3) { menuType = LEVEL_3; }

			Render::Get()->Get_c_level()->Set_status(LEVEL_STATUS_GAME);
		}
		else if (buttons[1].isClicked()) {
			Render::Get()->setStatus(RENDER_STATUS_MENU);
			//-------------------
			delete Render::Get()->Get_c_level();
			Render::Get()->setLevel(nullptr);
			fillVectorButtons(LEVEL_SELECTION);
		}
		else if (buttons[2].isClicked()) {
			Render::Get()->setStatus(RENDER_STATUS_MENU);
			//--------------------
			//Render::Get()->Get_c_level()->~Level();
			delete Render::Get()->Get_c_level();
			Render::Get()->setLevel(nullptr);
			fillVectorButtons(START);
		}
		break;
	}
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
	case LEVEL_1: {
		if (Render::Get()->Get_c_level()->Get_level_id() == 1) {
			if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Render::Get()->Get_c_level()->Set_status(LEVEL_STATUS_PAUSE);
			}
			else if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME && sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			{
				Render::Get()->Get_c_level()->Set_status(LEVEL_HELP_1);
			}
			else if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME && cntr_1 == 0)
			{
				cntr_1 = 1;
				Render::Get()->Get_c_level()->Set_status(LEVEL_HELP_1);
			}
			
		}
	}
	case LEVEL_2: {
		if (Render::Get()->Get_c_level()->Get_level_id() == 2) {
			if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Render::Get()->Get_c_level()->Set_status(LEVEL_STATUS_PAUSE);
			}
			else if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME && sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			{
				Render::Get()->Get_c_level()->Set_status(LEVEL_HELP_2);
			}
			else if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME && cntr_2 == 0)
			{
				cntr_2 = 1;
				Render::Get()->Get_c_level()->Set_status(LEVEL_HELP_2);
			}
		}
	}
	case LEVEL_3: {
		if (Render::Get()->Get_c_level()->Get_level_id() == 3) {
			if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Render::Get()->Get_c_level()->Set_status(LEVEL_STATUS_PAUSE);
			}
			else if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME && sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			{
				Render::Get()->Get_c_level()->Set_status(LEVEL_HELP_3);
			}
			else if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME && cntr_3 == 0)
			{
				cntr_3 = 1;
				Render::Get()->Get_c_level()->Set_status(LEVEL_HELP_3);
			}
		}
	}
	case HELP_1: {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (Render::Get()->Get_c_level()->Get_level_id() == 1) { menuType = LEVEL_1; }
			if (Render::Get()->Get_c_level()->Get_level_id() == 2) { menuType = LEVEL_2; }
			if (Render::Get()->Get_c_level()->Get_level_id() == 3) { menuType = LEVEL_3; }

			Render::Get()->Get_c_level()->Set_status(LEVEL_STATUS_GAME);
		}
		
		break;
	}
	case HELP_2: {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (Render::Get()->Get_c_level()->Get_level_id() == 1) { menuType = LEVEL_1; }
			if (Render::Get()->Get_c_level()->Get_level_id() == 2) { menuType = LEVEL_2; }
			if (Render::Get()->Get_c_level()->Get_level_id() == 3) { menuType = LEVEL_3; }

			Render::Get()->Get_c_level()->Set_status(LEVEL_STATUS_GAME);
		}

		break;
	}
	case HELP_3: {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (Render::Get()->Get_c_level()->Get_level_id() == 1) { menuType = LEVEL_1; }
			if (Render::Get()->Get_c_level()->Get_level_id() == 2) { menuType = LEVEL_2; }
			if (Render::Get()->Get_c_level()->Get_level_id() == 3) { menuType = LEVEL_3; }

			Render::Get()->Get_c_level()->Set_status(LEVEL_STATUS_GAME);
		}

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
	else if (menuType == START) {
		Static_Object* light_text = nullptr;
		
		if (buttons[0].isHovered()) { light_text = new Static_Object(96); light_text->setPosition(889, 361); }
		else if (buttons[1].isHovered()) { light_text = new Static_Object(97); light_text->setPosition(845, 576); }
		else if (buttons[2].isHovered()) { light_text = new Static_Object(98); light_text->setPosition(909, 795); }
	
		if (light_text != nullptr) { light_text->display(window); }
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

	std::ifstream myfile("availables_santa_suits.txt");
	if (myfile.is_open())
	{
		myfile >> available_santas[0];
		myfile >> available_santas[1];
		myfile >> available_santas[2];

		myfile.close();
	}

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
	int level_id = Render::Get()->Get_c_level()->Get_level_id();

	delete Render::Get()->Get_c_level();
	Render::Get()->setLevel(nullptr);

	switch (level_id)
	{
	case 1: { lev_1(); break; }
	case 2: { lev_2(); break; }
	//case 3: { level_selection(); break; }
	}
}

void Menu::next_level()
{
	printf("BTN_NEXT_LEVEL\n");
	int level_id = Render::Get()->Get_c_level()->Get_level_id();

	delete Render::Get()->Get_c_level();
	Render::Get()->setLevel(nullptr);

	switch (level_id)
	{
	case 1: { lev_2(); break; }
	case 2: { level_selection(); break; }
	//case 3: { level_selection(); break; }
	}
}

void Menu::level_selection()
{
	printf("BTN_LEVEL_SELECTION\n");
	delete Render::Get()->Get_c_level();
	Render::Get()->setLevel(nullptr);
	fillVectorButtons(LEVEL_SELECTION);
}

void Menu::home()
{
	printf("BTN_HOME\n");
	delete Render::Get()->Get_c_level();
	Render::Get()->setLevel(nullptr);
	fillVectorButtons(START);
}

void Menu::lev_1()
{

	std::vector<Door_rooms*> doors_to_open;
	// Preparing to creating the level
	// Creating the background
	Static_Object *background = new Static_Object(64);

	// Creating the rooms
	// Creating the array of rooms
	std::vector<Room*> rooms;

	// Room 0
	Room *room0 = new Room(REGULAR, 0, sf::IntRect(1246, 24, 567, 285));

	std::vector<Static_Object_Hovered*> staticObjects;
	std::vector<Animated_Object*> animatedObjects;

	std::vector<Item_t> items;
	items.push_back(Item_t(COOKIE, YELLOW));
	items.push_back(Item_t(KEY, GREEN));
	items.push_back(Item_t(KEY, YELLOW));

	Static_Object_Storage *currStaticObject = new Static_Object_Storage(50, 51, items);		// Tumbochka
	currStaticObject->setPosition(1453, 166);
	staticObjects.push_back(currStaticObject);

	room0->setStaticObjects(staticObjects);
	room0->setAnimatedObjects(animatedObjects);


	// Room 1
	Room_Tree *room1 = new Room_Tree(TREE, 1, sf::IntRect(488, 24, 766, 285));

	staticObjects.clear();
	animatedObjects.clear();

	room1->setStaticObjects(staticObjects);
	room1->setAnimatedObjects(animatedObjects);

	// Christmas tree
	room1->setTreePosition(796, 28);


	// Room 2
	Room *room2 = new Room(REGULAR, 2, sf::IntRect(488, 332, 766, 285));

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
	Door_rooms *door0 = new Door_rooms(0, true, YELLOW, 1, 0);
	//doors_to_open.push_back(door0);
	

	// Door 1 and 2
	Door_front *door1 = new Door_front(1, true, GREEN, DOWN, 1, 2);
	Door_front *door2 = new Door_front(2, true, GREEN, TOP, 2, 1);
	

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

	//if(Render::Get()->Get_c_level)

	Level *level = new Level(1, background, rooms, doors);

	

	Render::Get()->setStatus(RENDER_STATUS_GAME);
	Render::Get()->setLevel(level);

	for (int i = 0; i < doors_to_open.size(); ++i)
	{
		doors_to_open[i]->Set_is_closed(false);
	}
	door0->Set_pos(sf::Vector2u(1118, 24));
	door1->Set_pos(sf::Vector2u(618, 34));
	door2->Set_pos(sf::Vector2u(618, 341));

	menuType = LEVEL_1;
}

void Menu::lev_2()
{
	std::vector<Door_rooms*> doors_to_open;
	// Preparing to creating the level
	// Creating the background
	Static_Object *background = new Static_Object(65);

	// Creating the rooms
	// Creating the array of rooms
	std::vector<Room*> rooms;

	// Room 0
	Room *room0 = new Room(REGULAR, 0, sf::IntRect(1326, 24, 407, 285));

	std::vector<Static_Object_Hovered*> staticObjects;
	std::vector<Animated_Object*> animatedObjects;

	room0->setStaticObjects(staticObjects);
	room0->setAnimatedObjects(animatedObjects);


	// Room 1
	Room *room1 = new Room(REGULAR, 1, sf::IntRect(568, 24, 606, 285));

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
	Room_Grandma *room2 = new Room_Grandma(GRANDMA, 2, sf::IntRect(568, 332, 656, 285), 9000000);

	staticObjects.clear();
	animatedObjects.clear();

	items.clear();
	items.push_back(Item_t(COOKIE, YELLOW));

	currStaticObject = new Static_Object_Storage(50, 51, items);		// Tumbochka
	currStaticObject->setPosition(1017, 475);
	staticObjects.push_back(currStaticObject);

	room2->setStaticObjects(staticObjects);
	room2->setAnimatedObjects(animatedObjects);

	room2->setGrandmaPosition(792, 402);


	// Room 3
	Room_Tree *room3 = new Room_Tree(TREE, 3, sf::IntRect(1276, 332, 457, 285));

	staticObjects.clear();
	animatedObjects.clear();

	items.clear();
	items.push_back(Item_t(COOKIE, YELLOW));

	currStaticObject = new Static_Object_Storage(48, 49, items);		// Sofa
	currStaticObject->setPosition(1390, 362);
	staticObjects.push_back(currStaticObject);

	room3->setStaticObjects(staticObjects);
	room3->setAnimatedObjects(animatedObjects);

	// Christmas tree
	room3->setTreePosition(1553, 338);


	// Setting the links
	room0->Set_left_room(room1);
	room1->Set_down_room(room2);
	room1->Set_right_room(room0);
	room2->Set_top_room(room1);
	room2->Set_right_room(room3);
	room3->Set_left_room(room2);

	// Creating the array of doors
	std::vector<Door*> doors;

	// Door 0
	Door_rooms *door0 = new Door_rooms(0, false, YELLOW, 1, 0);
	doors_to_open.push_back(door0);
	

	// Door 1 and 2
	Door_front *door1 = new Door_front(1, true, GREEN, DOWN, 1, 2);
	Door_front *door2 = new Door_front(2, true, GREEN, TOP, 2, 1);

	

	// Door 3
	Door_rooms *door3 = new Door_rooms(3, true, RED, 2, 3);
	

	// Setting the links
	door1->Set_adj_door_id(2);
	door2->Set_adj_door_id(1);

	room0->Set_left_door(door0);
	room1->Set_right_door(door0);
	room1->Set_down_door(door1);
	room2->Set_top_door(door2);
	room2->Set_right_door(door3);
	room3->Set_left_door(door3);

	// Adding rooms to the array
	rooms.push_back(room0);
	rooms.push_back(room1);
	rooms.push_back(room2);
	rooms.push_back(room3);

	// Adding doors to the array
	doors.push_back(door0);
	doors.push_back(door1);
	doors.push_back(door2);
	doors.push_back(door3);

	Level *level = new Level(2, background, rooms, doors);

	

	Render::Get()->setStatus(RENDER_STATUS_GAME);
	Render::Get()->setLevel(level);

	for (int i = 0; i < doors_to_open.size(); ++i)
	{
		doors_to_open[i]->Set_is_closed(false);
	}
	door3->Set_pos(sf::Vector2u(1118, 332));
	door1->Set_pos(sf::Vector2u(618, 34));
	door2->Set_pos(sf::Vector2u(618, 341));
	door0->Set_pos(sf::Vector2u(1118, 24));

	menuType = LEVEL_2;
}

void Menu::lev_3()
{
	std::vector<Door_rooms*> doors_to_open;
	std::vector<Door_front*> doors_front_to_open;
	// Preparing to creating the level
	// Creating the background
	Static_Object *background = new Static_Object(66);

	// Creating the rooms
	// Creating the array of rooms
	std::vector<Room*> rooms;

	// Room 0
	Room *room0 = new Room(REGULAR, 0, sf::IntRect(1238, 24, 496, 285));

	std::vector<Static_Object_Hovered*> staticObjects;
	std::vector<Animated_Object*> animatedObjects;

	room0->setStaticObjects(staticObjects);
	room0->setAnimatedObjects(animatedObjects);


	// Room 1
	Room *room1 = new Room(REGULAR, 1, sf::IntRect(614, 24, 472, 285));

	staticObjects.clear();
	animatedObjects.clear();

	std::vector<Item_t> items;
	items.push_back(Item_t(KEY, GREEN));
	items.push_back(Item_t(KEY, ORANGE));
	// Kee from safe

	Static_Object_Storage *currStaticObject = new Static_Object_Storage(50, 51, items);		// Tumbochka

	currStaticObject->setPosition(818, 167);
	staticObjects.push_back(currStaticObject);

	room1->setStaticObjects(staticObjects);
	room1->setAnimatedObjects(animatedObjects);


	// Room 2
	Room *room2 = new Room(REGULAR, 2, sf::IntRect(564, 332, 522, 285));

	staticObjects.clear();
	animatedObjects.clear();

	items.clear();
	items.push_back(Item_t(BONE, YELLOW));
	items.push_back(Item_t(WRENCH, YELLOW));
	items.push_back(Item_t(COOKIE, YELLOW));
	items.push_back(Item_t(KEY, BLUE));

	currStaticObject = new Static_Object_Storage(50, 51, items);		// Tumbochka
	currStaticObject->setPosition(969, 477);
	staticObjects.push_back(currStaticObject);

	room2->setStaticObjects(staticObjects);
	room2->setAnimatedObjects(animatedObjects);


	// Room 3
	Room *room3 = new Room(REGULAR, 3, sf::IntRect(172, 332, 341, 285));

	staticObjects.clear();
	animatedObjects.clear();

	items.clear();
	items.push_back(Item_t(COOKIE, YELLOW));

	currStaticObject = new Static_Object_Storage(48, 49, items);		// Sofa
	currStaticObject->setPosition(193, 362);
	staticObjects.push_back(currStaticObject);

	room3->setStaticObjects(staticObjects);
	room3->setAnimatedObjects(animatedObjects);


	// Room 4
	Room_Grandma *room4 = new Room_Grandma(GRANDMA, 4, sf::IntRect(1238, 332, 496, 285), 9000000);

	staticObjects.clear();
	animatedObjects.clear();

	/*Static_Object_Hovered *currStaticObjectHovered = new Static_Object_Hovered(63, 71);		// Schitovaja
	currStaticObject->setPosition(1485, 389);
	staticObjects.push_back(currStaticObjectHovered);*/

	room4->setStaticObjects(staticObjects);
	room4->setAnimatedObjects(animatedObjects);

	room4->setGrandmaPosition(1300, 412);


	// Room 5
	Room_Dog *room5 = new Room_Dog(DOG, 5, sf::IntRect(1188, 640, 596, 285), 3000000);

	staticObjects.clear();
	animatedObjects.clear();

	room5->setStaticObjects(staticObjects);
	room5->setAnimatedObjects(animatedObjects);

	room5->setDogPosition(1340, 721);


	// Room 6
	Room_Tree *room6 = new Room_Tree(TREE, 6, sf::IntRect(614, 640, 596, 285));

	items.clear();
	items.push_back(Item_t(COOKIE, YELLOW));

	currStaticObject = new Static_Object_Storage(52, 53, items);		// Safe
	currStaticObject->setPosition(808, 785);
	staticObjects.push_back(currStaticObject);

	room6->setStaticObjects(staticObjects);
	room6->setAnimatedObjects(animatedObjects);

	room6->setTreePosition(619, 649);


	// Setting the links
	room0->Set_left_room(room1);
	room1->Set_down_room(room2);
	room1->Set_right_room(room0);
	room2->Set_top_room(room1);
	room2->Set_left_room(room3);
	room2->Set_right_room(room4);
	room3->Set_right_room(room2);
	room4->Set_left_room(room2);
	room4->Set_down_room(room5);
	room5->Set_top_room(room4);
	room5->Set_left_room(room6);
	room6->Set_right_room(room5);

	// Creating the array of doors
	std::vector<Door*> doors;

	// Door 0
	Door_rooms *door0 = new Door_rooms(0, false, YELLOW, 1, 0);
	doors_to_open.push_back(door0);
	


	// Door 1 and 2
	Door_front *door1 = new Door_front(1, true, GREEN, DOWN, 1, 2);
	Door_front *door2 = new Door_front(2, true, GREEN, TOP, 2, 1);

	// Door 3
	Door_rooms *door3 = new Door_rooms(3, true, BLUE, 3, 2);
	//doors_to_open.push_back(door3);

	// Door 4
	Door_rooms *door4 = new Door_rooms(4, false, RED, 2, 4);
	doors_to_open.push_back(door4);
	

	// Door 5 and 6
	Door_front *door5 = new Door_front(5, false, PINK, DOWN, 4, 5);
	doors_front_to_open.push_back(door5);
	Door_front *door6 = new Door_front(6, false, PINK, TOP, 5, 4);
	doors_front_to_open.push_back(door6);

	

	// Door 7
	Door_rooms *door7 = new Door_rooms(7, true, ORANGE, 6, 5);
	//doors_to_open.push_back(door7);


	// Setting the links
	door1->Set_adj_door_id(2);
	door2->Set_adj_door_id(1);

	door5->Set_adj_door_id(6);
	door6->Set_adj_door_id(5);

	room0->Set_left_door(door0);
	room1->Set_right_door(door0);
	room1->Set_down_door(door1);
	room2->Set_top_door(door2);
	room2->Set_left_door(door3);
	room2->Set_right_door(door4);
	room3->Set_right_door(door3);
	room4->Set_left_door(door4);
	room4->Set_down_door(door5);
	room5->Set_top_door(door6);
	room5->Set_left_door(door7);
	room6->Set_right_door(door7);

	// Adding rooms to the array
	rooms.push_back(room0);
	rooms.push_back(room1);
	rooms.push_back(room2);
	rooms.push_back(room3);
	rooms.push_back(room4);
	rooms.push_back(room5);
	rooms.push_back(room6);

	// Adding doors to the array
	doors.push_back(door0);
	doors.push_back(door1);
	doors.push_back(door2);
	doors.push_back(door3);
	doors.push_back(door4);
	doors.push_back(door5);
	doors.push_back(door6);
	doors.push_back(door7);

	Level *level = new Level(3, background, rooms, doors);

	

	Render::Get()->setStatus(RENDER_STATUS_GAME);
	Render::Get()->setLevel(level);

	for (int i = 0; i < doors_to_open.size(); ++i)
	{
		doors_to_open[i]->Set_is_closed(false);
	}
	for (int i = 0; i < doors_front_to_open.size(); ++i)
	{
		doors_front_to_open[i]->Set_is_closed(false);
	}

	door5->Set_pos(sf::Vector2u(1588, 341));
	door6->Set_pos(sf::Vector2u(1588, 649));
	door4->Set_pos(sf::Vector2u(1030, 332));
	door3->Set_pos(sf::Vector2u(406, 332));
	door0->Set_pos(sf::Vector2u(1030, 24));
	door1->Set_pos(sf::Vector2u(668, 34));
	door2->Set_pos(sf::Vector2u(668, 341));
	door7->Set_pos(sf::Vector2u(1030, 641));

	menuType = LEVEL_3;
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





