#pragma once
#include "Static_Object_Hovered.h"
#include "globals.h"

enum Door_t
{
	DOOR_FRONT,
	DOOR_ROOMS
};

class Door
{
public:
	/**
	* @param id - id of door
	* @param type - type of door
	* @param is_closed - if door is closed
	* @param key - colour of key to open door
	* @param cur_room_id - room where door is set
	* @param adj_room_id - adjacent room for this door
	*/
	Door(unsigned int id, Door_t type, bool is_closed, Colour_t key, unsigned int cur_room_id,
		unsigned int adj_room_id);
	~Door();

	virtual void Set_is_closed(bool is_closed) = 0;
	// pos without using coef
	virtual void Set_pos(sf::Vector2u pos) = 0;

	// Control click
	virtual void control() = 0;
	
	void display_background(sf::RenderWindow *window);
	virtual void display_foreground(sf::RenderWindow *window);

	virtual void Set_door_pos(float x, float y) = 0;
	//void Set_background(float x, float y) { m_background->setPosition(x, y); }

	// With using coef
	float get_center_coord();

	virtual void go_throw_the_door() = 0;

	bool getIsClosed() { return m_is_closed; }


protected:
	unsigned int m_id;
	unsigned int m_cur_room_id;
	unsigned int m_adj_room_id;

	Door_t m_type;

	const Colour_t m_key;

	bool m_is_closed;
	Static_Object_Hovered* m_door;
	Static_Object *m_background;
	Static_Object *m_door_handle;

	// Without using coef
	sf::Vector2u m_pos;
};

