#include "Animated_Object.h"
#include "Animation_loader.h"


Animated_Object::Animated_Object(unsigned int fps, unsigned int frames_array)
	:Object(ANIMATED), m_fps(fps), m_frames_array_index(frames_array), m_curr_frame_index(0) ,m_all_time(0)
{
	m_pos = sf::Vector2f(0, 0);
	Animation_loader* loader = Animation_loader::Get();
	m_animation_time = 1.0 / m_fps * 1000000 * loader->getNumberOfSprites(m_frames_array_index);
}


Animated_Object::~Animated_Object()
{

}

void Animated_Object::setPosition(float _x, float _y)
{
	m_pos.x = _x;
	m_pos.y = _y;
}
void Animated_Object::animate(unsigned int time)
{
	Animation_loader* loader = Animation_loader::Get();
	int count_frames = loader->getNumberOfSprites(m_frames_array_index);
	int time_frame = m_animation_time / count_frames;
/*
	m_all_time += time;

	int frame_we_need_id = m_all_time / time_frame;

	m_sprite = loader->getSprite(m_frames_array_index, frame_we_need_id);*/
	
	m_all_time += time;
	m_all_time %= count_frames*time_frame;
	m_sprite = Animation_loader::Get()->getSprite(m_frames_array_index, (unsigned int)(((float)m_all_time) / ((float)m_animation_time)*count_frames));
	m_sprite.setPosition(m_pos);
	//m_sprite = Animation_loader::Get()->getSprite(m_frames_array_index, 0);

}

void Animated_Object::display(sf::RenderWindow *window)
{
	window->draw(m_sprite);
}