#include "Room_Tree.h"
#include "Render.h"
#include "Player.h"
#include "Menu.h"
#include "Inventory.h"

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
			Render::Get()->Set_level_status(LEVEL_STATUS_END);

			//TODO
			//Download in file

			int rate = Inventory::Get()->number_of_cookies();
			int level_id = Render::Get()->Get_c_level()->Get_level_id();
			//Menu::Get()->fillVectorButtons();
			
			int count_cookies[3];

			std::ifstream myfile1("achievements.txt");
			if (myfile1.is_open())
			{
				myfile1 >> count_cookies[0];
				myfile1 >> count_cookies[1];
				myfile1 >> count_cookies[2];

				count_cookies[level_id - 1] = rate;

				myfile1.close();
			}
		
			std::ofstream myfile2("achievements.txt", std::ios::out);
			if (myfile2.is_open())
			{
				myfile2 << count_cookies[0];
				myfile2 << count_cookies[1];
				myfile2 << count_cookies[2];

				myfile2.close();
			}

			if (rate == 3) { Menu::Get()->fillVectorButtons(LOOT_BOX); }
			else { Menu::Get()->fillVectorButtons(LEVEL_END, rate); }
			
			Render::Get()->setStatus(Render_status_t::RENDER_STATUS_MENU);
		}
	}
}