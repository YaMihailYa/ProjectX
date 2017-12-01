#pragma once
#include "Object.h"
class Animated_Object :
	public Object
{
public:
	Animated_Object(unsigned int fps, unsigned int frames_array);
	~Animated_Object();

	void display(sf::RenderWindow *window);
	/**
	* Animate sprite
	* @param time - time passed from last call of this function in MICROSECONDS
	*/
	void animate(unsigned int time);

protected:
	unsigned int m_all_time; // Time from begin of animation in MICROSECONDS
	unsigned int m_fps; // Frames per SECONDS
	unsigned int m_frames_array_index;
	unsigned int m_curr_frame_index;
	unsigned int m_animation_time;
};

