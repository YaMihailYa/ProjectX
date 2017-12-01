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
private:
	void Init();

	static Render* m_this;
	Level* m_c_level;

	sf::RenderWindow *m_window;
	float m_coef_x;
	float m_coef_y;
};

