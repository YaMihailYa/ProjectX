#pragma once
#include "Level.h"

class Render
{
public:
	Render();
	~Render();

	// Start displaying objects
	void Rendering();

	static Render* Get() { return m_this;  }
	Level* Get_c_level() const { return m_c_level; }

	sf::Vector2f Get_coef() const { return sf::Vector2f(m_coef_x, m_coef_y); }
private:
	void Init();

	static Render* m_this;
	Level* m_c_level;

	sf::RenderWindow *m_window;
	float m_coef_x;
	float m_coef_y;
};

