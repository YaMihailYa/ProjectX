#pragma once
class Render
{
public:
	Render();
	~Render();

	// Start displaying objects
	void Rendering();

	
private:
	void Init();

	sf::RenderWindow *m_window;
	float m_coef_x;
	float m_coef_y;
};

