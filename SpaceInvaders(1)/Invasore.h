#pragma once
#include <iostream>
#include "drawing.h"
using namespace std;

class Invasore
{
private:
	char tipo;
	string InvasoreImg;
	int x;
	int y;
public:
	Invasore();
	Invasore(char tipoInvasore);
	void DisegnaInvasoreIniziale(int x, int y);
	void DisegnaInvasore();
	void MuoviInvasoreDx();
	void MuoviInvasoreSx();
	bool ControllaXDx();
	bool ControllaXSx();
	bool SparaColpo(int xGiocatore, int &OstacoloColpito, int viteOst1, int viteOst2, int viteOst3, int viteOst4);
	int GetX();
	void cambiaImmagine();
	int getPunti();
};

