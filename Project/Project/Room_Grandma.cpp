#include "Room_Grandma.h"
#include "Player.h"
#include "Render.h"

Room_Grandma::Room_Grandma(Room_t type, unsigned int id, sf::IntRect rect, unsigned int timeOfPhase)
	: Room(type, id, rect)
{
	this->m_timeOfPhase = timeOfPhase;
	this->m_isActive = true;
	this->m_passedTime = 0;

	this->m_grandmaActive = new Animated_Object(25, 3);
	this->m_grandmaPassive = new Animated_Object(25, 4);
}


Room_Grandma::~Room_Grandma()
{
	delete this->m_grandmaActive;
	delete this->m_grandmaPassive;
}


void Room_Grandma::setGrandmaPosition(float _x, float _y)
{
	this->m_grandmaActive->setPosition(_x, _y + 47);
	this->m_grandmaPassive->setPosition(_x, _y);
}


void Room_Grandma::display(sf::RenderWindow *window, unsigned int time)
{
	if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME)
	{
		this->m_passedTime += time;
	}
	
	// If it is time to change the phase
	if (this->m_passedTime >= this->m_timeOfPhase)
	{
		this->m_isActive = !this->m_isActive;
		this->m_passedTime -= this->m_timeOfPhase;
	}

	// Displaying the grandma
	if (this->m_isActive)
	{
		this->m_grandmaActive->animate(time);
		this->m_grandmaActive->display(window);
	}
	else
	{
		this->m_grandmaPassive->animate(time);
		this->m_grandmaPassive->display(window);
	}

	// If player is in room during the active phase - game over
	if (Player::Get()->Get_c_room() == this->m_id && this->m_isActive)
	{
		Render::Get()->Set_level_status(LEVEL_STATUS_FAILED);
	}

	// Displaying other objects
	Room::display(window, time);
}