#pragma once
#include "Room.h"
#include "Player.h"

/**
*	Base class for all levels
*	
*/

enum Level_status_t
{
	LEVEL_STATUS_GAME,
	LEVEL_STATUS_PAUSE,
	LEVEL_STATUS_END,
	LEVEL_STATUS_FAILED
};

class Level
{
public:
	Level(unsigned int id, Static_Object *_backGround, std::vector<Room*> _rooms,
			std::vector<Door*> _doors, sf::Vector2f player);
	~Level();

	// Display all objects of current level
	void Display(sf::RenderWindow *window, unsigned int _time);

	Room* Get_room_by_id(unsigned int room_id) { return m_rooms[room_id]; }
	void Set_status(Level_status_t status) { m_status = status; }

	std::vector<Room*> Get_rooms() { return m_rooms; }
	int Get_quantity_of_rooms() { return m_rooms.size(); }

protected:
	Level_status_t m_status;
	const unsigned int m_id;

	Static_Object *m_backGround;
	std::vector<Room*> m_rooms;
	std::vector<Door*> m_doors;

	Player *m_player;
};