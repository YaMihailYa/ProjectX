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
	m_textures->Add_texture("Resurses/Images/interface/background.png"); // 9
	m_textures->Add_texture("Resurses/Images/interface/paused.png");	 // 10
	m_textures->Add_texture("Resurses/Images/interface/level_failed.png");	  // 11
	m_textures->Add_texture("Resurses/Images/interface/level_selection.png"); // 12
	// #Interface level menu
	m_textures->Add_texture("Resurses/Images/interface/menu_level/Menu_level_00.png"); // 13
	m_textures->Add_texture("Resurses/Images/interface/menu_level/Menu_level_01.png"); // 14
	m_textures->Add_texture("Resurses/Images/interface/menu_level/Menu_level_02.png"); // 15
	m_textures->Add_texture("Resurses/Images/interface/menu_level/Menu_level_03.png"); // 16
	// #Interface level completed
	m_textures->Add_texture("Resurses/Images/interface/level_completed/Level_completed_0.png"); // 17
	m_textures->Add_texture("Resurses/Images/interface/level_completed/Level_completed_1.png"); // 18
	m_textures->Add_texture("Resurses/Images/interface/level_completed/Level_completed_2.png"); // 19
	m_textures->Add_texture("Resurses/Images/interface/level_completed/Level_completed_3.png"); // 20


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
		m.onClick();
		
		m_window->display();
	}
}
