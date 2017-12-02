#pragma once
#include "Room.h"
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
	Level(unsigned int id);
	~Level();

	// Display all objects of current level
	virtual void Display(sf::RenderWindow *window) = 0;

	Room* Get_room_by_id(unsigned int room_id) { return m_rooms[room_id]; }
	void Set_status(Level_status_t status) { m_status = status; }

	std::vector<Room*> Get_rooms() { return m_rooms; }
	int Get_quantity_of_rooms() { return m_rooms.size(); }

protected:
	Level_status_t m_status;

	std::vector<Room*> m_rooms;
	const unsigned int m_id;
};