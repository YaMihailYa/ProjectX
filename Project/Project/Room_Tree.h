#pragma once
#include "Room.h"

class Room_Tree
	: public Room
{
public:
	Room_Tree(Room_t type, unsigned int id, sf::IntRect rect);
	~Room_Tree();

	void setTreePosition(float _x, float _y);

	void display(sf::RenderWindow *window, unsigned int time);

protected:
	Static_Object_Hovered *m_tree;

	// When clicked on the tree
	void checkClicked();
};