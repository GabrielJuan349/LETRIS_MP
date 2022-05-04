// FINISHED





#pragma once
#include "../Graphic Lib/libreria.h"
#include <string>
#include <vector>
#include "InfoImportant.h"

using namespace std;


class TileRenderer
{
public:
	TileRenderer();
	~TileRenderer();
	void Render(int col, int fil, int letter);
	void RenderPressed(int col, int fil, int letter);
	void WordRender(vector<int>word, int size);
	void RenderSpeed(int col, int posY, int letter);

private:
	Sprite m_aLetters_Normal[MAX_ALPHABET_ENGLISH];
	Sprite m_aLetters_Pressed[MAX_ALPHABET_ENGLISH];
};

