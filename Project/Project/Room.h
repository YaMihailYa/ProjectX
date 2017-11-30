#pragma once
#include "globals.h"

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
	sf::IntRect move_player(sf::IntRect old_coords, sf::IntRect new_coords, Direction_t dir);

	bool Get_enterable() const { return m_enterable; }

	void Set_enterable(bool enterable) { m_enterable = enterable; }
	void Set_right_room(Room *right_room) { m_right_room = right_room; }
	void Set_left_room(Room *left_room) { m_left_room = left_room; }


protected:
	void Entered();

	unsigned int m_id;
	Room_t m_type;

	// Rectangle of room
	sf::IntRect m_rect;
	bool m_enterable;

	Room *m_right_room;
	Room *m_left_room;

};

