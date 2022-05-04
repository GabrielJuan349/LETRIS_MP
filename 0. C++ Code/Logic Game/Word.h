#pragma once
#include <string>
#include <vector>
#include "TileRenderer.h"
#include "InfoImportant.h"

using namespace std;

class Word
{
public:

	~Word();
	vector<char> Getword() { return m_word; }
	vector<int> Getwordpic() { return m_wordpicture; }
	vector<int> GetposX() { return m_posX; }
	vector<int> GetposY() { return m_posY; }
	void EnterLetter(int letter, int col, int fil);

private:
	//Palabra a buscar
	vector<char> m_word;
	vector<int> m_wordpicture;
	TileRenderer m_printpic;

	// posicion de las letras dentro de la matriz
	vector<int> m_posX;
	vector<int> m_posY;
};

