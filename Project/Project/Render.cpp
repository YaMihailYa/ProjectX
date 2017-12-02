#include "Render.h"
#include "Menu.h"

Render* Render::m_this = nullptr;

Render::Render()
{
	Init();
	if (m_this != nullptr)
		exit(EXIT_FAILURE);
	m_this = this;
}


Render::~Render()
{
	delete m_window;
}


void Render::Init()
{
	// Create window
	m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game", sf::Style::Fullscreen);
	// Calculate coef
	sf::Vector2u window_size = m_window->getSize();
	m_coef_x = window_size.x / 1920.0f;
	m_coef_y = window_size.y / 1080.0f;

	m_textures = new Texture_loader;
	m_animations = new Animation_loader;

	// Load animations
	// #grandfather
	m_textures->Add_texture("Resurses/Images/animations/grandfather/gf_left.png");   // 0
	m_textures->Add_texture("Resurses/Images/animations/grandfather/gf_right.png");  // 1
	m_textures->Add_texture("Resurses/Images/animations/grandfather/gf_breath.png"); // 2
	// #grandmother
	m_textures->Add_texture("Resurses/Images/animations/grandmother/gm_does_not_sleep.png"); // 3
	m_textures->Add_texture("Resurses/Images/animations/grandmother/gm_is_sleeping.png");	 // 4
	// #dog
	m_textures->Add_texture("Resurses/Images/animations/dog/dog_barks.png");  // 5
	m_textures->Add_texture("Resurses/Images/animations/dog/dog_bone.png");   // 6
	m_textures->Add_texture("Resurses/Images/animations/dog/dog_dreams.png"); // 7
	// #cat
	m_textures->Add_texture("Resurses/Images/animations/cat/cat.png"); // 8
	
	// Load interface
	// #Interface backgrounds
	m_textures->Add_texture("Resurses/Images/interface/background.png");			// 9
	m_textures->Add_texture("Resurses/Images/interface/paused.png");				// 10
	m_textures->Add_texture("Resurses/Images/interface/level_failed.png");			// 11
	m_textures->Add_texture("Resurses/Images/interface/level_selection.png");		// 12
	m_textures->Add_texture("Resurses/Images/interface/Level_selection_temp.png");  // 13
	// #Interface level menu
	m_textures->Add_texture("Resurses/Images/interface/menu_level/Menu_level_00.png"); // 14
	m_textures->Add_texture("Resurses/Images/interface/menu_level/Menu_level_01.png"); // 15
	m_textures->Add_texture("Resurses/Images/interface/menu_level/Menu_level_02.png"); // 16
	m_textures->Add_texture("Resurses/Images/interface/menu_level/Menu_level_03.png"); // 17
	// #Interface level completed
	m_textures->Add_texture("Resurses/Images/interface/level_completed/Level_completed_0.png"); // 18
	m_textures->Add_texture("Resurses/Images/interface/level_completed/Level_completed_1.png"); // 19
	m_textures->Add_texture("Resurses/Images/interface/level_completed/Level_completed_2.png"); // 20
	m_textures->Add_texture("Resurses/Images/interface/level_completed/Level_completed_3.png"); // 21
	
	// Load gameplay images
	// #door->front
	m_textures->Add_texture("Resurses/Images/gameplay/door/front/door_frond_background_hover.png");     // 22
	m_textures->Add_texture("Resurses/Images/gameplay/door/front/door_front_background_not_hover.png"); // 23
	m_textures->Add_texture("Resurses/Images/gameplay/door/front/door_front_background.png");			// 24
	// #front->handles 
	m_textures->Add_texture("Resurses/Images/gameplay/door/front/handles/BLUE.png");   // 25
	m_textures->Add_texture("Resurses/Images/gameplay/door/front/handles/GREEN.png");  // 26
	m_textures->Add_texture("Resurses/Images/gameplay/door/front/handles/ORANGE.png"); // 27
	m_textures->Add_texture("Resurses/Images/gameplay/door/front/handles/PINK.png");   // 28
	m_textures->Add_texture("Resurses/Images/gameplay/door/front/handles/RED.png");    // 29
	m_textures->Add_texture("Resurses/Images/gameplay/door/front/handles/YELLOW.png"); // 30
	// #rooms->closed
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/closed/door_opened_background.png");			// 31 
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/closed/door_opened_background_hover.png");		// 32
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/closed/door_opened_background_not_hover.png"); // 33
	// #rooms->closed->handles
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/closed/handles/BLUE.png");   // 34
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/closed/handles/GREEN.png");  // 35
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/closed/handles/ORANGE.png"); // 36
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/closed/handles/RED.png");    // 37
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/closed/handles/VIOLET.png"); // 38
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/closed/handles/YELLOW.png"); // 39
	// #rooms->opened
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/opened/background.png"); // 40
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/opened/foreground.png"); // 41
	// #rooms->opened->handles
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/opened/handles/BLUE.png");   // 42
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/opened/handles/GREEN.png");  // 43
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/opened/handles/ORANGE.png"); // 44
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/opened/handles/PINK.png");   // 45
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/opened/handles/RED.png");    // 46
	m_textures->Add_texture("Resurses/Images/gameplay/door/rooms/opened/handles/YELLOW.png"); // 47
	// #kepts
	m_textures->Add_texture("Resurses/Images/gameplay/kepts/cupboard.png");         // 48
	m_textures->Add_texture("Resurses/Images/gameplay/kepts/cupboard_hover.png");   // 49
	m_textures->Add_texture("Resurses/Images/gameplay/kepts/nightstand.png");       // 50
	m_textures->Add_texture("Resurses/Images/gameplay/kepts/nightstand_hover.png"); // 51
	m_textures->Add_texture("Resurses/Images/gameplay/kepts/safe.png");				// 52
	m_textures->Add_texture("Resurses/Images/gameplay/kepts/safe_hover.png");		// 53
	// #small_items
	m_textures->Add_texture("Resurses/Images/gameplay/small_items/bone.png");		// 54
	m_textures->Add_texture("Resurses/Images/gameplay/small_items/cookie.png");		// 55
	m_textures->Add_texture("Resurses/Images/gameplay/small_items/wrench.png");		// 56
	// #small_items->keys
	m_textures->Add_texture("Resurses/Images/gameplay/small_items/keys/key_BLUE.png");		// 57
	m_textures->Add_texture("Resurses/Images/gameplay/small_items/keys/key_GREEN.png");		// 58
	m_textures->Add_texture("Resurses/Images/gameplay/small_items/keys/key_ORANGE.png");	// 59
	m_textures->Add_texture("Resurses/Images/gameplay/small_items/keys/key_PINK.png");		// 60
	m_textures->Add_texture("Resurses/Images/gameplay/small_items/keys/key_RED.png");		// 61
	m_textures->Add_texture("Resurses/Images/gameplay/small_items/keys/key_YELLOW.png");	// 62
	// gameplay_folder
	m_textures->Add_texture("Resurses/Images/gameplay/panel.png");	// 63


	// Initialization animations
	// #grandfather
	m_animations->add(0, 19);
	m_animations->add(1, 19);
	m_animations->add(2, 10);
	// #grandmother
	m_animations->add(3, 29);
	m_animations->add(4, 11);
	// #dog
	m_animations->add(5, 4);
	m_animations->add(6, 5);
	m_animations->add(7, 4);
	// #cat
	m_animations->add(8, 38);
}

void Render::Rendering()
{
	sf::Clock time_delay;
	unsigned int time_delay_mcs; // Time passed from last iteration in MICROSECONDS
	Menu m(START);
	//m.fillVectorButtons(menu_type_t::START);

	while (m_window->isOpen())
	{
		time_delay_mcs = time_delay.getElapsedTime().asMicroseconds();
		time_delay.restart();

		sf::Event ev;
		while (m_window->pollEvent(ev));
		{
			if (ev.type == sf::Event::Closed)
				m_window->close();
		}

		m_window->clear();

		// Here display level
		m.display(m_window);
		m.onKeyClick();
		m.onClick();
		
		m_window->display();
	}
}
