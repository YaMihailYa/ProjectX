#include "Inventory.h"
#include "Render.h"

Inventory *Inventory::m_this = nullptr;

Inventory::Inventory(sf::IntRect rect)
	:m_rect(rect)
{
	if (m_this != nullptr)
		exit(EXIT_FAILURE);

	m_this = this;
	/*begin_draw_pos.x = rect.height / 3;
	begin_draw_pos.y = rect.width / 5;*/
	begin_draw_pos.x = rect.left;
	begin_draw_pos.y = rect.top;

	// Multiplying on the coefs
	sf::Vector2f coef = Render::Get()->Get_coef();
	m_rect.width *= coef.x;
	m_rect.left *= coef.x;
	m_rect.height *= coef.y;
	m_rect.top *= coef.y;
}

Inventory::~Inventory()
{
	if (m_items.empty())
		for (int i = 0; i < m_items.size(); i++)
		{
			delete m_items[i].obj;
			m_items.erase(m_items.begin() + (i - 1));
		}
	m_this = nullptr;
}

void Inventory::add_item(Item_t &item)
{
	int obj_id;
	switch (item._type)
	{
	case COOKIE:
		obj_id = 55;
		break;
	case BONE:
		obj_id = 54;
		break;
	case KEY:
		switch (item._colour)
		{
		case YELLOW:
			obj_id = 62;
			break;
		case GREEN:
			obj_id = 58;
			break;
		case BLUE:
			obj_id = 57;
			break;
		case RED:
			obj_id = 61;
			break;
		case PINK:
			obj_id = 60;
			break;
		case ORANGE:
			obj_id = 59;
			break;
		default:
			break;
		}
		break;
	case WRENCH:
		obj_id = 56;
		break;
	default:
		break;
	}
	
	Static_Object *obj = new Static_Object(obj_id);
	obj->setPosition(begin_draw_pos.x + ITEM_PADDING * m_items.size(), begin_draw_pos.y);
	m_items.push_back(Inventory_item_t(item, obj));
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
			m_items.erase(m_items.begin() + (i));
		}
	for (int i = 0; i < m_items.size(); i++)
		m_items[i].obj->setPosition(begin_draw_pos.x + ITEM_PADDING * m_items.size(), begin_draw_pos.y);
	return;
}

void Inventory::display(sf::RenderWindow *window)
{
	for (int i = 0; i < m_items.size(); i++)
		m_items[i].obj->display(window);
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

	for (int i = 0; i< m_items.size(); i++)
	{
		if (m_items[i].type._type == COOKIE)
		{
			func_number++;
		}
	}

	return func_number;
}