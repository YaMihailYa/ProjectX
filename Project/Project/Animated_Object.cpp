#include "Animated_Object.h"
#include "Animation_loader.h"


Animated_Object::Animated_Object(unsigned int fps, unsigned int frames_array)
	:Object(ANIMATED), m_fps(fps), m_frames_array_index(frames_array), m_curr_frame_index(0) ,m_all_time(0)
{
	Animation_loader* loader = Animation_loader::Get();
	m_animation_time = 1.0 / m_fps * 1000000 * loader->getNumberOfSprites(m_frames_array_index);
}


Animated_Object::~Animated_Object()
{

}


void Animated_Object::animate(unsigned int time)
{
	Animation_loader* loader = Animation_loader::Get();
	int count_frames = loader->getNumberOfSprites(m_frames_array_index);
	int time_frame = m_animation_time / count_frames;

	m_all_time += time;

	int frame_we_need_id = m_all_time / time_frame;

	m_sprite = loader->getSprite(m_frames_array_index, frame_we_need_id);
}

void Animated_Object::display(sf::RenderWindow *window)
{
	window->draw(m_sprite);
}