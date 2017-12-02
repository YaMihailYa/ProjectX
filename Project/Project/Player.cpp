#include "Player.h"
#include "Render.h"


Player* Player::m_this = nullptr;

Player::Player(unsigned int speed)
	:m_speed(speed), m_c_pos(sf::Vector2u(100, 100)), m_status(ANIMATION_STAY)
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);
	m_this = this;

	sf::IntRect s;
	// m_rect = 
}


Player::~Player()
{
	m_this = nullptr;
}


void Player::display(sf::RenderWindow *window, unsigned int time)
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
		m_target_pos = sf::Vector2u(sf::Mouse::getPosition());
		m_move_directions.clear();


	}
}


void Player::move_to_x_coord(float _xCoord, unsigned int _time)
{
	exit(EXIT_FAILURE);
}

