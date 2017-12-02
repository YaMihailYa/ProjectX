#include "Room_Tree.h"
#include "Render.h"
#include "Player.h"

Room_Tree::Room_Tree(Room_t type, unsigned int id, sf::IntRect rect)
	: Room(type, id, rect)
{
	this->m_tree = new Static_Object_Hovered(72, 73);
}


Room_Tree::~Room_Tree()
{
	delete this->m_tree;
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
	if (Player::Get()->Get_clicked())
	{
		if (this->m_tree->Get_sprite().getGlobalBounds().contains((sf::Vector2f) Player::Get()->Get_c_pos()))
		{
			Render::Get()->Set_level_status(LEVEL_STATUS_FAILED);
		}
	}
}