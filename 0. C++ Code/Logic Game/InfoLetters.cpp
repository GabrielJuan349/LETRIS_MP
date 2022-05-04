#include "InfoLetters.h"

void InfoLetters::setPosition(int X, int Y) {

	m_posX = X;
	m_posXdetail = 37 + (X * TILE_WIDTH);

	m_posY = Y;
	m_posYdetail = 147 + (Y * TILE_HEIGHT);
}

void InfoLetters::ControlLetter(int mousePosX, int mousePosY, bool mouseisPressed, bool mouseStatus, bool DeleteWordButton) {

	if ((mousePosX >= m_posXdetail && mousePosX <= m_posXdetail + TILE_WIDTH &&
		mousePosY >= m_posYdetail && mousePosY <= m_posYdetail + TILE_HEIGHT)
		&& (mouseisPressed == true) && (mouseStatus == true)) {
		
		m_select = true;
		m_doaction = true;
	}
	else
	{
		if (DeleteWordButton == false) {
			m_select = m_select;
		}
		else {
			m_select = false;
		}

		m_doaction = false;
	}
	
	
	


	if (m_select == false) {
		m_letra.Render(m_posX, m_posY, m_letter);
	}
	else {
		m_letra.RenderPressed(m_posX, m_posY, m_letter);
	}

}

void InfoLetters::animCaiguda(float deltatime, int fila, int X, int speed){
	
	
	int fil = 147 + (((BOARD_COLS + 1) - fila) * TILE_HEIGHT);
	
	if (m_posYcaiguda <= fil) {
		m_letra.RenderSpeed(X, m_posYcaiguda, m_letter);
		m_posYcaiguda += (deltatime*2)*speed;
	}
	else {
		m_finCaiguda = true;
	}

	
}
