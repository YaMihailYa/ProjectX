#include "Door_rooms.h"

Door_rooms::Door_rooms(unsigned int id, bool is_closed, Colour_t key, unsigned int cur_room_id,
	unsigned int adj_room_id)
	:Door(id, DOOR_ROOMS, is_closed, key, cur_room_id, adj_room_id), m_foreground(nullptr)
{
	
}


Door_rooms::~Door_rooms()
{
}

void Door_rooms::display_foreground(sf::RenderWindow *window)
{
	if (m_foreground != nullptr)
		m_foreground->display(window);
}

//void Door_rooms::def_closed()
//{
//	if (m_is_closed)
//	{
//		//m_door->checkHovered();
//		if (m_door->getIsHovered() && sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
//		{
//			// TODO: check if key is in inventory
//			exit(EXIT_FAILURE);
//			Set_is_closed(false);
//		}
//	}
//}

void Door_rooms::Set_is_closed(bool is_closed)
{
}
//void Door_rooms::Set_is_closed(bool is_closed)
//{
//	m_is_closed = is_closed;
//
//	if (is_closed)
//	{
//		if (m_door != nullptr)
//			delete m_door;
//		m_door = new Static_Object_Hovered(Door_rooms_closed_id, Door_rooms_closed_hovered_id);
//
//		if (m_foreground != nullptr)
//		{
//			delete m_foreground;
//			m_foreground = nullptr;
//		}
//
//		if (m_background != nullptr)
//		{
//			delete m_background;
//		}
//		m_background = new Static_Object(Door_rooms_closed_background_id);
//	}
//	else
//	{
//		if (m_door != nullptr)
//		{
//			delete m_door;
//			m_door = nullptr;
//		}
//
//		if (m_foreground != nullptr)
//			delete m_foreground;
//		m_foreground = new Static_Object(Door_rooms_opened_foreground_id);
//
//		if (m_background != nullptr)
//			delete m_background;
//		m_background = new Static_Object(Door_rooms_opened_background_id);
//	}
//}
