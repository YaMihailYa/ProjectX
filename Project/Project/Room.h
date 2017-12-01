#pragma once
#include "globals.h"
#include "Door.h"

enum Room_t
{
	REGULAR,
	GRANDMA,
	DOG
};

class Room
{
public:
	Room(Room_t type, unsigned int id, sf::IntRect rect, bool enterable);
	~Room();

	/**
	* Move player
	* @param old_coords old coordinates of player
	* @param new_coords new coordinates of player
	* @param dir directions in which player was moved
	* @return new coorcdinates of player
	*/
	sf::Vector2u move_player(sf::Vector2u old_coords, sf::Vector2u new_coords, Direction_t dir);

	bool Get_enterable() const { return m_enterable; }

	void Set_enterable(bool enterable) { m_enterable = enterable; }
	void Set_right_room(Room *right_room) { m_right_room = right_room; }
	void Set_left_room(Room *left_room) { m_left_room = left_room; }
	void Set_top_room(Room *top_room) { m_top_room = top_room; }
	void Set_down_room(Room *down_room) { m_down_room = down_room; }
	
	void Set_right_door(Door *right_door) { m_right_door = right_door; }
	void Set_left_door(Door *left_door) { m_left_door = left_door; }
	void Set_top_door(Door *top_door) { m_top_door = top_door; }
	void Set_down_door(Door *down_door) { m_down_door = down_door; }

protected:
	//void Entered();

	unsigned int m_id;
	Room_t m_type;

	// Rectangle of room
	sf::IntRect m_rect;
	bool m_enterable;

	Room *m_right_room;
	Room *m_left_room;
	Room *m_top_room;
	Room *m_down_room;

	Door *m_right_door;
	Door *m_left_door;
	Door *m_top_door;
	Door *m_down_door;

};

