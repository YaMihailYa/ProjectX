#include "Player.h"
#include "Render.h"
#include "Room.h"
 #include "Menu.h"

Player* Player::m_this = nullptr;

Player::Player(unsigned int speed)
	: m_c_pos(sf::Vector2u(1516, 181)), m_target_pos(sf::Vector2u(1516, 181)), m_status(ANIMATION_STAY),
		m_c_room_id(0), m_clicked(false), m_was_clicked(false)
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);
	m_this = this;
	
	sf::Vector2f coef = Render::Get()->Get_coef();
	this->m_speed = speed * coef.x;
	m_c_pos.x *= coef.x;
	m_c_pos.y *= coef.y;
	m_target_pos = m_c_pos;

	switch (Menu::Get()->selected_option_id) // load skin
	{
	case 0: // read
		this->m_left_anim = new Animated_Object(25, 0);
		this->m_right_anim = new Animated_Object(25, 1);
		this->m_stay_anim = new Animated_Object(10, 2);
		break;
	case 1: // green
		this->m_left_anim = new Animated_Object(25, 13);
		this->m_right_anim = new Animated_Object(25, 14);
		this->m_stay_anim = new Animated_Object(10, 12);
		break;
	case 2: // pink
		this->m_left_anim = new Animated_Object(25, 16);
		this->m_right_anim = new Animated_Object(25, 17);
		this->m_stay_anim = new Animated_Object(10, 15);
		break;
	case 3: // blue
		this->m_left_anim = new Animated_Object(25, 10);
		this->m_right_anim = new Animated_Object(25, 11);
		this->m_stay_anim = new Animated_Object(10, 9);
		break;
	default: // default skin = read
		this->m_left_anim = new Animated_Object(25, 0);
		this->m_right_anim = new Animated_Object(25, 1);
		this->m_stay_anim = new Animated_Object(10, 2);
		break;
	}

	

	// Green
	/*this->m_left_anim = new Animated_Object(25, 13);
	this->m_right_anim = new Animated_Object(25, 14);
	this->m_stay_anim = new Animated_Object(10, 12);*/

	//this->m_rect = (sf::IntRect) this->m_stay_anim->Get_sprite().getGlobalBounds();
	m_rect = (sf::IntRect)Animation_loader::Get()->getSprite(2, 0).getGlobalBounds();
}


Player::~Player()
{
	m_this = nullptr;
}

void Player::Set_c_pos(sf::Vector2f c_pos)
{
	m_c_pos = c_pos;
	sf::Vector2f coef =  Render::Get()->Get_coef();
	m_c_pos.x *= coef.x;
	m_c_pos.y *= coef.y;
}

