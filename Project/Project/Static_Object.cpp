#include "Static_Object.h"
#include "Texture_loader.h"



Static_Object::Static_Object(int id)
	:Object(STATIC)
{
	Texture_loader *texture_loader = Texture_loader::Get();

	sf::Texture *texture = texture_loader->Get_texture(id);

	this->m_sprite = sf::Sprite();
	this->m_sprite.setTexture(*texture);
}


Static_Object::~Static_Object()
{
}

void Static_Object::display(sf::RenderWindow *window)
{
	// Drawing the sprite
	window->draw(this->m_sprite);
}
