#include "ColonnaInvasori.h"

ColonnaInvasori::ColonnaInvasori() {
	this->nEl = 0;
	this->nInvasoriVivi = 0;
	this->PuntiColonna = 0;
}
void ColonnaInvasori::Inserisci(Invasore Inv, int indice) {
	if (this->nEl < MAXC) {
		this->colonna[this->nEl] = Inv;
		this->IndiciColonna[this->nEl] = indice;
		this->nEl++;
		this->nInvasoriVivi++;
	}
}
bool ColonnaInvasori::cercaIndice(int indice) {
	for (int i = 0; i < this->nEl; i++) {
		if (this->IndiciColonna[i] == indice) {
			return true;
		}
	}
	return false;
}
void ColonnaInvasori::Elimina(int indice) {
	for (int i = 0; i < this->nEl; i++) {
		if (this->IndiciColonna[i] == indice) {
			int punti = colonna[i].getPunti();
			this->PuntiColonna = this->PuntiColonna + punti;
			colonna[i].cambiaImmagine();
			this->IndiciColonna[i] = 0;
			this->nInvasoriVivi--;
		}
	}
}
void ColonnaInvasori::DisegnaColonna() {
	for (int i = 0; i < this->nEl; i++) {
		colonna[i].DisegnaInvasore();
	}
}
void ColonnaInvasori::MuoviInvasoriSx() {
	for (int i = 0; i < this->nEl; i++) {
		colonna[i].MuoviInvasoreSx();
	}
}
void ColonnaInvasori::MuoviInvasoriDx() {
	for (int i = 0; i < this->nEl; i++) {
		colonna[i].MuoviInvasoreDx();
	}
}
bool ColonnaInvasori::ControllaXDx() {
	for (int i = 0; i < this->nEl; i++) {
		if (this->colonna[i].ControllaXDx() == true) {
			return true;
		}
	}
	return false;
}
bool ColonnaInvasori::ControllaXSx() {
	for (int i = 0; i < this->nEl; i++) {
		if (this->colonna[i].ControllaXSx() == true) {
			return true;
		}
	}
	return false;
}
Invasore ColonnaInvasori::GetInvasore(int indice) {
	for (int i = 0; i < this->nEl; i++) {
		if (this->IndiciColonna[i] == indice) {
			return this->colonna[i];
		}
	}
}

bool ColonnaInvasori::controllaSeVuota() {
	if (this->nEl == 0) {
		return true;
	}
	return false;
}
int ColonnaInvasori::GetnInvasoriVivi() {
	return this->nInvasoriVivi;
}
bool ColonnaInvasori::SparaRandomInvasore(int XGiocatore, int &OstacoloColpito1, int viteOst1, int viteOst2, int viteOst3, int viteOst4) {
	int OstacoloColpito2 = 0;
	bool InvTrovato = false;
	int randomIndice = 0;
	while (InvTrovato == false) {
		randomIndice = rand() % 4;
		if (this->IndiciColonna[randomIndice] != 0) {
			InvTrovato = true;
		}
	}
	bool PlayerColpito = this->colonna[randomIndice].SparaColpo(XGiocatore, OstacoloColpito2, viteOst1, viteOst2, viteOst3, viteOst4);
	OstacoloColpito1 = OstacoloColpito2;
	if (PlayerColpito == true) {
		return true;
	}
	else {
		return false;
	}
}
int ColonnaInvasori::GetPuntiColonna() {
	return this->PuntiColonna;
}