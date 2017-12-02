#pragma once
#include "Animated_Object.h"

class Animated_Object_Hovered
	: public Animated_Object
{
public:
	Animated_Object_Hovered(unsigned int fps, unsigned int frames_array, unsigned int frames_array_hovered);
	~Animated_Object_Hovered();
	
	void setIsHovered(bool _isHovered);
	bool getIsHovered();

	void animate(unsigned int time);

protected:
	unsigned int m_frames_array_hovered_index;

	bool m_isHovered;						// True if outline is needed (Player is nearly)

	void checkHovered();					// Checking if door is need to be hovered
};