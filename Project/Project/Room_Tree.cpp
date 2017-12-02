#include "Room_Tree.h"
#include "Render.h"

Room_Tree::Room_Tree(Room_t type, unsigned int id, sf::IntRect rect, bool enterable)
	: Room(type, id, rect, enterable)
{
	this->m_tree = new Static_Object_Hovered(0, 0);
}


Room_Tree::~Room_Tree()
{

}


void Room_Tree::setTreePosition(float _x, float _y)
{
	this->m_tree->setPosition(_x, _y);
}


void Room_Tree::display(sf::RenderWindow *window, unsigned int time)
{
	this->checkClicked();

	this->m_tree->display(window);

	Room::display(window, time);
}


void Room_Tree::checkClicked()
{
	if (/* ... */ false)
	{
		Render::Get()->Set_level_status(LEVEL_FAILED);
	}
}