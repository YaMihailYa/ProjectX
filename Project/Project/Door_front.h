#pragma once
#include "Door.h"

class Door_front
	: public Door
{
public:
	/**
	* @param id - id of door
	* @param type - type of door
	* @param is_closed - if door is closed
	* @param key - colour of key to open door
	* @param tp_dir - direction in which player must be teleported (UP/DOWN)
	* @param cur_room_id - room where door is set
	* @param adj_room_id - adjacent room for this door
	*/
	Door_front(unsigned int id, bool is_closed, Colour_t key, Direction_t tp_dir,
		unsigned int cur_room_id, unsigned adj_room_id);
	~Door_front();

	void Set_is_closed(bool is_closed);
	// pos without using coef
	void Set_pos(sf::Vector2u pos);

	void Set_adj_door_id(unsigned int adj_door_id) { m_adj_door_id = adj_door_id; }

	void control();

	void go_throw_the_door();

protected:
	unsigned int m_adj_door_id;
	Direction_t m_tp_dir;
};

