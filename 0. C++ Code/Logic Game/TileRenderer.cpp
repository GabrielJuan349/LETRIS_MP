// FINISHED


#include"TileRenderer.h"

TileRenderer::TileRenderer() {
	
	for (int i = 0; i < MAX_ALPHABET_ENGLISH; i++) {
		string path_normal = "./data/letters/white_" + std::to_string(i) + ".png";
		m_aLetters_Normal[i].create(path_normal.c_str());
	}

	for (int i = 0; i < MAX_ALPHABET_ENGLISH; i++) {	
		string path_pressed = "./data/letters/yellow_" + std::to_string(i) + ".png";
		m_aLetters_Pressed[i].create(path_pressed.c_str());
	}
}

TileRenderer::~TileRenderer() {
}

void TileRenderer::Render(int col, int fil, int letter) {
	int letra, colf, filf;
	int columna_inicial = 37;
	int fila_inicial = 147;
	

	letra = letter - 65;
	// letter = A --> i = 65 --> letra = 0

	colf = columna_inicial + ((col) * TILE_WIDTH);
	filf = fila_inicial + (((BOARD_ROWS - 1)- fil) * TILE_HEIGHT);

	m_aLetters_Normal[letra].draw(colf, filf);

}

void TileRenderer::RenderPressed(int col, int fil, int letter) {
	int letra, colf, filf;
	int columna_inicial = 37;
	int fila_inicial = 147;
	letra = letter - 65;

	
	// letter = A --> i = 65 --> letra = 0

	colf = columna_inicial + (col * TILE_WIDTH);
	filf = fila_inicial + (fil * TILE_HEIGHT);

	m_aLetters_Pressed[letra].draw(colf, filf);
}

void TileRenderer::WordRender(vector<int>word, int size) {

	int letra, colf;

	int fila = 700;
	int columna_inicial = 37;
	for (int i = 0; i < size; i++) {

		letra = word[i] - 65;

		colf = columna_inicial + (i * TILE_WIDTH);

		m_aLetters_Normal[letra].draw(colf, fila);

	}
}

void TileRenderer::RenderSpeed(int col, int posY, int letter) {

	int columna_inicial = 37;
	int letra = letter - 65;

	int columna = columna_inicial + (col * TILE_WIDTH);

	m_aLetters_Normal[letra].draw(columna, posY);

}
