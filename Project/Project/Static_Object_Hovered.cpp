#include "Static_Object_Hovered.h"
#include "Texture_loader.h"
#include "Player.h"
#include "Render.h"

Static_Object_Hovered::Static_Object_Hovered(int id_main, int id_hovered)
	: Static_Object(id_main)
{
	m_type = HOVERED;
	Texture_loader *texture_loader = Texture_loader::Get();

	sf::Texture *texture = texture_loader->Get_texture(id_hovered);

	this->m_sprite_hovered = sf::Sprite();
	this->m_sprite_hovered.setTexture(*texture);
	this->m_sprite_hovered.setScale(Render::Get()->Get_coef());

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


void Static_Object_Hovered::setPosition(float _x, float _y)
{
	Object::setPosition(_x, _y);

	sf::Vector2f coef = Render::Get()->Get_coef();
	this->m_sprite_hovered.setPosition((_x - 3)*coef.x, (_y - 3)*coef.y);
}


void Static_Object_Hovered::checkHovered()
{
	// Getting the rectangle of this object
	sf::FloatRect thisSpriteBoundary = this->m_sprite.getGlobalBounds();

	// Checking if the mouse is on this object
	if (thisSpriteBoundary.contains((sf::Vector2f) sf::Mouse::getPosition()))
	{
		this->m_isHovered = true;
	}
	else
	{
		this->m_isHovered = false;
	}
}


void Static_Object_Hovered::display(sf::RenderWindow *window)
{
	this->checkHovered();

	//this->checkClickOnThis();

	if (this->m_isHovered)
	{
		window->draw(this->m_sprite_hovered);
	}
	else
	{
		window->draw(this->m_sprite);
	}
}