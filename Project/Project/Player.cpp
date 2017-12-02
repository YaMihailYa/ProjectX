#include "Player.h"
#include "Render.h"


Player* Player::m_this = nullptr;

Player::Player(unsigned int speed)
	:m_speed(speed), m_c_pos(sf::Vector2u(100, 100))
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


	}

	sf::Vector2u new_coords;
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
	}
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

