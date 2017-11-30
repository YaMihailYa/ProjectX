#include "Object.h"



Object::Object(Object_t type)
	:m_type(type)
{
}


Object::~Object()
{
}


void Object::setPosition(float _x, float _y) {
	this->m_sprite.setPosition(_x, _y);
}
