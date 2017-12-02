#pragma once
#include "Door.h"
class Door_rooms :
	public Door
{
public:
	/**
	* @param id - id of door
	* @param is_closed - if door is closed
	* @param key - colour of key to open door
	* @param cur_room_id - room where door is set (left)
	* @param adj_room_id - adjacent room for this door (right)
	*/
	Door_rooms(unsigned int id, bool is_closed, Colour_t key, unsigned int left_room_id,
		unsigned int right_room_id);
	~Door_rooms();

	void Set_is_closed(bool is_closed);
	// pos without using coef
	void Set_pos(sf::Vector2u pos);

	void display_background(sf::RenderWindow *window);
	void display_foreground(sf::RenderWindow *window);

	void go_throw_the_door();

	void control();

protected:
	Static_Object *m_foreground;
};

