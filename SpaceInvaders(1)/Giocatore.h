#pragma once
#include <iostream>
#include "drawing.h"
using namespace std;

class Giocatore
{
private:
	int x;
	int y;
	int xGiocatore;
	int yGiocatore;
	string giocatoreImg;
	string colpoGiocatore;
public:
	Giocatore();
	void disegnaGiocatore(int x, int y);
	void disegnaGiocatoreSP();
	int MuoviSinistra();
	int MuoviDestra();
	int SparaColpo(int viteOst1, int viteOst2, int viteOst3, int viteOst4);
	int GetX();
};

