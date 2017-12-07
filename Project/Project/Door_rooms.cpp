#include "Door_rooms.h"
#include "Player.h"
#include "Inventory.h"
#include "Render.h"

Door_rooms::Door_rooms(unsigned int id, bool is_closed, Colour_t key, unsigned int left_room_id,
	unsigned int right_room_id)
	:Door(id, DOOR_ROOMS, is_closed, key, left_room_id, right_room_id), m_foreground(nullptr)
{
	//Set_is_closed(false);
	if (is_closed)
		Set_is_closed(true);
}


Door_rooms::~Door_rooms()
{
}

void Door_rooms::display_background(sf::RenderWindow *window)
{
	control();
	Door::display_background(window);
}

void Door_rooms::display_foreground(sf::RenderWindow *window)
{
	if (m_foreground != nullptr)
		m_foreground->display(window);
}

// pos without using coef
void Door_rooms::Set_pos(sf::Vector2u pos)
{
	m_pos = pos;
	if (m_background != nullptr)
		m_background->setPosition(pos.x, pos.y);

	if (m_is_closed)
	{
		if (m_door != nullptr)
			m_door->setPosition(pos.x + 70, pos.y + 13);

		if (m_door_handle != nullptr)
			m_door_handle->setPosition(pos.x + 89, pos.y + 134);
	}
	else
	{
		if (m_foreground != nullptr)
			m_foreground->setPosition(pos.x + 71, pos.y);

		if (m_door_handle != nullptr)
			m_door_handle->setPosition(pos.x + 273, pos.y + 132);
	}
}

void Door_rooms::go_throw_the_door()
{
	Player *player;
	player = Player::Get();
	sf::Vector2f player_pos = player->Get_c_pos();
	unsigned int c_room_id = player->Get_c_room();
	Level *level = Render::Get()->Get_c_level();

	sf::Vector2f coef = Render::Get()->Get_coef();
	// If player now in left room
	if (c_room_id == m_cur_room_id)
	{
		Room *adj = level->Get_room_by_id(m_adj_room_id);
		player_pos.x = adj->Get_rect().left/coef.x;
		player->Set_c_room(m_adj_room_id);
	}
	else
	{
		Room *cur = level->Get_room_by_id(m_cur_room_id);
		sf::IntRect tmp = cur->Get_rect();
		player_pos.x = (tmp.left + tmp.width)/coef.x;
		player->Set_c_room(m_cur_room_id);
	}

	player->Set_c_pos(player_pos);
}

void Door_rooms::control()
{
	if (Player::Get()->Get_clicked() && m_door!=nullptr && m_door->Get_sprite().getGlobalBounds().contains(sf::Vector2f(Player::Get()->Get_targer_pos())))
	{

		if (m_is_closed)
		{
			if (Inventory::Get()->checkElement(Item_t(KEY, m_key)))
			{
				Inventory::Get()->del_item(Item_t(KEY, m_key));
				Set_is_closed(false);
				
			

			}
		}
		else
		{
			go_throw_the_door();
		}
	}
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
	m_is_closed = is_closed;

	if (is_closed)
	{
		if (m_door != nullptr)
			delete m_door;
		m_door = new Static_Object_Hovered(33, 32);

		if (m_background != nullptr)
		{
			delete m_background;
		}
		m_background = new Static_Object(31);

		if (m_foreground != nullptr)
		{
			delete m_foreground;
			m_foreground = nullptr;
		}

		if (m_door_handle != nullptr)
		{
			delete m_door_handle;
		}

		switch (m_key)
		{
		case YELLOW:
			m_door_handle = new Static_Object(39);
			break;
		case GREEN:
			m_door_handle = new Static_Object(35);
			break;
		case BLUE:
			m_door_handle = new Static_Object(34);
			break;
		case RED:
			m_door_handle = new Static_Object(37);
			break;
		case PINK:
			m_door_handle = new Static_Object(38);
			break;
		case ORANGE:
			m_door_handle = new Static_Object(36);
			break;
		default:
			break;
		}
	}
	else
	{
		sf::Vector2f coef = Render::Get()->Get_coef();

		// Change sizes of m_rect for adjacent rooms
		Level *level = Render::Get()->Get_c_level();

		// Change for left room
		Room *room = level->Get_room_by_id(m_cur_room_id);
		sf::IntRect rect = room->Get_rect();
		rect.width += (64+ 20)* coef.x;
		room->Set_rect(rect);

		// Change for rigth room
		room = level->Get_room_by_id(m_adj_room_id);
		rect = room->Get_rect();
		rect.width += (64+20) * coef.x;
		rect.left -= (64-20) * coef.x;
		room->Set_rect(rect);
		if (m_door != nullptr)
		{
			delete m_door;
			m_door = nullptr;
		}

		if (m_background != nullptr)
		{
			delete m_background;
		}
		m_background = new Static_Object(40);

		if (m_foreground != nullptr)
		{
			delete m_foreground;
		}
		m_foreground = new Static_Object(41);




		if (m_door_handle != nullptr)
			delete m_door_handle;
		m_door_handle = new Static_Object(76);
		/*
				if (m_door_handle != nullptr)
		{
			delete m_door_handle;
		}
		switch (m_key)
		{
		case YELLOW:
			m_door_handle = new Static_Object(47);
			break;
		case GREEN:
			m_door_handle = new Static_Object(43);
			break;
		case BLUE:
			m_door_handle = new Static_Object(42);
			break;
		case RED:
			m_door_handle = new Static_Object(46);
			break;
		case PINK:
			m_door_handle = new Static_Object(45);
			break;
		case ORANGE:
			m_door_handle = new Static_Object(44);
			break;
		default:
			break;
		}*/
	}

	Set_pos(m_pos);
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
