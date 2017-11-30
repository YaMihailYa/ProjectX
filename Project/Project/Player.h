#pragma once
#include "globals.h"
#include "Animated_Object.h"

class Player
{
public:
	Player(unsigned int speed);
	~Player();

	/**
	* Move player
	* @param dir direction
	* @param time time from last call of function 
	*/
	void Move(Direction_t dir, unsigned int time);

	void display(sf::RenderWindow *window, unsigned int time);

	static Player* Get() { return m_this; }

	void Set_c_room(unsigned int id) { m_c_room_id = id; }
	unsigned int Get_c_room() const { return m_c_room_id; }
	
	sf::IntRect Get_boundary() const { return m_rect; }
protected:
	static Player* m_this;

	//sf::Sprite m_sprite;
	Animated_Object *m_left_anim;
	Animated_Object *m_right_anim;
	Animated_Object *m_stay_anim;
	sf::Vector2u m_c_pos;
	sf::IntRect m_rect;
	unsigned int m_speed; // pixels per MICROSECONDS

	// ID of current room
	unsigned int m_c_room_id;
};

