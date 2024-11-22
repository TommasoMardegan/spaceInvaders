#pragma once
#include "Invasore.h"
int const MAX = 28;
class InsiemeInv
{
private:
	Invasore Insieme[MAX];
	int InsiemeIndici[MAX];
	int nEl;
public:
	InsiemeInv();
	void Inserisci(Invasore Inv, int indice);
	bool Cerca(int indiceRicerca);
	Invasore GetInvasore(int indice);
};

