#pragma once
#include <iostream>
#include "drawing.h"
using namespace std;
class Ostacolo
{
private:
	string OstacoloImg;
	int viteOstacolo;
public:
	Ostacolo();
	void disegnaOstacolo(int x, int y); 
	void DiminuisciViteOstacolo();
	int getViteOst();
};

