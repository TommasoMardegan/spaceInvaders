#pragma once
#include "Invasore.h"
int const MAXC = 4;
class ColonnaInvasori
{
private:
	Invasore colonna[MAXC];
	int IndiciColonna[MAXC];
	int nEl;
	int nInvasoriVivi;
	int PuntiColonna;
public:
	ColonnaInvasori();
	void Inserisci(Invasore Inv, int indice);
	bool cercaIndice(int indice);
	void Elimina(int indice);
	void DisegnaColonna();
	void MuoviInvasoriSx();
	void MuoviInvasoriDx();
	bool ControllaXDx();
	bool ControllaXSx();
	Invasore GetInvasore(int indice);
	bool controllaSeVuota();
	int GetnInvasoriVivi();
	bool SparaRandomInvasore(int XGiocatore, int &OstacoloColpito, int viteOst1, int viteOst2, int viteOst3, int viteOst4);
	int GetPuntiColonna();
};

