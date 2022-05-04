#include "Word.h"


Word::~Word()
{
	m_word.clear();
	m_wordpicture.clear();
	m_posX.clear();
	m_posY.clear();
}

void Word::EnterLetter(int letter, int col, int fil) {

	int i = letter + 76;
	char letra = i;

	if (m_word.size() < BOARD_COLS) {

		//control paraula
		m_word.push_back(letra);

		m_wordpicture.push_back(letter);
		m_printpic.WordRender(m_wordpicture, m_wordpicture.size());

		//control lletres
		
		m_posX.push_back(col);
		m_posY.push_back(fil);
	}
}
