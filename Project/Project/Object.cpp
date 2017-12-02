#include "Object.h"
#include "Render.h"


Object::Object(Object_t type)
	:m_type(type)
{
}


Object::~Object()
{
}


void Object::setPosition(float _x, float _y)
{
	sf::Vector2f coef = Render::Get()->Get_coef();
	this->m_sprite.setPosition(_x*coef.x, _y*coef.y);
}
