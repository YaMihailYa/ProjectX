#pragma once
#include "Static_Object_Hovered.h"
#include "globals.h"

enum Door_t
{
	DOOR,
	DOOR_ROOMS
};

class Door
{
public:
	/**
	* @param type - type of door
	* @param is_closed - if door is closed
	* @param key - colour of key to open door
	*/
	Door(Door_t type, bool is_closed, Colour_t key);
	~Door();

	virtual void Set_is_closed(bool is_closed) = 0;
	virtual void def_closed() = 0;

	virtual void move_next() = 0;
	
	void display_background(sf::RenderWindow *window);

protected:
	Door_t m_type;

	const Colour_t m_key;

	bool m_is_closed;
	Static_Object_Hovered* m_door;
	Static_Object *m_background;
};

