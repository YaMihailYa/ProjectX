#pragma once

enum Object_t
{
	STATIC,
	ANIMATED
};

class Object
{
public:
	Object(Object_t type);
	~Object();

	// Display sprite
	virtual void display(sf::RenderWindow *window) = 0;

protected:
	sf::Sprite m_sprite;
	const Object_t m_type;
};

