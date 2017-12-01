#include "Static_Object_Storage.h"

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