void Player::display(sf::RenderWindow *window, unsigned int time)
{
	//m_status = ANIMATION_STAY;
	//move_to_x_coord(m_target_pos.x, time);
	this->m_clicked = false;

	printf("%d\n", m_c_room_id);
	if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME)
	{
		if (!this->m_move_directions.empty())
		{
			Direction_t currDirection = this->m_move_directions[0];
			Room *currRoom = Render::Get()->Get_c_level()->Get_room_by_id(m_c_room_id);

			float targetCoord = currRoom->getCoordByDirection(currDirection);

			if (this->m_c_pos.x == targetCoord)
			{
				this->m_move_directions.erase(this->m_move_directions.begin());

				Door *currDoor = currRoom->getDoorByDirection(currDirection);

				if (currDoor->getIsClosed())
				{
					this->m_move_directions.clear();
					m_target_pos.x = targetCoord;
					this->m_status = ANIMATION_STAY;
				}
				else
				{
					currDoor->go_throw_the_door();
				}
			}
			else
			{
				this->move_to_x_coord(targetCoord, time);
			}
		}
		else
		{
			// If we are in the target room
			//if (this->m_c_pos == this->m_target_pos)
			if (fabs(this->m_c_pos.x - this->m_target_pos.x) < 10)
			{
				if (m_was_clicked == true)
				{
					this->m_clicked = true;
					this->m_was_clicked = false;
				}

				this->m_status = ANIMATION_STAY;
				/*
				// If we are in the target room
				//if (this->m_c_pos == this->m_target_pos)
				if (fabs(this->m_c_pos.x - this->m_target_pos.x) < 10)
				{
					this->m_clicked = true;
					this->m_status = ANIMATION_STAY;
				}
				else
				{
					this->move_to_x_coord(this->m_target_pos.x, time);
				}*/
			}
			else
			{
				this->move_to_x_coord(this->m_target_pos.x, time);
			}
		}
	}
	

	// Displaying the player
	sf::Vector2f coef = Render::Get()->Get_coef();

	switch (m_status)
	{
	case ANIMATION_STAY:	
		if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME)
		{
			m_stay_anim->animate(time);
			m_rect = (sf::IntRect) m_stay_anim->Get_sprite().getGlobalBounds();

			m_stay_anim->setPosition((m_c_pos.x - m_rect.width / 2.) / coef.x, (m_c_pos.y - m_rect.width / 2.) / coef.y);
		}
		m_stay_anim->display(window);
		break;
	case ANIMATION_LEFT:
		if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME)
		{
			m_left_anim->animate(time);
			m_rect = (sf::IntRect) m_left_anim->Get_sprite().getGlobalBounds();
			m_left_anim->setPosition((m_c_pos.x - m_rect.width / 2.) / coef.x, (m_c_pos.y - m_rect.width / 2.) / coef.y);
		}
		m_left_anim->display(window);
		break;
	case ANIMATION_RIGHT:
		if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME)
		{
			m_right_anim->animate(time);
			m_rect = (sf::IntRect) m_right_anim->Get_sprite().getGlobalBounds();
			m_right_anim->setPosition((m_c_pos.x - m_rect.width / 2.) / coef.x, (m_c_pos.y - m_rect.width / 2.) / coef.y);
		}
		m_right_anim->display(window);
		break;
	default:
		break;
	}

	/*sf::Vector2u new_coords;
	new_coords = m_c_pos;
	Room* c_room = Render::Get()->Get_c_level()->Get_room_by_id(m_c_room_id);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_left_anim->animate(time);
		new_coords.x -= time*m_speed;
		m_c_pos = c_room->move_player(m_c_pos, new_coords, Direction_t::LEFT);
		m_left_anim->setPosition(m_c_pos.x, m_c_pos.y);
		m_left_anim->display(window);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_right_anim->animate(time);
		new_coords.x += time*m_speed;
		m_c_pos = c_room->move_player(m_c_pos, new_coords, Direction_t::RIGHT);
		m_right_anim->setPosition(m_c_pos.x, m_c_pos.y);
		m_right_anim->display(window);
	}
	else
	{
		m_stay_anim->animate(time);
		m_stay_anim->setPosition(m_c_pos.x, m_c_pos.y);
		m_stay_anim->display(window);
	}*/
	/* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		m_stay_anim->animate(time);
		m_stay_anim->display(window);
	}*/
}

void Player::Move()
{
	if (Render::is_clicked && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2f tagretPosCopy = m_target_pos;

		m_target_pos = sf::Vector2f(sf::Mouse::getPosition());
		m_move_directions.clear();

		// Finding the id of target room
		int targetRoomId = -1;

		m_was_clicked = true;
		std::vector<Room*> rooms = Render::Get()->Get_c_level()->Get_rooms();
		for (int i = 0; i < rooms.size(); i++)
		{
			if (rooms[i]->getRectOfRoom().contains((sf::Vector2i) m_target_pos))
			{
				targetRoomId = rooms[i]->getID();
				break;
			}
		}

		// If the room was found - find the route
		if (targetRoomId != -1)
		{
			// Array of visited rooms

			std::vector<bool> visitedRooms(Render::Get()->Get_c_level()->Get_quantity_of_rooms(), false);
			visitedRooms[m_c_room_id] = true;
			find_the_route(this->m_c_room_id, targetRoomId, visitedRooms);
		}
		else
		{
			m_target_pos = tagretPosCopy;
		}

		printf("\n\nDirections: ");
		for (int i = 0; i < m_move_directions.size(); ++i)
		{
			switch (m_move_directions[i])
			{
			case LEFT:
				printf("LEFT ");
				break;
			case RIGHT:
				printf("RIGHT ");
				break;
			case TOP:
				printf("TOP ");
				break;
			case DOWN:
				printf("DOWN ");
				break;
			default:
				break;
			}
		}
	}

}


