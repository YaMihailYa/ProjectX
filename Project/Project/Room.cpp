#include "Room.h"
#include "Player.h"
#include "Render.h"
#include "Level.h"


Room::Room(Room_t type, unsigned int id, sf::IntRect rect, bool enterable)
	:m_type(type), m_id(id), m_rect(rect), m_enterable(enterable)
{
	m_left_room = nullptr;
	m_right_room = nullptr;
	m_top_room = nullptr;
	m_down_room = nullptr;

	m_left_door = nullptr;
	m_right_door = nullptr;
	m_top_door = nullptr;
	m_down_door = nullptr;
}


Room::~Room()
{
	for (int i = 0; i < this->m_staticObjects.size(); i++)
	{
		delete this->m_staticObjects[i];
	}

	for (int i = 0; i < this->m_animatedObjects.size(); i++)
	{
		delete this->m_animatedObjects[i];
	}
}

sf::Vector2u Room::move_player(sf::Vector2u old_coords, sf::Vector2u new_coords, Direction_t dir)
{
	if (dir == LEFT)
	{
		// If player get out of m_rect
		if (new_coords.x < m_rect.left)
		{
			// If left room is connected and enterable
			if (m_left_room != nullptr && m_left_room->Get_enterable())
			{
				return m_left_room->move_player(old_coords, new_coords, dir);
			}
			else
			{
				Player::Get()->Set_c_room(m_id);
				old_coords.x = m_rect.left;
				return old_coords;
			}
		}
		else
		{
			Player::Get()->Set_c_room(m_id);
			return new_coords;
		}
	}
	else if (dir == RIGHT)
	{
		// If player get out of rect
		if (old_coords.x > m_rect.left + m_rect.width)
		{
			// If right room is connected and enterable
			if (m_right_room != nullptr && m_right_room->Get_enterable())
			{
				return m_right_room->move_player(old_coords, new_coords, dir);
			}
			else
			{
				Player::Get()->Set_c_room(m_id);
				old_coords.x = m_rect.left + m_rect.width;
				return old_coords;
			}
		}
		else
		{
			Player::Get()->Set_c_room(m_id);
			return new_coords;
		}
	}
	else
		exit(EXIT_FAILURE);
}


void Room::setStaticObjects(std::vector<Static_Object_Hovered*> _staticObjects)
{
	this->m_staticObjects = _staticObjects;
}


void Room::setAnimatedObjects(std::vector<Animated_Object*> _animatedObjects)
{
	this->m_animatedObjects = _animatedObjects;
}


float Room::getCoordByDirection(Direction_t direction)
{
	switch (direction)
	{
	case LEFT:
	{
		return this->m_rect.left;
	}
	case RIGHT:
	{
		return this->m_rect.left + this->m_rect.width;
	}
	case TOP:
	{
		return this->m_top_door->get_center_coord();
	}
	case DOWN:
	{
		return this->m_down_door->get_center_coord();
	}
	}

	return 0;
}


Room* Room::getRoomByDirection(Direction_t direction)
{
	switch (direction)
	{
	case LEFT:
		return this->m_left_room;
	case RIGHT:
		return this->m_right_room;
	case TOP:
		return this->m_top_room;
	case DOWN:
		return this->m_down_room;
	default:
		break;
	}

	return nullptr;
}


Door* Room::getDoorByDirection(Direction_t direction)
{
	switch (direction)
	{
	case LEFT:
		return this->m_left_door;
	case RIGHT:
		return this->m_right_door;
	case TOP:
		return this->m_top_door;
	case DOWN:
		return this->m_down_door;
	default:
		break;
	}

	return nullptr;
}


void Room::display(sf::RenderWindow *window, unsigned int time) {
	// Displaying static objects
	for (int i = 0; i < this->m_staticObjects.size(); i++)
	{
		this->m_staticObjects[i]->display(window);
	}

	// Displaying animated objects
	for (int i = 0; i < this->m_animatedObjects.size(); i++)
	{
		if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME)
		{
			this->m_animatedObjects[i]->animate(time);
		}

		this->m_animatedObjects[i]->display(window);
	}
}
