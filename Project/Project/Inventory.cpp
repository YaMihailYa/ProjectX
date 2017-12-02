#include "Inventory.h"

Inventory *Inventory::m_this = nullptr;

Inventory::Inventory(sf::IntRect rect)
	:m_rect(rect)
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);

	m_this = this;
	m_rect = rect;
	begin_draw_pos.x = rect.height / 3;
	begin_draw_pos.y = rect.width / 5;
}

Inventory::~Inventory()
{
	if (m_items.empty())
		for (int i = 0; i < m_items.size(); i++)
		{
			delete m_items[i].obj;
			m_items.erase(m_items.begin() + (i - 1));
		}
}

void Inventory::add_item(Item_t &item)
{
	Static_Object *static_object = new Static_Object(item._type);
	
		static_object->setPosition(begin_draw_pos.x + ITEM_PADDING * m_items.size(), begin_draw_pos.y);
	m_items.push_back(Inventory_item_t(item, *static_object));
}

bool Inventory::change_item(Item_t & item)
{
	if (m_items.empty()) return false;
	for (int i = 0; i < m_items.size(); i++)
		if (m_items[i].type._type == item._type) return true;
	return false;
}

void Inventory::del_item(Item_t & item)
{
	if (m_items.empty()) return;
	for (int i = 0; i < m_items.size(); i++)
		if (m_items[i].type._type == item._type)
		{
			delete m_items[i].obj;
			m_items.erase(m_items.begin() + (i - 1));
		}
	return;
}

void Inventory::display(sf::RenderWindow &window)
{
	for (int i = 0; i < m_items.size(); i++)
		m_items[i].obj->display(&window);
}

bool Inventory::checkElement(Item_t &item)
{
	int arrSize = this->m_items.size();

	for (int i = 0; i < arrSize; i++)
	{
		if (this->m_items[i].type._type == item._type)
		{
			if (this->m_items[i].type._type == KEY)
			{
				if (this->m_items[i].type._colour == item._colour)
				{
					return true;
				}
			}
			else
			{
				return true;
			}
		}
	}

	return false;
}

int Inventory::number_of_cookies()
{
	int func_number = 0;

	for (int i = 0; m_items.size(); i++)
	{
		if (m_items[i].type._type == COOKIE)
		{
			func_number++;
		}
	}

	return func_number;
}