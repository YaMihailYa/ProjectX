#include "Player.h"


Player* Player::m_this = nullptr;

Player::Player()
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);

	m_this = this;
}


Player::~Player()
{
	m_this = nullptr;
}
