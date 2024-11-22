#include "Gioco.h"

Gioco::Gioco() {
	this->SfondoImg = "IniBackground.bmp";
	this->vite = 5;
	this->Punti = 0;
}
void Gioco::disegnaSfondo() {
	Draw(this->SfondoImg, 0, 0);
	Present();
}
void Gioco::disegnaStrIniziale() {
	DrawString(60, Height/2 - 40, "Space Invaders", "Arial", 20, LightGreen);
	Present();
}
void Gioco::disegnaIndicazioni() {
	DrawString(30, Height/2 - 10, "Premi tasto destro e sinistro del mouse per muoverti", "Arial", 8, LightGreen);
	DrawString(100, Height / 2, "e spazio per sparare", "Arial", 8, LightGreen);
	Present();
}
void Gioco::disegnaPuntiVite() {
	DrawString(215, 7, "Punti: ", "Arial", 7, LightCyan);
	string StrPunti = to_string(this->Punti);
	DrawString(240, 7, StrPunti, "Arial", 7, LightCyan);
	DrawString(260, 7, "Vite: ", "Arial", 7, LightGreen);
	string StrVite = to_string(this->vite);
	DrawString(280, 7, StrVite, "Arial", 7, LightGreen);
	Present();
}
void Gioco::vittoria() {
	Clear(Black);
	this->SfondoImg = "VittoriaBackground.bmp";
	Draw(this->SfondoImg, 0, 0);
	DrawString(95, Height / 2 - 40, "Hai vinto!", "Arial", 20, LightGreen);
	DrawString(98, Height / 2 - 10, "La galassia ti ringrazia!", "Arial", 8, LightGreen);
	Present();
	Wait(10000);
	system("PAUSE");
}
void Gioco::Sconfitta() {
	Clear(Black);
	this->SfondoImg = "SconfittaBackground.bmp";
	Draw(this->SfondoImg, 0, 0);
	DrawString(95, Height / 2 - 40, "Hai perso!", "Arial", 20, LightGreen);
	DrawString(98, Height / 2 - 7, "La galassia e' perduta!", "Arial", 8, LightGreen);
	Present();
	Wait(10000);
	system("PAUSE");
}
void Gioco::DiminuisciVite() {
	this->vite = this->vite - 1;
}
int Gioco::GetVite() {
	return this->vite;
}
void Gioco::SetPunti(int punti) {
	this->Punti = punti;
}
