#pragma once
#include "Room.h"
#include "Animated_Object_Hovered.h"

enum Dog_State_t
{
	PASSIVE,
	ACTIVE,
	FINISHED
};

class Room_Dog
	: Room
{
public:
	Room_Dog(Room_t type, unsigned int id, sf::IntRect rect, unsigned int timeOfBarking);
	~Room_Dog();

	void setDogPosition(float _x, float _y);

	void display(sf::RenderWindow *window, unsigned int time);

protected:
	Animated_Object *m_dogPassive;
	Animated_Object_Hovered *m_dogActive;
	Animated_Object *m_dogFinished;

	// Current state of dog
	Dog_State_t m_currentState;
	
	// Time of active phase
	unsigned int m_timeOfBarking;

	// Time that was passed since entering the room
	unsigned int m_passedTime;

};