#pragma once
#include "../Graphic Lib/libreria.h"

class button
{
public:
	button();

	bool buttonUpdate();
	bool buttonPress();

	void buttonDraw(int);
	
private:
	Sprite buttons[4];

	int m_x, m_y;
	int dim_x, dim_y;

	bool pressed;
};
