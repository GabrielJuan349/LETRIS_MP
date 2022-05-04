#pragma once
#include "TileRenderer.h"
#include "InfoImportant.h"


class InfoLetters
{
public:
	InfoLetters(): m_select(false), m_doaction(false), m_posYcaiguda(147) {}
	~InfoLetters() {}
	
	void setPosition(int X, int Y);
	void setLetter(int letter) { m_letter = letter; }
	int getLetter() { return m_letter; }
	int getposX() { return m_posX; }
	int getposY() { return m_posY; }
	void ControlLetter(int mousePosX, int mousePosY, bool mouseisPressed, bool mouseStatus,
		bool DeleteWordButton);
	bool getselect() { return m_doaction; }

	void animCaiguda(float deltatime, int fila, int X, int speed);
	bool getfinCaiguda() { return m_finCaiguda; }



private:

	TileRenderer m_letra;
	int m_letter;
	int m_posX;
	int m_posY;
	int m_posXdetail;
	int m_posYdetail;
	int m_posYcaiguda;
	bool m_select;
	bool m_doaction;
	bool m_finCaiguda;



};
