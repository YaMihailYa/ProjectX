#include "Static_Object_Hovered.h"
#include "Texture_loader.h"

Static_Object_Hovered::Static_Object_Hovered(int id_main, int id_hovered)
	: Static_Object(id_main)
{
	Texture_loader *texture_loader = Texture_loader::Get();

	sf::Texture *texture = texture_loader->Get_texture(id_hovered);

	this->m_sprite_hovered = sf::Sprite();
	this->m_sprite_hovered.setTexture(*texture);

	// By default displays unhovered sprite
	this->m_isHovered = false;
}


Static_Object_Hovered::~Static_Object_Hovered()
{

}


void Static_Object_Hovered::setIsHovered(bool _isHovered)
{
	this->m_isHovered = _isHovered;
}


bool Static_Object_Hovered::getIsHovered()
{
	return this->m_isHovered;
}


void Static_Object_Hovered::display(sf::RenderWindow *window)
{
	if (this->m_isHovered)
	{
		window->draw(this->m_sprite);
	}
	else
	{
		window->draw(this->m_sprite_hovered);
	}
}