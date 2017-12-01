#include "Door.h"

#define Door_closed_id 0
#define Door_closed_hovered_id 1
#define Door_closed_background_id 2
#define Door_opened_background_id 3

Door::Door(Door_t type, bool is_closed, Colour_t key)
	:m_type(type), m_is_closed(is_closed), m_key(key), m_background(nullptr), m_door(nullptr)
{
}


Door::~Door()
{
}

void Door::display_background(sf::RenderWindow *window)
{
	if (m_background != nullptr)
		m_background->display(window);

	if (m_is_closed)
		m_door->display(window);
}

//void Door::Set_is_closed(bool is_closed)
//{
//	m_is_closed = is_closed;
//
//	if (is_closed)
//	{
//		if (m_door != nullptr)
//			delete m_door;
//		m_door = new Static_Object_Hovered(Door_closed_id, Door_closed_hovered_id);
//
//		if (m_background != nullptr)
//		{
//			delete m_background;
//		}
//		m_background = new Static_Object(Door_closed_background_id);
//	}
//	else
//	{
//		if (m_door != nullptr)
//		{
//			delete m_door;
//			m_door = nullptr;
//		}
//
//		if (m_background != nullptr)
//			delete m_background;
//		m_background = new Static_Object(Door_opened_background_id);
//	}
//}
