#include "Door.h"
#include "Player.h"
#include "Render.h"

Door::Door(unsigned int id, Door_t type, bool is_closed, Colour_t key, unsigned int cur_room_id,
	unsigned int adj_room_id)
	:m_id(id), m_type(type), m_is_closed(is_closed), m_key(key), m_background(nullptr), m_door(nullptr), m_pos(0, 0)
{
}


Door::~Door()
{
	if (m_background != nullptr)
		delete m_background;

	if (m_door_handle != nullptr)
		delete m_door_handle;

	if (m_door != nullptr)
		delete m_door;
}

void Door::display_background(sf::RenderWindow *window)
{
	if (m_background != nullptr)
		m_background->display(window);

	if (m_door_handle != nullptr)
		m_door_handle->display(window);

	if (m_is_closed)
		m_door->display(window);
}

void Door::display_foreground(sf::RenderWindow *window)
{
	// Must be empty
	// All is OK
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


float Door::get_center_coord()
{
	switch (m_type)
	{
	case DOOR_FRONT:
		return m_pos.x*Render::Get()->Get_coef().x + m_background->Get_sprite().getGlobalBounds().width / 2;
		break;
	case DOOR_ROOMS:
		return (m_pos.x + 75)*Render::Get()->Get_coef().x;
		break;
	default:
		break;
	}
	return 0;
}
