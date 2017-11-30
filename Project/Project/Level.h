#pragma once
#include "Room.h"
/**
*	Base class for all levels
*	
*/

class Level
{
public:
	Level(unsigned int id);
	~Level();

	// Display all objects of current level
	virtual void Display(sf::RenderWindow *window) = 0;

protected:
	std::vector<Room*> m_rooms;
	const unsigned int m_id;
};