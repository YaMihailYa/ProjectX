#pragma once
#include "Object.h"

class Static_Object :
	public Object
{
public:
	Static_Object(int id);
	virtual ~Static_Object();
	
	// Display sprite
	void display(sf::RenderWindow *window);
};

