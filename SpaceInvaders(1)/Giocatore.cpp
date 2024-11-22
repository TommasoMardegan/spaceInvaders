#include "Giocatore.h"

Giocatore::Giocatore() {
	this->x = Width / 2 - 40;
	this->y = 180;
	this->xGiocatore = Width/2-40;
	this->yGiocatore = 180;
	this->giocatoreImg = "PlayerIcon.bmp";
}
void Giocatore::disegnaGiocatore(int x, int y) {
	Clear(Black);
	Draw(this->giocatoreImg, x, y);
	this->xGiocatore = x;
	this->yGiocatore = y;
	Present();
}
void Giocatore::disegnaGiocatoreSP() {
	Clear(Black);
	Draw(this->giocatoreImg, this->xGiocatore, this->yGiocatore);
	Present();
}
int Giocatore::MuoviSinistra() {
	int spostamento = this->x - 5;
	if (spostamento > 0) {
		this->x = this->x - 5;
		return spostamento;
	}
	else {
		return x;
	}
}
int Giocatore::MuoviDestra() {
	int spostamento = this->x + 5;
	if (spostamento < Width - 40) {
		this->x = this->x + 5;
		return spostamento;
	}
	else {
		return x;
	}
}
int Giocatore::SparaColpo(int viteOst1, int viteOst2, int viteOst3, int viteOst4) {
	int yColpo = this->y + 20;
	if (this->x > 0 && this->x < 35) {
		if (viteOst1 > 0) {
			while (yColpo > 190) {
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, White);
				Present();
				Wait(20);
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, Black);
				Present();
				yColpo = yColpo - 10;
			}
			return 1;
		}
		else {
			while (yColpo > 0) {
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, White);
				Present();
				Wait(15);
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, Black);
				Present();
				yColpo = yColpo - 10;
			}
			return 0;
		}
	}
	else if (this->x > 65 && this->x < 105) {
		if (viteOst2 > 0) {
			while (yColpo > 190) {
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, White);
				Present();
				Wait(20);
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, Black);
				Present();
				yColpo = yColpo - 10;
			}
			return 2;
		}
		else {
			while (yColpo > 0) {
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, White);
				Present();
				Wait(15);
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, Black);
				Present();
				yColpo = yColpo - 10;
			}
			return 0;
		}
	}
	else if (this->x > 135 && this->x < 175) {
		if (viteOst3 > 0) {
			while (yColpo > 190) {
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, White);
				Present();
				Wait(20);
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, Black);
				Present();
				yColpo = yColpo - 10;
			}
			return 3;
		}
		else {
			while (yColpo > 0) {
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, White);
				Present();
				Wait(15);
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, Black);
				Present();
				yColpo = yColpo - 10;
			}
			return 0;
		}
	}
	else if (this->x > 205 && this->x < 245) {
		if (viteOst4 > 0) {
			while (yColpo > 190) {
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, White);
				Present();
				Wait(20);
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, Black);
				Present();
				yColpo = yColpo - 10;
			}
			return 4;
		}
		else {
			while (yColpo > 0) {
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, White);
				Present();
				Wait(15);
				DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, Black);
				Present();
				yColpo = yColpo - 10;
			}
			return 0;
		}
	}
	else {
		while (yColpo > 0) {
			DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, White);
			Present();
			Wait(15);
			DrawLine(this->x + 25, yColpo, this->x + 25, yColpo - 10, 1, Black);
			Present();
			yColpo = yColpo - 10;
		}
		return 0;
	}
}
int Giocatore::GetX() {
	return this->xGiocatore;
}