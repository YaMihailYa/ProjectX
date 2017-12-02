	#pragma once
#include "Static_Object.h"

/**
*
*	Objects that are hovered when the mouse is on it
*
*/

class Static_Object_Hovered :
	public Static_Object
{
public:
	Static_Object_Hovered(int id_main, int id_hovered);
	~Static_Object_Hovered();

	void setIsHovered(bool _isHovered);
	bool getIsHovered();

	void setPosition(float _x, float _y);

	// Display sprite
	void display(sf::RenderWindow *window);


protected:
	sf::Sprite m_sprite_hovered;			// Same sprite with yellow outline

	bool m_isHovered;						// True if outline is needed (Player is nearly)

	// Checking if door is need to be hovered (when mouse is on it)
	void checkHovered();

};
