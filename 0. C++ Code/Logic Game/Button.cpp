#include "button.h"

button::button()
{
	buttons[0].create("./data/GUI/Button_Normal.png");
	buttons[1].create("./data/GUI/Button_Pressed.png");
	buttons[2].create("./data/GUI/Btn_Circle_Close_1_Normal.png");
	buttons[3].create("./data/GUI/Btn_Circle_Close_3_Pressed.png");

	m_x = 0;
	m_y = 0;

	dim_x = 0;
	dim_y = 0;

	pressed = false;
}

bool button::buttonUpdate()
{
	bool req = false;
	if (Mouse_getX() > m_x && Mouse_getX() < m_x + dim_x && Mouse_getY() > m_y && Mouse_getY() < m_y + dim_y)
	{
		if (Mouse_getBtnLeft()){
			pressed = true;
		}

		else
		{
			if (pressed){
				req = true;
			}
			else{
				pressed = false;
			}
		}
	}

	else {
		pressed = false;
	}

	return req;
}

bool button::buttonPress()
{
	return pressed;
}

void button::buttonDraw(int b)
{
	switch (b)
	{
		case 0:
			dim_x = 194;
			dim_y = 85;

			m_x = 150;
			m_y = 750;

			if (pressed){
				buttons[1].draw(150, 750);
			}
			else{
				buttons[0].draw(150, 750);
			}

			break;

		case 1:
			dim_x = 90;
			dim_y = 90;

			m_x = 350;
			m_y = 760;

			if (pressed){
				buttons[3].draw(350, 760);
			}
			else{
				buttons[2].draw(350, 760);
			}

			break;
	}
}
