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
	Static_Object* obj;
};

class Inventory
{
public:
	Inventory(sf::IntRect rect);
	~Inventory();

	//void add_item(Item_t);
	//void display(sf::RenderWindow *window);
	

protected:
	std::vector<Inventory_item_t> m_items;

	sf::IntRect m_rect;
};