void Player::move_to_x_coord(float _xCoord, unsigned int _time)
{
	if (this->m_c_pos.x < _xCoord)
	{
		// Moving right
		this->m_status = ANIMATION_RIGHT;

		this->m_c_pos.x += (float)_time * (float)this->m_speed / 1000000;

		// Checking if went through the border
		if (this->m_c_pos.x > _xCoord)
		{
			this->m_c_pos.x = _xCoord;
		}
	}
	else if (m_c_pos.x > _xCoord)
	{
		// Moving left
		this->m_status = ANIMATION_LEFT;

		this->m_c_pos.x -= (float)_time * (float)this->m_speed / 1000000;

		// Checking if went through the border
		if (this->m_c_pos.x < _xCoord)
		{
			this->m_c_pos.x = _xCoord;
		}
	}
	else
		m_status = ANIMATION_STAY;
}


//bool Player::find_the_route(unsigned int startRoomId, unsigned int endRoomId, std::vector<bool> &_visitedRooms)
bool Player::find_the_route(unsigned int c_room_id, unsigned int end_room_id, std::vector<bool> &_visitedRooms)
{
	if (end_room_id == c_room_id)
		return true;

	Room *c_room = Render::Get()->Get_c_level()->Get_room_by_id(c_room_id);
	for (int i = 0; i < 4; i++)
	{
		Room *c_adj_room = c_room->getRoomByDirection(static_cast<Direction_t>(i));
		if (c_adj_room == nullptr)
			continue;

		unsigned int c_adj = c_adj_room->getID();
		if (!_visitedRooms[c_adj])
		{
			m_move_directions.push_back(static_cast<Direction_t>(i));
			_visitedRooms[c_adj] = true;
			if (find_the_route(c_adj, end_room_id, _visitedRooms))
				return true;
			else
			{
				_visitedRooms[c_adj] = false;
				m_move_directions.pop_back();
			}

		}

	}

	return false;

	/*
	if (_visitedRooms[startRoomId])
	{
		return false;
	}

	_visitedRooms[startRoomId] = true;

	if (startRoomId == endRoomId)
	{
		return true;
	}

	Room *currRoom = Render::Get()->Get_c_level()->Get_room_by_id(startRoomId);

	// Looking throu all the near rooms
	// (in order LEFT - DOWN - RIGHT - TOP)

	// Going to the left room
	if (currRoom->getRoomByDirection(LEFT) != nullptr)
	{
		this->m_move_directions.push_back(LEFT);

		if (find_the_route(currRoom->getRoomByDirection(LEFT)->getID(), endRoomId, _visitedRooms))
		{
			return true;
		}

		this->m_move_directions.pop_back();
	}	

	// Going to the down room
	if (currRoom->getRoomByDirection(DOWN) != nullptr)
	{
		this->m_move_directions.push_back(DOWN);

		if (find_the_route(currRoom->getRoomByDirection(DOWN)->getID(), endRoomId, _visitedRooms))
		{
			return true;
		}

		this->m_move_directions.pop_back();
	}
	
	// Going to the right room
	if (currRoom->getRoomByDirection(RIGHT) != nullptr)
	{
		this->m_move_directions.push_back(RIGHT);

		if (find_the_route(currRoom->getRoomByDirection(RIGHT)->getID(), endRoomId, _visitedRooms))
		{
			return true;
		}

		this->m_move_directions.pop_back();
	}
	
	// Going to the top room
	if (currRoom->getRoomByDirection(TOP) != nullptr)
	{
		this->m_move_directions.push_back(TOP);

		if (find_the_route(currRoom->getRoomByDirection(TOP)->getID(), endRoomId, _visitedRooms))
		{
			return true;
		}

		this->m_move_directions.pop_back();
	}

	_visitedRooms[startRoomId] = false;
	return false;*/
}

