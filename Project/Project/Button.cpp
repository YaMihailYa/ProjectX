#include "Button.h"
#include "Render.h"

Button::Button(int x0, int y0, int width, int height, menu_type_t m_menu_name, btn_type_t m_btn_name)
{
	sf::Vector2f coef = Render::Get()->Get_coef();
	rectangle = sf::IntRect(x0*coef.x, y0*coef.y, width*coef.x, height*coef.y);
	this->m_menu_name = m_menu_name;
	this->m_btn_name = m_btn_name;
}

Button::~Button() { }

int Button::getX0() { return rectangle.left; }

int Button::getY0() { return rectangle.top; }

int Button::getWidth() { return rectangle.width; }

int Button::getHeight() { return rectangle.height; }

menu_type_t Button::getMenuName() { return m_menu_name; }

btn_type_t Button::getBtnName() { return m_btn_name; }

bool Button::isClicked()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		//printf("mouse\n");
		// get global mouse position
		sf::Vector2i position = sf::Mouse::getPosition();

		int x = position.x;
		int y = position.y;

		if (x >= getX0() && x <= getX0() + getWidth()) 
		{
			if (y >= getY0() && y <= getY0() + getHeight())
			{
				return true;
			}
		}
	}

	return false;
}
