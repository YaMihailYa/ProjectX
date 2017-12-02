#pragma once
#include "globals.h"
#include "Static_Object.h"

// Id of items for stati_object's:
// 0 - печеньки
// 1 - ...
// Сам придумаешь

// Отступы между элементами инвентаря в пикселях:
#define ITEM_PADDING 10

struct Inventory_item_t
{
	Item_t type;
	Static_Object *obj;
	Inventory_item_t::Inventory_item_t() { }
	Inventory_item_t::Inventory_item_t(Item_t &_type, Static_Object &_obj)
	{
		type = _type;
		obj = &_obj;
	}
};

class Inventory
{
private:
	sf::Vector2<float> begin_draw_pos;
	

public:
	Inventory(sf::IntRect rect);
	~Inventory();

	
	void add_item(Item_t&);
	bool change_item(Item_t&);
	void del_item(Item_t &item);
	void display(sf::RenderWindow &window);

	bool checkElement(Item_t &item);
	
	int number_of_cookies();

	static Inventory* Get() { return m_this; }

protected:
	static Inventory *m_this;
	std::vector<Inventory_item_t> m_items;
	sf::IntRect m_rect;
};

