#pragma once
#include "globals.h"
#include "Animated_Object.h"

enum Player_Status_t
{
	ANIMATION_STAY,
	ANIMATION_LEFT,
	ANIMATION_RIGHT
};

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
	void Move(/*Direction_t dir, unsigned int time*/);




	void display(sf::RenderWindow *window, unsigned int time);

	static Player* Get() { return m_this; }

	void Set_pos(sf::Vector2f pos) { m_pos = pos; }
	void Set_c_pos(sf::Vector2f c_pos) { m_c_pos = c_pos; }
	void Set_c_room(unsigned int id) { m_c_room_id = id; }

	bool Get_clicked() const { return this->m_clicked; }
	sf::Vector2f Get_pos() const { return m_pos; }
	sf::Vector2f Get_c_pos() const { return m_c_pos; }
	unsigned int Get_c_room() const { return m_c_room_id; }
	
	sf::IntRect Get_boundary() const { return m_rect; }
protected:
	static Player* m_this;

	// Current status of player
	Player_Status_t m_status;

	//sf::Sprite m_sprite;
	Animated_Object *m_left_anim;
	Animated_Object *m_right_anim;
	Animated_Object *m_stay_anim;

	sf::Vector2f m_pos;
	sf::Vector2f m_c_pos;
	sf::Vector2f m_target_pos;

	std::vector<Direction_t> m_move_directions;

	sf::IntRect m_rect;
	unsigned int m_speed; // pixels per SECONDS

	// When player comes to the point of mouse click
	bool m_clicked;

	// ID of current room
	unsigned int m_c_room_id;

	// Move to the x coordinate of the room
	void move_to_x_coord(float _xCoord, unsigned int _time);

	// Finding the route of player (using DFS)
	// And filling the array of move directions (bool if found)
	bool find_the_route(unsigned int startRoomId, unsigned int endRoomId, std::vector<bool> &visitedRooms);
};

