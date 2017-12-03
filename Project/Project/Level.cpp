#include "Level.h"
#include "Menu.h"
#include "Inventory.h"
#include "Room_Dog.h"
#include "Room_Grandma.h"
#include "Room_Tree.h"


Level::Level(unsigned int id, Static_Object *_backGround, std::vector<Room*> _rooms,
	std::vector<Door*> _doors)
	:m_id(id), m_backGround(_backGround), m_rooms(_rooms), m_doors(_doors), m_status(LEVEL_STATUS_GAME)
{
	this->m_player = new Player(100);

	// Creating the inventory
	Inventory *inventory = new Inventory(sf::IntRect(294, 1017, 1445, 63));
}


Level::~Level()
{
	delete m_player;
	delete m_backGround;
}


void Level::Set_status(Level_status_t status)
{
	m_status = status;
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
		switch (m_rooms[i]->getType())
		{
		case REGULAR:
		{
			this->m_rooms[i]->display(window, _time);
			break;
		}
		case DOG:
		{
			((Room_Dog*)this->m_rooms[i])->display(window, _time);
			break;
		}
		case GRANDMA:
		{
			((Room_Grandma*)this->m_rooms[i])->display(window, _time);
			break;
		}
		case TREE:
		{
			((Room_Tree*)this->m_rooms[i])->display(window, _time);
			break;
		}
		}

		this->m_rooms[i]->display(window, _time);
	}

	// Displaying the backgrounds of doors
	int doorsSize = this->m_doors.size();
	for (int i = 0; i < doorsSize; i++)
	{
		this->m_doors[i]->display_background(window);
	}

	// Displaying the player
	this->m_player->Move();
	this->m_player->display(window, _time);

	// Displaying the foregrounds of doors
	for (int i = 0; i < doorsSize; i++)
	{
		this->m_doors[i]->display_foreground(window);
	}

	// Displaying the inventory
	Inventory::Get()->display(window);

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
