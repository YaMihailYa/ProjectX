#pragma once
#include "Static_Object.h"

class Static_Object_Hovered :
	public Static_Object
{
public:
	Static_Object_Hovered(int id_main, int id_hovered);
	~Static_Object_Hovered();

	void setIsHovered(bool _isHovered);
	bool getIsHovered();

	// Display sprite
	void display(sf::RenderWindow *window);
	void defHovered();


protected:
	sf::Sprite m_sprite_hovered;		// Same sprite with yellow outline

	bool m_isHovered;						// True if outline is needed (Player is nearly)

};
