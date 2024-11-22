#include "Ostacolo.h"

Ostacolo::Ostacolo() {
	this->viteOstacolo = 3;
	this->OstacoloImg = "ObstacleFull.bmp";
}
void Ostacolo::disegnaOstacolo(int x, int y) {
	if (this->viteOstacolo == 3) {
		this->OstacoloImg = "ObstacleFull.bmp";
	}
	else if (this->viteOstacolo == 2) {
		this->OstacoloImg = "ObstacleHit1.bmp";
		x = x + 1.5;
	}
	else if (this->viteOstacolo == 1) {
		this->OstacoloImg = "ObstacleHit2.bmp";
	}
	else {
		this->OstacoloImg = "Black.bmp";
	}
	Draw(this->OstacoloImg, x, y);
	Present();
}
void Ostacolo::DiminuisciViteOstacolo() {
	if (viteOstacolo != 0) {
		this->viteOstacolo = this->viteOstacolo - 1;
	}
}
int Ostacolo::getViteOst() {
	return this->viteOstacolo;
}