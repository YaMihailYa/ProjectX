#pragma once
#include "Room.h"
/**
*	Base class for all levels
*	
*/

enum Level_status_t
{
	GAME,
	PAUSE,
	LEVEL_END,
	LEVEL_FAILED
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

protected:
	Level_status_t m_status;

	std::vector<Room*> m_rooms;
	const unsigned int m_id;
};