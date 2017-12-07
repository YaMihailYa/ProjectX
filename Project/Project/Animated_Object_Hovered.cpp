#include "Animated_Object_Hovered.h"
#include "Animation_loader.h"
#include "Player.h"

Animated_Object_Hovered::Animated_Object_Hovered(unsigned int fps, unsigned int frames_array, unsigned int frames_array_hovered)
	: Animated_Object(fps, frames_array)
{
	this->m_frames_array_hovered_index = frames_array_hovered;
	this->m_isHovered = false;
}


Animated_Object_Hovered::~Animated_Object_Hovered()
{

}


void Animated_Object_Hovered::setIsHovered(bool _isHovered)
{
	this->m_isHovered = _isHovered;
}


bool Animated_Object_Hovered::getIsHovered()
{
	return this->m_isHovered;
}


void Animated_Object_Hovered::checkHovered()
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


void Animated_Object_Hovered::animate(unsigned int time)
{
	this->checkHovered();

	int currArrayIndex = this->m_isHovered ? m_frames_array_hovered_index : m_frames_array_index;

	Animation_loader* loader = Animation_loader::Get();
	int count_frames = loader->getNumberOfSprites(currArrayIndex);
	int time_frame = m_animation_time / count_frames;

	m_all_time += time;
	m_all_time %= count_frames *time_frame;

	unsigned int frame_we_need_id = (unsigned int)(((float)m_all_time) / ((float)m_animation_time)*count_frames);

	m_sprite = loader->getSprite(currArrayIndex, frame_we_need_id);
	m_sprite.setPosition(m_pos);
}