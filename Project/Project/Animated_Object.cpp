#include "Animated_Object.h"
#include "Animation_loader.h"


Animated_Object::Animated_Object(unsigned int fps, unsigned int frames_array)
	:Object(ANIMATED), m_fps(fps), m_frames_array(frames_array), m_all_time(0)
{
}


Animated_Object::~Animated_Object()
{
}


void Animated_Object::animate(unsigned int time)
{
	/* 
	*	I don't know wtf is it doing....
	*	You'd to continue last raw
	*/


	Animation_loader* loader = Animation_loader::Get();

	m_all_time += time;
	m_all_time %= loader->getNumberOfSprites(m_frames_array) / m_fps * 1000000;
	
	m_sprite = loader->getSprite(m_frames_array, m_all_time);
}

void Animated_Object::display(sf::RenderWindow *window)
{
	window->draw(m_sprite);
}