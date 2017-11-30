#pragma once
#include "globals.h"

class Player
{
public:
	Player();
	~Player();


	void Move(Direction_t dir, unsigned int time);

	static Player* Get() { return m_this; }

	void Set_c_room(unsigned int id) { m_c_room_id = id; }
	unsigned int Get_c_room() const { return m_c_room_id; }
protected:
	static Player* m_this;

	sf::Sprite m_sprite;

	// ID of current room
	unsigned int m_c_room_id;
};

