#include "Render.h"



Render::Render()
{
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
}

void Render::Rendering()
{
	sf::Clock time_delay;
	unsigned int time_delay_mcs; // Time passed from last iteration in MICROSECONDS
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
		
		m_window->display();
	}
}
