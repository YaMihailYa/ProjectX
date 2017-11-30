#include "Player.h"


Player* Player::m_this = nullptr;

Player::Player(unsigned int speed)
	:m_speed(speed), m_c_pos(sf::Vector2u(100, 100))
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);
	m_this = this;

	// m_rect = 
}


Player::~Player()
{
	m_this = nullptr;
}


void Player::display(sf::RenderWindow *window, unsigned int time)
{
	sf::IntRect old_rect, new_rect;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		
		m_left_anim->animate(time);
		old_rect = sf::IntRect(m_left_anim->Get_sprite().getGlobalBounds());
		new_rect = old_rect;
		new_rect.left += time*m_speed;
		//new_rect = 
		m_left_anim->display(window);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_right_anim->animate(time);
		m_right_anim->display(window);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		m_stay_anim->animate(time);
		m_stay_anim->display(window);
	}
}

void Player::Move(Direction_t dir, unsigned int time)
{
	
}

