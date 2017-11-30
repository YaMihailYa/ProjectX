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

	// Setting the position of object
	void setPosition(float _x, float _y);

	// Display sprite
	virtual void display(sf::RenderWindow *window) = 0;

	sf::Sprite Get_sprite() const { return m_sprite; }

protected:
	sf::Sprite m_sprite;
	const Object_t m_type;
};

