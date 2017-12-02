#include "Button.h"
#include "Render.h"

Button::Button(int x0, int y0, int width, int height, menu_type_t m_menu_name, btn_type_t m_btn_name)
{
	sf::Vector2f coef = Render::Get()->Get_coef();
	rectangle = sf::IntRect(x0*coef.x, y0*coef.y, width*coef.x, height*coef.y);
	this->m_menu_name = m_menu_name;
	this->m_btn_name = m_btn_name;
	fl_clicked = false;

	x0_click = -2;
	y0_click = -2;
}

Button::~Button() { }

int Button::getX0() { return rectangle.left; }

int Button::getY0() { return rectangle.top; }

int Button::getX0Click() { return x0_click; }

int Button::getY0Click() { return 0; }

int Button::getWidth() { return rectangle.width; }

int Button::getHeight() { return rectangle.height; }

menu_type_t Button::getMenuName() { return m_menu_name; }

btn_type_t Button::getBtnName() { return m_btn_name; }

bool Button::isClicked()
{
	//if (fl_clicked == true) { return false; }

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// get global mouse position
		sf::Vector2i position = sf::Mouse::getPosition();

		int x = position.x;
		int y = position.y;

		if (x >= getX0() && x <= getX0() + getWidth()) 
		{
			if (y >= getY0() && y <= getY0() + getHeight())
			{
				printf("mouse\n");

				x0_click = x;
				y0_click = y;

				//fl_clicked = true;
				return true;
			}
		}
	}

	return false;
}
