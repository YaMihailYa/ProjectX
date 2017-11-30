#pragma once
#include "Room.h"
class Room_regular :
	public Room
{
public:
	Room_regular(unsigned int id, sf::IntRect rect, bool enterable);
	~Room_regular();
};

