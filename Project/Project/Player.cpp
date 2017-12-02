#include "Player.h"
#include "Render.h"


Player* Player::m_this = nullptr;

Player::Player(unsigned int speed)
	: m_c_pos(sf::Vector2u(100, 100)), m_status(ANIMATION_STAY)
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);
	m_this = this;

	sf::IntRect s;
	// m_rect = 
	this->m_clicked = false;

	this->m_speed = speed * Render::Get()->Get_coef().x;
}


Player::~Player()
{
	m_this = nullptr;
}


void Player::display(sf::RenderWindow *window, unsigned int time)
{
	this->m_clicked = false;

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
		if (this->m_c_pos == this->m_target_pos)
		{
			this->m_clicked = true;
			this->m_status = ANIMATION_STAY;
		}
		else
		{
			this->move_to_x_coord(this->m_target_pos.x, time);
		}		
	}

	// Displaying the player
	switch (m_status)
	{
	case ANIMATION_STAY:
		m_stay_anim->animate(time);
		m_stay_anim->setPosition(m_c_pos.x, m_c_pos.y);
		m_stay_anim->display(window);
		break;
	case ANIMATION_LEFT:
		m_left_anim->animate(time);
		m_left_anim->setPosition(m_c_pos.x, m_c_pos.y);
		m_left_anim->display(window);
		break;
	case ANIMATION_RIGHT:
		m_right_anim->animate(time);
		m_right_anim->setPosition(m_c_pos.x, m_c_pos.y);
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

void Player::Move(/*Direction_t dir, unsigned int time*/)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2u tagretPosCopy = m_target_pos;

		m_target_pos = sf::Vector2u(sf::Mouse::getPosition());
		m_move_directions.clear();

		// Finding the id of target room
		int targetRoomId = -1;

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
			find_the_route(this->m_c_room_id, targetRoomId, visitedRooms);
		}
		else
		{
			m_target_pos = tagretPosCopy;
		}
	}
}


void Player::move_to_x_coord(float _xCoord, unsigned int _time)
{
	if (this->m_c_pos.x < _xCoord)
	{
		// Moving right
		this->m_status = ANIMATION_RIGHT;

		this->m_c_pos.x += _time * this->m_speed;

		// Checking if went through the border
		if (this->m_c_pos.x > _xCoord)
		{
			this->m_c_pos.x = _xCoord;
		}
	}
	else
	{
		// Moving left
		this->m_status = ANIMATION_LEFT;

		this->m_c_pos.x -= _time * this->m_speed;

		// Checking if went through the border
		if (this->m_c_pos.x < _xCoord)
		{
			this->m_c_pos.x = _xCoord;
		}
	}
}


bool Player::find_the_route(unsigned int startRoomId, unsigned int endRoomId, std::vector<bool> &_visitedRooms)
{
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
	return false;
}

