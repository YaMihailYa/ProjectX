#include "Static_Object_Storage.h"
#include "Inventory.h"

Static_Object_Storage::Static_Object_Storage(int id_main, int id_hovered, std::vector<Item_t> _items)
	: Static_Object_Hovered(id_main, id_hovered)
{
	this->m_items = _items;
}


Static_Object_Storage::~Static_Object_Storage()
{

}


void Static_Object_Storage::setItems(std::vector<Item_t> _items)
{
	this->m_items = _items;
}


std::vector<Item_t> Static_Object_Storage::getItems()
{
	return this->m_items;
}


void Static_Object_Storage::clearItems()
{
	this->m_items.clear();
}


void Static_Object_Storage::checkClickOnThis()
{
	if (/* ... */  false)
	{
		Inventory *inventory = Inventory::Get();

		// Adding all the items to the inventory
		for (int i = 0; i < this->m_items.size(); i++)
		{
			inventory->add_item(m_items[i]);
		}

		this->m_items.clear();
	}
}