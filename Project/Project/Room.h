#pragma once
#include "globals.h"
#include "Door.h"
#include "Animated_Object.h"

enum Room_t
{
	REGULAR,
	GRANDMA,
	DOG,
	TREE
};

class Room
{
public:
	Room(Room_t type, unsigned int id, sf::IntRect rect);
	~Room();

	/**
	* Move player
	* @param old_coords old coordinates of player
	* @param new_coords new coordinates of player
	* @param dir directions in which player was moved
	* @return new coorcdinates of player
	*/
	//sf::Vector2u move_player(sf::Vector2u old_coords, sf::Vector2u new_coords, Direction_t dir);

	unsigned int getID() const { return this->m_id; }

	void setStaticObjects(std::vector<Static_Object_Hovered*> _staticObjects);
	void setAnimatedObjects(std::vector<Animated_Object*> _animatedObjects);

	float getCoordByDirection(Direction_t direction);

	void Set_right_room(Room *right_room) { m_right_room = right_room; }
	void Set_left_room(Room *left_room) { m_left_room = left_room; }
	void Set_top_room(Room *top_room) { m_top_room = top_room; }
	void Set_down_room(Room *down_room) { m_down_room = down_room; }

	Room* getRoomByDirection(Direction_t direction);
	
	void Set_right_door(Door *right_door) { m_right_door = right_door; }
	void Set_left_door(Door *left_door) { m_left_door = left_door; }
	void Set_top_door(Door *top_door) { m_top_door = top_door; }
	void Set_down_door(Door *down_door) { m_down_door = down_door; }

	Door* getDoorByDirection(Direction_t direction);

	void Set_rect(sf::IntRect rect) { m_rect = rect; }
	sf::IntRect Get_rect() const { return m_rect; }

	sf::IntRect getRectOfRoom() { return this->m_rect; }

	void display(sf::RenderWindow *window, unsigned int time);


protected:
	//void Entered();

	unsigned int m_id;
	Room_t m_type;

	// Rectangle of room
	sf::IntRect m_rect;

	// Arrays of static objects of the room (hovered only)
	std::vector<Static_Object_Hovered*> m_staticObjects;

	// Arrays of animated objects of the room (hovered only)
	std::vector<Animated_Object*> m_animatedObjects;

	Room *m_right_room;
	Room *m_left_room;
	Room *m_top_room;
	Room *m_down_room;

	Door *m_right_door;
	Door *m_left_door;
	Door *m_top_door;
	Door *m_down_door;

};

