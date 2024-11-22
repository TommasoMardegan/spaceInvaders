#include "InsiemeInv.h"

InsiemeInv::InsiemeInv() {
	this->nEl = 0;
}
void InsiemeInv::Inserisci(Invasore Inv, int Indice) {
	if (this->nEl < MAX) {
		this->Insieme[this->nEl] = Inv;
		this->InsiemeIndici[this->nEl] = Indice;
	}
}
bool InsiemeInv::Cerca(int indiceRicerca) {
	for (int i = 0; i < this->nEl; i++) {
		if (this->InsiemeIndici[i] == indiceRicerca) {
			return true;
		}
		return false;
	}
}
Invasore InsiemeInv::GetInvasore(int indice) {
	return this->Insieme[indice];
}