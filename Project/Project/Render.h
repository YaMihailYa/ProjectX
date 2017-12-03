#pragma once
#include "Texture_loader.h"
#include "Animation_loader.h"
#include "Level.h"

enum Render_status_t
{
	RENDER_STATUS_MENU,
	RENDER_STATUS_GAME
};

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

	void Set_level_status(Level_status_t status) { m_c_level->Set_status(status); }

	void setLevel(Level *_level) { this->m_c_level = _level; }
	void setStatus(Render_status_t _status) { this->m_status = _status; }
	static bool is_clicked;
private:
	Render_status_t m_status;

	void Init();

	static Render* m_this;
	Level* m_c_level;

	Texture_loader *m_textures;
	Animation_loader *m_animations;
	
	sf::RenderWindow *m_window;
	float m_coef_x;
	float m_coef_y;

	bool is_clicked_check;
};

