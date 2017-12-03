#include "Door_front.h"
#include "Render.h"
#include "Player.h"
#include "Inventory.h"


Door_front::Door_front(unsigned int id, bool is_closed, Colour_t key, Direction_t tp_dir,
	unsigned int cur_room_id, unsigned adj_room_id)
	:Door(id, DOOR_FRONT, is_closed, key, cur_room_id, adj_room_id), m_tp_dir(tp_dir)
{
	/*m_background = new Static_Object(24);
	m_door = new Static_Object_Hovered(22, 23);
	m_door_handle = new Static_Object()*/
	//Set_is_closed(is_closed);
	if (is_closed)
		Set_is_closed(true);
}


Door_front::~Door_front()
{
}

void Door_front::Set_is_closed(bool is_closed)
{
	m_is_closed = is_closed;
	
	if (is_closed)
	{
		if (m_door != nullptr)
			delete m_door;
		m_door = new Static_Object_Hovered(23, 22);

		if (m_background != nullptr)
		{
			delete m_background;
		}
		m_background = new Static_Object(24);

		if (m_door_handle != nullptr)
		{
			delete m_door_handle;
		}

		switch (m_key)
		{
		case YELLOW:
			m_door_handle = new Static_Object(30);
			break;
		case GREEN:
			m_door_handle = new Static_Object(26);
			break;
		case BLUE:
			m_door_handle = new Static_Object(25);
			break;
		case RED:
			m_door_handle = new Static_Object(29);
			break;
		case PINK:
			m_door_handle = new Static_Object(28);
			break;
		case ORANGE:
			m_door_handle = new Static_Object(27);
			break;
		default:
			break;
		}
	}
	else
	{
		if (m_door != nullptr)
		{
			delete m_door;
			m_door = nullptr;
		}
		m_door = new Static_Object_Hovered(23, 22);
		

		if (m_background != nullptr)
		{
			delete m_background;
		}
		m_background = new Static_Object(24);

		if (m_door_handle != nullptr)
		{
			delete m_door_handle;
		}

		switch (m_key)
		{
		case YELLOW:
			m_door_handle = new Static_Object(30);
			break;
		case GREEN:
			m_door_handle = new Static_Object(26);
			break;
		case BLUE:
			m_door_handle = new Static_Object(25);
			break;
		case RED:
			m_door_handle = new Static_Object(29);
			break;
		case PINK:
			m_door_handle = new Static_Object(28);
			break;
		case ORANGE:
			m_door_handle = new Static_Object(27);
			break;
		default:
			break;
		}
	}

	Set_pos(m_pos);
}

// pos without using coef
void Door_front::Set_pos(sf::Vector2u pos)
{
	m_pos = pos;
	m_background->setPosition(pos.x, pos.y);
	m_door->setPosition(pos.x + 11, pos.y + 12);
	m_door_handle->setPosition(pos.x + 82, pos.y + 128);
}

void Door_front::control()
{
	if (Player::Get()->Get_clicked() && m_door->Get_sprite().getGlobalBounds().contains(sf::Vector2f(Player::Get()->Get_c_pos())))
	{
		
		if (m_is_closed)
		{
			if (Inventory::Get()->checkElement(Item_t(KEY, m_key)))
			{
				Inventory::Get()->del_item(Item_t(KEY, m_key));
				Set_is_closed(false);
				if (m_door_handle != nullptr)
					delete m_door_handle;
				m_door_handle = new Static_Object(74);
				Render::Get()->Get_c_level()->Get_door_by_id(m_adj_door_id)->Set_is_closed(false);
			}
		}
		else
		{
			go_throw_the_door();
		}
	}
}

void Door_front::go_throw_the_door()
{
	sf::Vector2f player_pos = Player::Get()->Get_c_pos();
	if (m_tp_dir == DOWN)
	{
		player_pos.y -= 309;
	}
	else
	{
		player_pos.y += 309;
	}

	Player* player = Player::Get();
	player->Set_c_pos(player_pos);
	player->Set_c_room(m_adj_room_id);
}
