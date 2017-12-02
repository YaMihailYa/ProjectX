#pragma once
#include "Static_Object_Hovered.h"
#include "globals.h"

/**
*
*	Objects that can store items (sofa, nightstand, ect.)
*
*/

class Static_Object_Storage
	: public Static_Object_Hovered
{
public:
	Static_Object_Storage(int id_main, int id_hovered, std::vector<Item_t> _items);
	~Static_Object_Storage();

	void setItems(std::vector<Item_t> _items);
	std::vector<Item_t> getItems();

	// Deleting all the items
	void clearItems();


protected:
	std::vector<Item_t> m_items;

	// Check if clicked on this
	void checkClickOnThis();
};