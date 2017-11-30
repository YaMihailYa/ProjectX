#include "Animated_Object.h"



Animated_Object::Animated_Object(unsigned int fps, unsigned int frames_array)
	:Object(ANIMATED), m_fps(fps), m_frames_array(frames_array)
{
}


Animated_Object::~Animated_Object()
{
}


void Animated_Object::animate(unsigned int time)
{

}

void Animated_Object::display(sf::RenderWindow *window)
{
	window->draw(m_sprite);
}