#include "Level.h"
#include "Menu.h"


Level::Level(unsigned int id, Static_Object *_backGround, std::vector<Room*> _rooms,
	std::vector<Door*> _doors, sf::Vector2f player)
	:m_id(id), m_backGround(_backGround), m_rooms(_rooms), m_doors(_doors), m_status(LEVEL_STATUS_GAME)
{
	this->m_player = new Player(100);
}


Level::~Level()
{
	delete this->m_player;
}


void Level::Set_status(Level_status_t status)
{
	switch (status)
	{
	case LEVEL_STATUS_PAUSE:
	{
		Menu::Get()->fillVectorButtons(PAUSE);
		break;
	}
	case LEVEL_STATUS_END:
	{
		Menu::Get()->fillVectorButtons(LEVEL_END);
		break;
	}
	case LEVEL_STATUS_FAILED:
	{
		Menu::Get()->fillVectorButtons(LEVEL_FAILED);
		break;
	}
	}
}


void Level::Display(sf::RenderWindow *window, unsigned int _time)
{
	// Displaying background
	this->m_backGround->display(window);

	// Displaying the rooms
	int roomsSize = this->m_rooms.size();
	for (int i = 0; i < roomsSize; i++)
	{
		this->m_rooms[i]->display(window, _time);
	}

	// Displaying the backgrounds of doors
	int doorsSize = this->m_doors.size();
	for (int i = 0; i < doorsSize; i++)
	{
		this->m_doors[i]->display_background(window);
	}

	// Displaying the player
	this->m_player->display(window, _time);

	// Displaying the foregrounds of doors
	for (int i = 0; i < doorsSize; i++)
	{
		this->m_doors[i]->display_foreground(window);
	}

	// If not active game
	switch (this->m_status)
	{
	case LEVEL_STATUS_PAUSE: {
		Menu::Get()->display(window);

		break;
	}
	case LEVEL_STATUS_END:
	{
		Menu::Get()->display(window);

		break;
	}
	case LEVEL_STATUS_FAILED:
	{
		Menu::Get()->display(window);

		break;
	}
	default:
		break;
	}
}
