#include "Room_Dog.h"
#include "Player.h"

Room_Dog::Room_Dog(Room_t type, unsigned int id, sf::IntRect rect, bool enterable, unsigned int timeOfBarking)
	: Room(type, id, rect, enterable)
{
	this->m_timeOfBarking = timeOfBarking;
	this->m_currentState = PASSIVE;
	this->m_passedTime = 0;

	this->m_dogPassive = new Animated_Object(25, 0);
	this->m_dogActive = new Animated_Object_Hovered(25, 0, 0);
	this->m_dogFinished = new Animated_Object(25, 0);
}


Room_Dog::~Room_Dog()
{
	delete this->m_dogPassive;
	delete this->m_dogActive;
	delete this->m_dogFinished;
}


void Room_Dog::display(sf::RenderWindow *window, unsigned int time)
{
	// Changing the state, if necessary
	// Checking if player is in room
	if (this->m_currentState != FINISHED)
	{
		if (this->m_currentState == PASSIVE && Player::Get()->Get_c_room() == this->m_id)
		{
			this->m_currentState = ACTIVE;
		}
		else if (this->m_currentState == ACTIVE && Player::Get()->Get_c_room() != this->m_id)
		{
			this->m_currentState = PASSIVE;
		}
		// If throwing the bone
		/*else if (this->m_currentState == ACTIVE && this->m_dogActive->getIsHovered() &&
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			this->m_currentState = FINISHED;

			// Removing the bone from inventory

		}*/
	}

	switch (this->m_currentState)
	{
	case PASSIVE:
	{
		this->m_dogPassive->animate(time);
		this->m_dogPassive->display(window);
	}
	case ACTIVE:
	{
		this->m_passedTime += time;
		
		// If it is time to finish the game
		if (this->m_passedTime >= this->m_timeOfBarking)
		{
			// ...
		}
		
		this->m_dogActive->animate(time);
		this->m_dogActive->display(window);
	}
	case FINISHED:
	{
		this->m_dogFinished->animate(time);
		this->m_dogFinished->display(window);
	}

	// Displaying other objects
	Room::display(window, time);
	}
}