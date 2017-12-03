#include "Room_Dog.h"
#include "Player.h"
#include "Inventory.h"
#include "Render.h"
#include "Menu.h"

Room_Dog::Room_Dog(Room_t type, unsigned int id, sf::IntRect rect, unsigned int timeOfBarking)
	: Room(type, id, rect)
{
	this->m_timeOfBarking = timeOfBarking;
	this->m_currentState = PASSIVE;
	this->m_passedTime = 0;

	this->m_dogPassive = new Animated_Object(25, 7);
	this->m_dogActive = new Animated_Object_Hovered(25, 5, 5);
	this->m_dogFinished = new Animated_Object(25, 6);
}


Room_Dog::~Room_Dog()
{
	delete this->m_dogPassive;
	delete this->m_dogActive;
	delete this->m_dogFinished;
}


void Room_Dog::setDogPosition(float _x, float _y)
{
	this->m_dogActive->setPosition(_x, _y);
	this->m_dogPassive->setPosition(_x, _y);
	this->m_dogFinished->setPosition(_x, _y);
}


void Room_Dog::display(sf::RenderWindow *window, unsigned int time)
{
	// Changing the state, if necessary
	// Checking if player is in room
	if (this->m_currentState != FINISHED)
	{
		Item_t _bone;
		_bone._type = BONE;

		if (this->m_currentState == PASSIVE && Player::Get()->Get_c_room() == this->m_id)
		{
			this->m_currentState = ACTIVE;
		}
		else if (this->m_currentState == ACTIVE && Player::Get()->Get_c_room() != this->m_id)
		{
			this->m_currentState = PASSIVE;
		}
		// If throwing the bone
		else if (Player::Get()->Get_clicked())
		{
			// Checking that click was on the dog
			if (this->m_currentState == ACTIVE && Inventory::Get()->checkElement(_bone) &&
				this->m_dogActive->Get_sprite().getGlobalBounds().contains((sf::Vector2f) Player::Get()->Get_c_pos()))
			{
				this->m_currentState = FINISHED;

				// Removing the bone from inventory
				Inventory::Get()->del_item(_bone);
			}			
		}
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
		if (Render::Get()->Get_c_level()->Get_status() == LEVEL_STATUS_GAME)
		{
			this->m_passedTime += time;
		}
		
		// If it is time to finish the game
		if (this->m_passedTime >= this->m_timeOfBarking)
		{
			Render::Get()->Set_level_status(LEVEL_STATUS_FAILED);
			Render::Get()->setStatus(RENDER_STATUS_MENU);
			Menu::Get()->fillVectorButtons(LEVEL_FAILED);
		}
		
		this->m_dogActive->animate(time);
		this->m_dogActive->display(window);
	}
	case FINISHED:
	{
		this->m_dogFinished->animate(time);
		this->m_dogFinished->display(window);
	}
	}

	// Displaying other objects
	Room::display(window, time);
}