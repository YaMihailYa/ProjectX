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
	LEVEL_STATUS_FAILED,
	LEVEL_HELP_1,
	LEVEL_HELP_2,
	LEVEL_HELP_3
};

class Level
{
public:
	Level(unsigned int id, Static_Object *_backGround, std::vector<Room*> _rooms,
			std::vector<Door*> _doors);
	~Level();

	// Display all objects of current level
	void Display(sf::RenderWindow *window, unsigned int _time);

	Room* Get_room_by_id(unsigned int room_id) { return m_rooms[room_id]; }
	Door* Get_door_by_id(unsigned int door_id) { return m_doors[door_id]; }

	unsigned int Get_level_id() { return m_id; }
	void Set_status(Level_status_t status);
	Level_status_t Get_status() { return this->m_status; }

	std::vector<Room*> Get_rooms() { return m_rooms; }
	int Get_quantity_of_rooms() { return m_rooms.size(); }

protected:
	Level_status_t m_status;
	unsigned int m_id;

	Static_Object *m_backGround;
	std::vector<Room*> m_rooms;
	std::vector<Door*> m_doors;

	Player *m_player;
};