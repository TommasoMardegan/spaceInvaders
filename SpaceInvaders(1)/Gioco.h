#include "drawing.h"
#include <iostream>
#include "windows.h"
using namespace std;
#pragma once
class Gioco
{
private:
	string SfondoImg;
	int vite;
	int Punti;
public:
	Gioco();
	void disegnaSfondo();
	void disegnaStrIniziale();
	void disegnaIndicazioni();
	void disegnaPuntiVite();
	void DiminuisciVite();
	void vittoria();
	void Sconfitta();
	int GetVite();
	void SetPunti(int punti);
};

