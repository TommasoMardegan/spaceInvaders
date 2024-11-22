#include "Invasore.h"

Invasore::Invasore() {
	this->tipo = 'v'; //v = verde, b = blu, r = rosa
	this->InvasoreImg = "GreenEnemy.bmp";
	this->x = 0;
	this->y = 0;
}
Invasore::Invasore(char tipoInvasore) {
	this->x = 0;
	this->y = 0;
	if (tipoInvasore == 'v' || tipoInvasore == 'b' || tipoInvasore == 'r' || tipoInvasore == 'n') {
		this->tipo = tipoInvasore;
		if (tipoInvasore == 'v') {
			this->InvasoreImg = "GreenEnemy.bmp";
		}
		if (tipoInvasore == 'b') {
			this->InvasoreImg = "BlueEnemy.bmp";
		}
		if (tipoInvasore == 'r') {
			this->InvasoreImg = "PinkEnemy.bmp";
		}
		if (tipoInvasore == 'n') {
			this->InvasoreImg = "Black.bmp";
		}
	}
	else {
		this->tipo = 'v';
		this->InvasoreImg = "GreenEnemy.bmp";
	}
}
void Invasore::DisegnaInvasoreIniziale(int x, int y) {
	this->x = x;
	this->y = y;
	Draw(this->InvasoreImg, x, y);
	Present();
}
void Invasore::DisegnaInvasore() {
	Draw(this->InvasoreImg, this->x, this->y);
	Present();
}
void Invasore::MuoviInvasoreDx() {
	if (this->x <= Width - 40) {
		this->x = this->x + 10;
	}
	else {
		this->x = this->x;
	}
}
void Invasore::MuoviInvasoreSx() {
	if (this->x > 20) {
		this->x = this->x - 10;
	}
	else {
		this->x = this->x;
	}
}
bool Invasore::ControllaXDx() {
	if (this->x == Width - 40) {
		return true;
	}
	else {
		return false;
	}
}
bool Invasore::ControllaXSx() {
	if (this->x == 20) {
		return true;
	}
	else {
		return false;
	}
}
bool Invasore::SparaColpo(int xGiocatore, int& OstacoloColpito, int viteOst1, int viteOst2, int viteOst3, int viteOst4) {
	bool colpito = false;
	int yColpo = this->y + 20;
	if (this->x + 8 > 0 && this->x + 8 < 35) {
		if (viteOst1 > 0) {
			while (yColpo < 170) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = false;
			}
			OstacoloColpito = 1;
		}
		else if (this->x + 8 < xGiocatore + 40 && this->x + 8 > xGiocatore) {
			while (yColpo < 215) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = true;
			}
		}
		else {
			while (yColpo < 300) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = false;
			}
		}
	}
	else if(this->x + 8 > 90 && this->x + 8 < 125) {
		if (viteOst2 > 0) {
			while (yColpo < 170) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = false;
			}
			OstacoloColpito = 2;
		}
		else if (this->x + 8 < xGiocatore + 40 && this->x + 8 > xGiocatore) {
			while (yColpo < 215) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = true;
			}
		}
		else {
			while (yColpo < 300) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = false;
			}
		}
	}
	else if (this->x + 8 > 155 && this->x + 8 < 185) {
		if (viteOst3 > 0) {
			while (yColpo < 170) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = false;
			}
			OstacoloColpito = 3;
		}
		else if (this->x + 8 < xGiocatore + 40 && this->x + 8 > xGiocatore) {
			while (yColpo < 215) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = true;
			}
		}
		else {
			while (yColpo < 300) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = false;
			}
		}
	}
	else if (this->x + 8 > 225 && this->x + 8 < 265) {
		if (viteOst4 > 0) {
			while (yColpo < 170) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = false;
			}
			OstacoloColpito = 4;
		}
		else if (this->x + 8 < xGiocatore + 40 && this->x + 8 > xGiocatore) {
			while (yColpo < 215) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = true;
			}
		}
		else {
			while (yColpo < 300) {
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
				Present();
				Wait(20);
				DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
				Present();
				yColpo = yColpo + 10;
				colpito = false;
			}
		}
	}
	else if (this->x + 8 < xGiocatore + 40 && this->x + 8 > xGiocatore) {
		while (yColpo < 215) {
			DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
			Present();
			Wait(20);
			DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
			Present();
			yColpo = yColpo + 10;
			colpito = true;
		}
	}
	else {
		while (yColpo < 300) {
			DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, LightGreen);
			Present();
			Wait(20);
			DrawLine(this->x + 8, yColpo, this->x + 8, yColpo + 10, 1, Black);
			Present();
			yColpo = yColpo + 10;
			colpito = false;
		}
	}
	if (colpito == true) {
		return true;
	}
	else {
		return false;
	}
}
int Invasore::GetX() {
	return this->x;
}
void Invasore::cambiaImmagine() {
	this->InvasoreImg = "Black.bmp";
}
int Invasore::getPunti() {
	int punti = 0;
	if (this->InvasoreImg == "GreenEnemy.bmp") {
		punti = 30;
	}
	else if (this->InvasoreImg == "BlueEnemy.bmp") {
		punti = 20;
	}
	else if (this->InvasoreImg == "PinkEnemy.bmp") {
		punti = 10;
	}
	return punti;
}