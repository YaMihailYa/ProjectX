#pragma once
#include "Room.h"

class Room_Grandma
	: public Room
{
public:
	Room_Grandma(Room_t type, unsigned int id, sf::IntRect rect, bool enterable, unsigned int timeOfPhase);
	~Room_Grandma();

	void setGrandmaPosition(float _x, float _y);

	void display(sf::RenderWindow *window, unsigned int time);

protected:
	Animated_Object *m_grandmaActive;
	Animated_Object *m_grandmaPassive;

	// Current state of grandma (true if active)
	bool m_isActive;

	// Time of one phase
	unsigned int m_timeOfPhase;

	// Time that current phase is going on
	unsigned int m_passedTime;

};