#include "joc.h"
#include "../Graphic Lib/NFont/NFont.h"




//-----------------------------------------
// joc: porta el control de tot el joc
//-----------------------------------------
void joc()
{
	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	Screen pantalla(MIDA_X, MIDA_Y);
	//Mostrem la finestra grafica
	pantalla.show();

	//------------------------------------
	//-----Introducci— a la prˆctica -----
	//
	//  TODO:   Aqu’ heu de crear els sprites/fonts i
	//          totes les variables necessˆries per
	//          treballar en el bucle principal de
	//          sota (do...while).
	//
	//------------------------------------

	//-----TODO 1
	//Crear un timer i mostrar per pantalla el temps passat
	float timer = 0.0f;
	NFont font("data/Fonts/FreeSans.ttf",
		30, NFont::Color(0, 0, 0, 255));
	bool drawTimer = true;
	//-----TODO 1


	//-----TODO 2
	//-Pintar una matriu de 4x4 amb el sprite de la lletra 'a' de letris
	//-Pintar un sprite de bot— i cada cop que es clica pintar o deixar de pintar el bot—
	bool drawMatrix = true;
	Sprite lletraA("./data/Letters/white_0.png");
	//Sprite boto("./data/GUI/Btn_Circle_Close_1_Normal.png");
	//-----TODO 2
	Sprite botoNotPush("./data/GUI/Btn_Circle_Close_1_Normal.png");
	Sprite botoPushed("./data/GUI/Btn_Circle_Close_3_Pressed.png");
	Sprite fons("./data/GUI/background_play.png");
	Sprite GOver("./data/GUI/GameOver.png");
	Sprite Start("./data/GUI/Button_Normal.png");
	//Modificacio per entrega del 3 d'abril

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;


	int a = 0;
	int language;
	char let;
	bool correct, deleteb;
	vector<char> paraula;
	Dictionary correcto;
	Word word;
	InfoLetters letter;
	TileRenderer letra;

	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

		// Captura tots els events de ratolí i teclat de l'ultim cicle
		pantalla.processEvents();

		bool mouseStatus = Mouse_getBtnLeft();
		bool moousePressed = Mouse_getButLeft();

		int mousePosX = Mouse_getX();
		int mousePosY = Mouse_getY();

		//-----TODO 1---[INIT]
		//Crear un timer i mostrar per pantalla el temps passat

		timer += deltaTime;
		
		font.draw(47, 147, NFont::Scale(0.85f), "Temps transcorregut: %d", (int)timer);
		
		//-----TODO 1----[END]


		//-----TODO 2----[INIT]
		//-Pintar una matriu de 4x4 amb el sprite de la lletra 'a' de letris
		//-Pintar un sprite de bot— i cada cop que es clica pintar o deixar de pintar el bot—
		if (drawMatrix) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					int posX = 100 + (i * TILE_WIDTH);
					int posY = 200 + (j * TILE_WIDTH);
					lletraA.draw(posX, posY);
				}
			}

		}
		//Modificacio per entrega 3 d'abril [INICI]

		fons.draw(0, 0);
		deleteb = false;
		int posButton_X = 375;
		int posButton_Y = 650;

	    if (mousePosX > posButton_X && mousePosX < posButton_X + 90 &&
		    mousePosY > posButton_Y && mousePosY < posButton_Y + 90 &&
		    mouseStatus) {
			botoPushed.draw(posButton_X, posButton_Y);
		    drawMatrix = !drawMatrix;
			deleteb = true;
		}
		else {
		   botoNotPush.draw(posButton_X, posButton_Y);
		   lletraA.draw(33, 464);
		}

	
	//Modificacio per entrega 3 d'abril [END]
		/*if (a < 3) {
			cin >> language;

			correcto.SelectLanguage(language);
			for (int i = 0; i < 4; i++)
			{
				cin >> let;
				paraula.push_back(let);
			}

			correct = correcto.SearchWord(paraula);
			if (correct == true) {
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}

			paraula.clear();
		}
		else {*/

			letter.setLetter(75);
			letter.setPosition(4, 0);
			//letter.animCaiguda(deltaTime, 0, 4, 100);
			letter.ControlLetter(mousePosX, mousePosY, moousePressed, mouseStatus, deleteb);

			cout << letter.getselect() << endl;;

			//if (letter)
		//}


		

		
		a++;
	// Actualitza la pantalla
	pantalla.update();

} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
// Sortim del bucle si pressionem ESC

}


