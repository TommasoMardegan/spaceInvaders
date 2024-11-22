//+	Navicella del giocatore che può muoversi a destra o sinistra.
//+	“Invasori” generati nella mappa di gioco in alto che si muovono a destra e sinistra.
//+	La navicella può sparare dei missili che quando colpiscono gli invasori li uccidono.
//+ Anche gli invasori sparano dei missili dopo un certo timer che si ripete, che se colpiscono il giocatore lo danneggiano.
//+	Il giocatore può subire al massimo 3 colpi dopodiché il gioco finisce.
//+	Il programma implementa anche degli ostacoli che impediscono al giocatore di essere colpito(possono subire al massimo 3 colpi).
//+	Ogni classe di invasore vale dei punti(30 verde, 20 blu e 10 rosa).
//+	Il gioco finisce quando tutti gli invasori vengono respinti o il giocatore muore.

#include <iostream>
#include "Giocatore.h"
#include "Gioco.h"
#include "drawing.h"
#include "Invasore.h"
#include "Ostacolo.h"
#include "InsiemeInv.h"
#include "ColonnaInvasori.h"
using namespace std;
int const YPlayer = 200;
bool gioco = true;
int spostamento;
Giocatore Player;
Gioco Schermata;
char TastoPremuto;
bool alternaDxSx = true;
Ostacolo Ost1, Ost2, Ost3, Ost4;
int yOst = 165;
int xOst1 = 20, xOst2 = 90, xOst3 = 160, xOst4 = 230;
Invasore Inv1('v'), Inv2('v'), Inv3('v'), Inv4('v'), Inv5('v'), Inv6('v');
Invasore Inv8('b'), Inv9('b'), Inv10('b'), Inv11('b'), Inv12('b'), Inv13('b');
Invasore Inv15('b'), Inv16('b'), Inv17('b'), Inv18('b'), Inv19('b'), Inv20('b');
Invasore Inv22('r'), Inv23('r'), Inv24('r'), Inv25('r'), Inv26('r'), Inv27('r');
InsiemeInv InvasoriVivi;
ColonnaInvasori PrimaCol;
ColonnaInvasori SecondaCol;
ColonnaInvasori TerzaCol;
ColonnaInvasori QuartaCol;
ColonnaInvasori QuintaCol;
ColonnaInvasori SestaCol;
int RandInvasore, viteOst1, viteOst2, viteOst3, viteOst4;
bool trovato = false;
int OstacoloColpito = 0;
void main() {
	srand(time(NULL));
	if (Schermata.GetVite() == 0) {
		Schermata.Sconfitta();
	}
	UseDoubleBuffering(true);
	Player.disegnaGiocatore(0, YPlayer);
	Schermata.disegnaSfondo();
	Schermata.disegnaStrIniziale();
	Schermata.disegnaIndicazioni();
	Wait(3000);
	Clear(Black);
	Player.disegnaGiocatore(Width/2 - 40, YPlayer);
	Schermata.disegnaPuntiVite();
	Ost1.disegnaOstacolo(xOst1, yOst);
	Ost2.disegnaOstacolo(xOst2, yOst);
	Ost3.disegnaOstacolo(xOst3, yOst);
	Ost4.disegnaOstacolo(xOst4, yOst);
	Inv1.DisegnaInvasoreIniziale(50, 20);
	Inv2.DisegnaInvasoreIniziale(80, 20);
	Inv3.DisegnaInvasoreIniziale(110, 20);
	Inv4.DisegnaInvasoreIniziale(140, 20);
	Inv5.DisegnaInvasoreIniziale(170, 20);
	Inv6.DisegnaInvasoreIniziale(200, 20);
	Inv8.DisegnaInvasoreIniziale(50, 50);
	Inv9.DisegnaInvasoreIniziale(80, 50);
	Inv10.DisegnaInvasoreIniziale(110, 50);
	Inv11.DisegnaInvasoreIniziale(140, 50);
	Inv12.DisegnaInvasoreIniziale(170, 50);
	Inv13.DisegnaInvasoreIniziale(200, 50);
	Inv15.DisegnaInvasoreIniziale(50, 80);
	Inv16.DisegnaInvasoreIniziale(80, 80);
	Inv17.DisegnaInvasoreIniziale(110, 80);
	Inv18.DisegnaInvasoreIniziale(140, 80);
	Inv19.DisegnaInvasoreIniziale(170, 80);
	Inv20.DisegnaInvasoreIniziale(200, 80);
	Inv22.DisegnaInvasoreIniziale(50, 110);
	Inv23.DisegnaInvasoreIniziale(80, 110);
	Inv24.DisegnaInvasoreIniziale(110, 110);
	Inv25.DisegnaInvasoreIniziale(140, 110);
	Inv26.DisegnaInvasoreIniziale(170, 110);
	Inv27.DisegnaInvasoreIniziale(200, 110);
	PrimaCol.Inserisci(Inv1, 1);
	PrimaCol.Inserisci(Inv8, 8);
	PrimaCol.Inserisci(Inv15, 15);
	PrimaCol.Inserisci(Inv22, 22);
	SecondaCol.Inserisci(Inv2, 2);
	SecondaCol.Inserisci(Inv9, 9);
	SecondaCol.Inserisci(Inv16, 16);
	SecondaCol.Inserisci(Inv23, 23);
	TerzaCol.Inserisci(Inv3, 3);
	TerzaCol.Inserisci(Inv10, 10);
	TerzaCol.Inserisci(Inv17, 17);
	TerzaCol.Inserisci(Inv24, 24);
	QuartaCol.Inserisci(Inv4, 4);
	QuartaCol.Inserisci(Inv11, 11);
	QuartaCol.Inserisci(Inv18, 18);
	QuartaCol.Inserisci(Inv25, 25);
	QuintaCol.Inserisci(Inv5, 5);
	QuintaCol.Inserisci(Inv12, 12);
	QuintaCol.Inserisci(Inv19, 19);
	QuintaCol.Inserisci(Inv26, 26);
	SestaCol.Inserisci(Inv6, 6);
	SestaCol.Inserisci(Inv13, 13);
	SestaCol.Inserisci(Inv20, 20);
	SestaCol.Inserisci(Inv27, 27);
	while (gioco == true) {
		while (trovato == false) {
			int XPlayer = Player.GetX();
			viteOst1 = Ost1.getViteOst();
			viteOst2 = Ost2.getViteOst();
			viteOst3 = Ost3.getViteOst();
			viteOst4 = Ost4.getViteOst();
			int randomColonna = 1 + rand() % 6;
			if (randomColonna == 1) {
				if (PrimaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = PrimaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 2) {
				if (SecondaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = SecondaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 3) {
				if (TerzaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = TerzaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 4) {
				if (QuartaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = QuartaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 5) {
				if (QuintaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = QuintaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 6) {
				if (SestaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = SestaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
		}
		char key = LastKey();
		if (key == ' ') {
			viteOst1 = Ost1.getViteOst();
			viteOst2 = Ost2.getViteOst();
			viteOst3 = Ost3.getViteOst();
			viteOst4 = Ost4.getViteOst();
			int OstacoloDanneggiato = Player.SparaColpo(viteOst1, viteOst2, viteOst3, viteOst4);
			if (OstacoloDanneggiato == 1) {
				Ost1.DiminuisciViteOstacolo();
			}
			else if (OstacoloDanneggiato == 2) {
				Ost2.DiminuisciViteOstacolo();
			}
			else if (OstacoloDanneggiato == 3) {
				Ost3.DiminuisciViteOstacolo();
			}
			else if (OstacoloDanneggiato == 4) {
				Ost4.DiminuisciViteOstacolo();
			}
			else {
				int xColpo = Player.GetX();
				if (PrimaCol.GetInvasore(22).GetX() - 25 < xColpo && xColpo < PrimaCol.GetInvasore(22).GetX() - 10) {
					if (PrimaCol.cercaIndice(22) == true) {
						Clear(Black);
						PrimaCol.Elimina(22);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (PrimaCol.cercaIndice(15) == true) {
						Clear(Black);
						PrimaCol.Elimina(15);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (PrimaCol.cercaIndice(8) == true) {
						Clear(Black);
						PrimaCol.Elimina(8);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (PrimaCol.cercaIndice(1) == true) {
						Clear(Black);
						PrimaCol.Elimina(1);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
				}
				else if (SecondaCol.GetInvasore(23).GetX() - 25 < xColpo && xColpo < SecondaCol.GetInvasore(23).GetX() - 10) {
					if (SecondaCol.cercaIndice(23) == true) {
						Clear(Black);
						SecondaCol.Elimina(23);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (SecondaCol.cercaIndice(16) == true) {
						Clear(Black);
						SecondaCol.Elimina(16);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (SecondaCol.cercaIndice(9) == true) {
						Clear(Black);
						SecondaCol.Elimina(9);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (SecondaCol.cercaIndice(2) == true) {
						Clear(Black);
						SecondaCol.Elimina(2);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
				}
				else if (TerzaCol.GetInvasore(24).GetX() - 25 < xColpo && xColpo < TerzaCol.GetInvasore(24).GetX() - 10) {
					if (TerzaCol.cercaIndice(24) == true) {
						Clear(Black);
						TerzaCol.Elimina(24);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (TerzaCol.cercaIndice(17) == true) {
						Clear(Black);
						TerzaCol.Elimina(17);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (TerzaCol.cercaIndice(10) == true) {
						Clear(Black);
						TerzaCol.Elimina(10);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (TerzaCol.cercaIndice(3) == true) {
						Clear(Black);
						TerzaCol.Elimina(3);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
				}
				else if (QuartaCol.GetInvasore(25).GetX() - 25 < xColpo && xColpo < QuartaCol.GetInvasore(25).GetX() - 10) {
					if (QuartaCol.cercaIndice(25) == true) {
						Clear(Black);
						QuartaCol.Elimina(25);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (QuartaCol.cercaIndice(18) == true) {
						Clear(Black);
						QuartaCol.Elimina(18);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (QuartaCol.cercaIndice(11) == true) {
						Clear(Black);
						QuartaCol.Elimina(11);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (QuartaCol.cercaIndice(4) == true) {
						Clear(Black);
						QuartaCol.Elimina(4);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
				}
				else if (QuintaCol.GetInvasore(26).GetX() - 25 < xColpo && xColpo < QuintaCol.GetInvasore(26).GetX() - 10) {
					if (QuintaCol.cercaIndice(26) == true) {
						Clear(Black);
						QuintaCol.Elimina(26);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (QuintaCol.cercaIndice(19) == true) {
						Clear(Black);
						QuintaCol.Elimina(19);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (QuintaCol.cercaIndice(12) == true) {
						Clear(Black);
						QuintaCol.Elimina(12);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (QuintaCol.cercaIndice(5) == true) {
						Clear(Black);
						QuintaCol.Elimina(5);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
				}
				else if (SestaCol.GetInvasore(27).GetX() - 25 < xColpo && xColpo < SestaCol.GetInvasore(27).GetX() - 10) {
					if (SestaCol.cercaIndice(27) == true) {
						Clear(Black);
						SestaCol.Elimina(27);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (SestaCol.cercaIndice(20) == true) {
						Clear(Black);
						SestaCol.Elimina(20);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (SestaCol.cercaIndice(13) == true) {
						Clear(Black);
						SestaCol.Elimina(13);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
					else if (SestaCol.cercaIndice(6) == true) {
						Clear(Black);
						SestaCol.Elimina(6);
						PrimaCol.DisegnaColonna();
						SecondaCol.DisegnaColonna();
						TerzaCol.DisegnaColonna();
						QuartaCol.DisegnaColonna();
						QuintaCol.DisegnaColonna();
						SestaCol.DisegnaColonna();
						Ost1.disegnaOstacolo(xOst1, yOst);
						Ost2.disegnaOstacolo(xOst2, yOst);
						Ost3.disegnaOstacolo(xOst3, yOst);
						Ost4.disegnaOstacolo(xOst4, yOst);
						Player.disegnaGiocatoreSP();
						Schermata.disegnaPuntiVite();
					}
				}
			}
			int InvViviPrimac = PrimaCol.GetnInvasoriVivi();
			int InvViviSecondac = SecondaCol.GetnInvasoriVivi();
			int InvViviTerzac = TerzaCol.GetnInvasoriVivi();
			int InvViviQuartac = QuartaCol.GetnInvasoriVivi();
			int InvViviQuintac = QuintaCol.GetnInvasoriVivi();
			int InvViviSestac = SestaCol.GetnInvasoriVivi();
			int ViviTot = InvViviPrimac + InvViviSecondac + InvViviTerzac + InvViviQuartac + InvViviQuintac + InvViviSestac;
			if (ViviTot == 0) {
				Schermata.vittoria();
			}
		}
		if (LeftMousePressed() == true) {
			spostamento = Player.MuoviSinistra();
			Player.disegnaGiocatore(spostamento, YPlayer);
			Ost1.disegnaOstacolo(xOst1, yOst);
			Ost2.disegnaOstacolo(xOst2, yOst);
			Ost3.disegnaOstacolo(xOst3, yOst);
			Ost4.disegnaOstacolo(xOst4, yOst);
			Schermata.disegnaPuntiVite();
			PrimaCol.DisegnaColonna();
			SecondaCol.DisegnaColonna();
			TerzaCol.DisegnaColonna();
			QuartaCol.DisegnaColonna();
			QuintaCol.DisegnaColonna();
			SestaCol.DisegnaColonna();
			int randomInv = 1 + rand() % 27;
			if (InvasoriVivi.Cerca(randomInv) == true) {
				Invasore InvasoreScelto = InvasoriVivi.GetInvasore(randomInv);
				int XPlayer = Player.GetX();
				viteOst1 = Ost1.getViteOst();
				viteOst2 = Ost2.getViteOst();
				viteOst3 = Ost3.getViteOst();
				viteOst4 = Ost4.getViteOst();
				bool PlayerColpito = InvasoreScelto.SparaColpo(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
				if (OstacoloColpito == 1) {
					Ost1.DiminuisciViteOstacolo();
				}
				if (OstacoloColpito == 2) {
					Ost2.DiminuisciViteOstacolo();
				}
				if (OstacoloColpito == 3) {
					Ost3.DiminuisciViteOstacolo();
				}
				if (OstacoloColpito == 4) {
					Ost4.DiminuisciViteOstacolo();
				}
				OstacoloColpito = 0;
				if (PlayerColpito == true) {
					Schermata.DiminuisciVite();
				}
			}
		}
		if (RightMousePressed() == true) {
			spostamento = Player.MuoviDestra();
			Player.disegnaGiocatore(spostamento, YPlayer);
			Ost1.disegnaOstacolo(xOst1, yOst);
			Ost2.disegnaOstacolo(xOst2, yOst);
			Ost3.disegnaOstacolo(xOst3, yOst);
			Ost4.disegnaOstacolo(xOst4, yOst);
			Schermata.disegnaPuntiVite();
			PrimaCol.DisegnaColonna();
			SecondaCol.DisegnaColonna();
			TerzaCol.DisegnaColonna();
			QuartaCol.DisegnaColonna();
			QuintaCol.DisegnaColonna();
			SestaCol.DisegnaColonna();
			int randomInv = 1 + rand() % 27;
			if (InvasoriVivi.Cerca(randomInv) == true) {
				Invasore InvasoreScelto = InvasoriVivi.GetInvasore(randomInv);
				int XPlayer = Player.GetX();
				viteOst1 = Ost1.getViteOst();
				viteOst2 = Ost2.getViteOst();
				viteOst3 = Ost3.getViteOst();
				viteOst4 = Ost4.getViteOst();
				bool PlayerColpito = InvasoreScelto.SparaColpo(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
				if (OstacoloColpito == 1) {
					Ost1.DiminuisciViteOstacolo();
				}
				if (OstacoloColpito == 2) {
					Ost2.DiminuisciViteOstacolo();
				}
				if (OstacoloColpito == 3) {
					Ost3.DiminuisciViteOstacolo();
				}
				if (OstacoloColpito == 4) {
					Ost4.DiminuisciViteOstacolo();
				}
				OstacoloColpito = 0;
				if (PlayerColpito == true) {
					Schermata.DiminuisciVite();
				}
			}
		}
		if (alternaDxSx == true) {
			while (SestaCol.ControllaXDx() == false) {
				key = LastKey();
				if (key == ' ') {
					viteOst1 = Ost1.getViteOst();
					viteOst2 = Ost2.getViteOst();
					viteOst3 = Ost3.getViteOst();
					viteOst4 = Ost4.getViteOst();
					int OstacoloDanneggiato = Player.SparaColpo(viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloDanneggiato == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					else if (OstacoloDanneggiato == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					else if (OstacoloDanneggiato == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					else if (OstacoloDanneggiato == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					else {
						int xColpo = Player.GetX();
						if (PrimaCol.GetInvasore(22).GetX() - 25 < xColpo && xColpo < PrimaCol.GetInvasore(22).GetX() - 10) {
							if (PrimaCol.cercaIndice(22) == true) {
								Clear(Black);
								PrimaCol.Elimina(22);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (PrimaCol.cercaIndice(15) == true) {
								Clear(Black);
								PrimaCol.Elimina(15);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (PrimaCol.cercaIndice(8) == true) {
								Clear(Black);
								PrimaCol.Elimina(8);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (PrimaCol.cercaIndice(1) == true) {
								Clear(Black);
								PrimaCol.Elimina(1);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (SecondaCol.GetInvasore(23).GetX() - 25 < xColpo && xColpo < SecondaCol.GetInvasore(23).GetX() - 10) {
							if (SecondaCol.cercaIndice(23) == true) {
								Clear(Black);
								SecondaCol.Elimina(23);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SecondaCol.cercaIndice(16) == true) {
								Clear(Black);
								SecondaCol.Elimina(16);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SecondaCol.cercaIndice(9) == true) {
								Clear(Black);
								SecondaCol.Elimina(9);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SecondaCol.cercaIndice(2) == true) {
								Clear(Black);
								SecondaCol.Elimina(2);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (TerzaCol.GetInvasore(24).GetX() - 25 < xColpo && xColpo < TerzaCol.GetInvasore(24).GetX() - 10) {
							if (TerzaCol.cercaIndice(24) == true) {
								Clear(Black);
								TerzaCol.Elimina(24);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (TerzaCol.cercaIndice(17) == true) {
								Clear(Black);
								TerzaCol.Elimina(17);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (TerzaCol.cercaIndice(10) == true) {
								Clear(Black);
								TerzaCol.Elimina(10);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (TerzaCol.cercaIndice(3) == true) {
								Clear(Black);
								TerzaCol.Elimina(3);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (QuartaCol.GetInvasore(25).GetX() - 25 < xColpo && xColpo < QuartaCol.GetInvasore(25).GetX() - 10) {
							if (QuartaCol.cercaIndice(25) == true) {
								Clear(Black);
								QuartaCol.Elimina(25);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuartaCol.cercaIndice(18) == true) {
								Clear(Black);
								QuartaCol.Elimina(18);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuartaCol.cercaIndice(11) == true) {
								Clear(Black);
								QuartaCol.Elimina(11);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuartaCol.cercaIndice(4) == true) {
								Clear(Black);
								QuartaCol.Elimina(4);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (QuintaCol.GetInvasore(26).GetX() - 25 < xColpo && xColpo < QuintaCol.GetInvasore(26).GetX() - 10) {
							if (QuintaCol.cercaIndice(26) == true) {
								Clear(Black);
								QuintaCol.Elimina(26);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuintaCol.cercaIndice(19) == true) {
								Clear(Black);
								QuintaCol.Elimina(19);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuintaCol.cercaIndice(12) == true) {
								Clear(Black);
								QuintaCol.Elimina(12);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuintaCol.cercaIndice(5) == true) {
								Clear(Black);
								QuintaCol.Elimina(5);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (SestaCol.GetInvasore(27).GetX() - 25 < xColpo && xColpo < SestaCol.GetInvasore(27).GetX() - 10) {
							if (SestaCol.cercaIndice(27) == true) {
								Clear(Black);
								SestaCol.Elimina(27);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SestaCol.cercaIndice(20) == true) {
								Clear(Black);
								SestaCol.Elimina(20);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SestaCol.cercaIndice(13) == true) {
								Clear(Black);
								SestaCol.Elimina(13);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SestaCol.cercaIndice(6) == true) {
								Clear(Black);
								SestaCol.Elimina(6);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
					}
					int InvViviPrimac = PrimaCol.GetnInvasoriVivi();
					int InvViviSecondac = SecondaCol.GetnInvasoriVivi();
					int InvViviTerzac = TerzaCol.GetnInvasoriVivi();
					int InvViviQuartac = QuartaCol.GetnInvasoriVivi();
					int InvViviQuintac = QuintaCol.GetnInvasoriVivi();
					int InvViviSestac = SestaCol.GetnInvasoriVivi();
					int ViviTot = InvViviPrimac + InvViviSecondac + InvViviTerzac + InvViviQuartac + InvViviQuintac + InvViviSestac;
					if (ViviTot == 0) {
						Schermata.vittoria();
					}
				}
				if (LeftMousePressed() == true) {
					spostamento = Player.MuoviSinistra();
					Player.disegnaGiocatore(spostamento, YPlayer);
					Ost1.disegnaOstacolo(xOst1, yOst);
					Ost2.disegnaOstacolo(xOst2, yOst);
					Ost3.disegnaOstacolo(xOst3, yOst);
					Ost4.disegnaOstacolo(xOst4, yOst);
					Schermata.disegnaPuntiVite();
					PrimaCol.DisegnaColonna();
					SecondaCol.DisegnaColonna();
					TerzaCol.DisegnaColonna();
					QuartaCol.DisegnaColonna();
					QuintaCol.DisegnaColonna();
					SestaCol.DisegnaColonna();
					int randomInv = 1 + rand() % 27;
					if (InvasoriVivi.Cerca(randomInv) == true) {
						Invasore InvasoreScelto = InvasoriVivi.GetInvasore(randomInv);
						int XPlayer = Player.GetX();
						viteOst1 = Ost1.getViteOst();
						viteOst2 = Ost2.getViteOst();
						viteOst3 = Ost3.getViteOst();
						viteOst4 = Ost4.getViteOst();
						bool PlayerColpito = InvasoreScelto.SparaColpo(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
						if (OstacoloColpito == 1) {
							Ost1.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 2) {
							Ost2.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 3) {
							Ost3.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 4) {
							Ost4.DiminuisciViteOstacolo();
						}
						OstacoloColpito = 0;
						if (PlayerColpito == true) {
							Schermata.DiminuisciVite();
						}
					}
				}
				if (RightMousePressed() == true) {
					spostamento = Player.MuoviDestra();
					Player.disegnaGiocatore(spostamento, YPlayer);
					Ost1.disegnaOstacolo(xOst1, yOst);
					Ost2.disegnaOstacolo(xOst2, yOst);
					Ost3.disegnaOstacolo(xOst3, yOst);
					Ost4.disegnaOstacolo(xOst4, yOst);
					Schermata.disegnaPuntiVite();
					PrimaCol.DisegnaColonna();
					SecondaCol.DisegnaColonna();
					TerzaCol.DisegnaColonna();
					QuartaCol.DisegnaColonna();
					QuintaCol.DisegnaColonna();
					SestaCol.DisegnaColonna();
					int randomInv = 1 + rand() % 27;
					if (InvasoriVivi.Cerca(randomInv) == true) {
						Invasore InvasoreScelto = InvasoriVivi.GetInvasore(randomInv);
						int XPlayer = Player.GetX();
						viteOst1 = Ost1.getViteOst();
						viteOst2 = Ost2.getViteOst();
						viteOst3 = Ost3.getViteOst();
						viteOst4 = Ost4.getViteOst();
						bool PlayerColpito = InvasoreScelto.SparaColpo(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
						if (OstacoloColpito == 1) {
							Ost1.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 2) {
							Ost2.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 3) {
							Ost3.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 4) {
							Ost4.DiminuisciViteOstacolo();
						}
						OstacoloColpito = 0;
						if (PlayerColpito == true) {
							Schermata.DiminuisciVite();
						}
					}
				}
				Player.disegnaGiocatoreSP();
				Ost1.disegnaOstacolo(xOst1, yOst);
				Ost2.disegnaOstacolo(xOst2, yOst);
				Ost3.disegnaOstacolo(xOst3, yOst);
				Ost4.disegnaOstacolo(xOst4, yOst);
				Schermata.disegnaPuntiVite();
				PrimaCol.MuoviInvasoriDx();
				SecondaCol.MuoviInvasoriDx();
				TerzaCol.MuoviInvasoriDx();
				QuartaCol.MuoviInvasoriDx();
				QuintaCol.MuoviInvasoriDx();
				SestaCol.MuoviInvasoriDx();
				PrimaCol.DisegnaColonna();
				SecondaCol.DisegnaColonna();
				TerzaCol.DisegnaColonna();
				QuartaCol.DisegnaColonna();
				QuintaCol.DisegnaColonna();
				SestaCol.DisegnaColonna();
				Wait(100);
			}
		}
		else {
			while (PrimaCol.ControllaXSx() == false) {
				key = LastKey();
				if (key == ' ') {
					viteOst1 = Ost1.getViteOst();
					viteOst2 = Ost2.getViteOst();
					viteOst3 = Ost3.getViteOst();
					viteOst4 = Ost4.getViteOst();
					int OstacoloDanneggiato = Player.SparaColpo(viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloDanneggiato == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					else if (OstacoloDanneggiato == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					else if (OstacoloDanneggiato == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					else if (OstacoloDanneggiato == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					else {
						int xColpo = Player.GetX();
						if (PrimaCol.GetInvasore(22).GetX() - 25 < xColpo && xColpo < PrimaCol.GetInvasore(22).GetX() - 10) {
							if (PrimaCol.cercaIndice(22) == true) {
								Clear(Black);
								PrimaCol.Elimina(22);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (PrimaCol.cercaIndice(15) == true) {
								Clear(Black);
								PrimaCol.Elimina(15);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (PrimaCol.cercaIndice(8) == true) {
								Clear(Black);
								PrimaCol.Elimina(8);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (PrimaCol.cercaIndice(1) == true) {
								Clear(Black);
								PrimaCol.Elimina(1);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (SecondaCol.GetInvasore(23).GetX() - 25 < xColpo && xColpo < SecondaCol.GetInvasore(23).GetX() - 10) {
							if (SecondaCol.cercaIndice(23) == true) {
								Clear(Black);
								SecondaCol.Elimina(23);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SecondaCol.cercaIndice(16) == true) {
								Clear(Black);
								SecondaCol.Elimina(16);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SecondaCol.cercaIndice(9) == true) {
								Clear(Black);
								SecondaCol.Elimina(9);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SecondaCol.cercaIndice(2) == true) {
								Clear(Black);
								SecondaCol.Elimina(2);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (TerzaCol.GetInvasore(24).GetX() - 25 < xColpo && xColpo < TerzaCol.GetInvasore(24).GetX() - 10) {
							if (TerzaCol.cercaIndice(24) == true) {
								Clear(Black);
								TerzaCol.Elimina(24);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (TerzaCol.cercaIndice(17) == true) {
								Clear(Black);
								TerzaCol.Elimina(17);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (TerzaCol.cercaIndice(10) == true) {
								Clear(Black);
								TerzaCol.Elimina(10);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (TerzaCol.cercaIndice(3) == true) {
								Clear(Black);
								TerzaCol.Elimina(3);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (QuartaCol.GetInvasore(25).GetX() - 25 < xColpo && xColpo < QuartaCol.GetInvasore(25).GetX() - 10) {
							if (QuartaCol.cercaIndice(25) == true) {
								Clear(Black);
								QuartaCol.Elimina(25);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuartaCol.cercaIndice(18) == true) {
								Clear(Black);
								QuartaCol.Elimina(18);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuartaCol.cercaIndice(11) == true) {
								Clear(Black);
								QuartaCol.Elimina(11);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuartaCol.cercaIndice(4) == true) {
								Clear(Black);
								QuartaCol.Elimina(4);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (QuintaCol.GetInvasore(26).GetX() - 25 < xColpo && xColpo < QuintaCol.GetInvasore(26).GetX() - 10) {
							if (QuintaCol.cercaIndice(26) == true) {
								Clear(Black);
								QuintaCol.Elimina(26);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuintaCol.cercaIndice(19) == true) {
								Clear(Black);
								QuintaCol.Elimina(19);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuintaCol.cercaIndice(12) == true) {
								Clear(Black);
								QuintaCol.Elimina(12);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (QuintaCol.cercaIndice(5) == true) {
								Clear(Black);
								QuintaCol.Elimina(5);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
						else if (SestaCol.GetInvasore(27).GetX() - 25 < xColpo && xColpo < SestaCol.GetInvasore(27).GetX() - 10) {
							if (SestaCol.cercaIndice(27) == true) {
								Clear(Black);
								SestaCol.Elimina(27);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SestaCol.cercaIndice(20) == true) {
								Clear(Black);
								SestaCol.Elimina(20);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SestaCol.cercaIndice(13) == true) {
								Clear(Black);
								SestaCol.Elimina(13);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
							else if (SestaCol.cercaIndice(6) == true) {
								Clear(Black);
								SestaCol.Elimina(6);
								PrimaCol.DisegnaColonna();
								SecondaCol.DisegnaColonna();
								TerzaCol.DisegnaColonna();
								QuartaCol.DisegnaColonna();
								QuintaCol.DisegnaColonna();
								SestaCol.DisegnaColonna();
								Ost1.disegnaOstacolo(xOst1, yOst);
								Ost2.disegnaOstacolo(xOst2, yOst);
								Ost3.disegnaOstacolo(xOst3, yOst);
								Ost4.disegnaOstacolo(xOst4, yOst);
								Player.disegnaGiocatoreSP();
								Schermata.disegnaPuntiVite();
							}
						}
					}
					int InvViviPrimac = PrimaCol.GetnInvasoriVivi();
					int InvViviSecondac = SecondaCol.GetnInvasoriVivi();
					int InvViviTerzac = TerzaCol.GetnInvasoriVivi();
					int InvViviQuartac = QuartaCol.GetnInvasoriVivi();
					int InvViviQuintac = QuintaCol.GetnInvasoriVivi();
					int InvViviSestac = SestaCol.GetnInvasoriVivi();
					int ViviTot = InvViviPrimac + InvViviSecondac + InvViviTerzac + InvViviQuartac + InvViviQuintac + InvViviSestac;
					if (ViviTot == 0) {
						Schermata.vittoria();
					}
				}
				if (LeftMousePressed() == true) {
					spostamento = Player.MuoviSinistra();
					Player.disegnaGiocatore(spostamento, YPlayer);
					Ost1.disegnaOstacolo(xOst1, yOst);
					Ost2.disegnaOstacolo(xOst2, yOst);
					Ost3.disegnaOstacolo(xOst3, yOst);
					Ost4.disegnaOstacolo(xOst4, yOst);
					Schermata.disegnaPuntiVite();
					PrimaCol.DisegnaColonna();
					SecondaCol.DisegnaColonna();
					TerzaCol.DisegnaColonna();
					QuartaCol.DisegnaColonna();
					QuintaCol.DisegnaColonna();
					SestaCol.DisegnaColonna();
					int randomInv = 1 + rand() % 27;
					if (InvasoriVivi.Cerca(randomInv) == true) {
						Invasore InvasoreScelto = InvasoriVivi.GetInvasore(randomInv);
						int XPlayer = Player.GetX();
						viteOst1 = Ost1.getViteOst();
						viteOst2 = Ost2.getViteOst();
						viteOst3 = Ost3.getViteOst();
						viteOst4 = Ost4.getViteOst();
						bool PlayerColpito = InvasoreScelto.SparaColpo(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
						if (OstacoloColpito == 1) {
							Ost1.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 2) {
							Ost2.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 3) {
							Ost3.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 4) {
							Ost4.DiminuisciViteOstacolo();
						}
						OstacoloColpito = 0;
						if (PlayerColpito == true) {
							Schermata.DiminuisciVite();
						}
					}
				}
				if (RightMousePressed() == true) {
					spostamento = Player.MuoviDestra();
					Player.disegnaGiocatore(spostamento, YPlayer);
					Ost1.disegnaOstacolo(xOst1, yOst);
					Ost2.disegnaOstacolo(xOst2, yOst);
					Ost3.disegnaOstacolo(xOst3, yOst);
					Ost4.disegnaOstacolo(xOst4, yOst);
					Schermata.disegnaPuntiVite();
					PrimaCol.DisegnaColonna();
					SecondaCol.DisegnaColonna();
					TerzaCol.DisegnaColonna();
					QuartaCol.DisegnaColonna();
					QuintaCol.DisegnaColonna();
					SestaCol.DisegnaColonna();
					int randomInv = 1 + rand() % 27;
					if (InvasoriVivi.Cerca(randomInv) == true) {
						Invasore InvasoreScelto = InvasoriVivi.GetInvasore(randomInv);
						int XPlayer = Player.GetX();
						viteOst1 = Ost1.getViteOst();
						viteOst2 = Ost2.getViteOst();
						viteOst3 = Ost3.getViteOst();
						viteOst4 = Ost4.getViteOst();
						bool PlayerColpito = InvasoreScelto.SparaColpo(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
						if (OstacoloColpito == 1) {
							Ost1.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 2) {
							Ost2.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 3) {
							Ost3.DiminuisciViteOstacolo();
						}
						if (OstacoloColpito == 4) {
							Ost4.DiminuisciViteOstacolo();
						}
						OstacoloColpito = 0;
						if (PlayerColpito == true) {
							Schermata.DiminuisciVite();
						}
					}
				}
				Player.disegnaGiocatoreSP();
				Ost1.disegnaOstacolo(xOst1, yOst);
				Ost2.disegnaOstacolo(xOst2, yOst);
				Ost3.disegnaOstacolo(xOst3, yOst);
				Ost4.disegnaOstacolo(xOst4, yOst);
				Schermata.disegnaPuntiVite();
				PrimaCol.MuoviInvasoriSx();
				SecondaCol.MuoviInvasoriSx();
				TerzaCol.MuoviInvasoriSx();
				QuartaCol.MuoviInvasoriSx();
				QuintaCol.MuoviInvasoriSx();
				SestaCol.MuoviInvasoriSx();
				PrimaCol.DisegnaColonna();
				SecondaCol.DisegnaColonna();
				TerzaCol.DisegnaColonna();
				QuartaCol.DisegnaColonna();
				QuintaCol.DisegnaColonna();
				SestaCol.DisegnaColonna();
				Wait(100);
			}
		}
		trovato = false;
		while (trovato == false) {
			int XPlayer = Player.GetX();
			viteOst1 = Ost1.getViteOst();
			viteOst2 = Ost2.getViteOst();
			viteOst3 = Ost3.getViteOst();
			viteOst4 = Ost4.getViteOst();
			int randomColonna = 1 + rand() % 6;
			if (randomColonna == 1) {
				if (PrimaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = PrimaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 2) {
				if (SecondaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = SecondaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 3) {
				if (TerzaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = TerzaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 4) {
				if (QuartaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = QuartaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 5) {
				if (QuintaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = QuintaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
			else if (randomColonna == 6) {
				if (SestaCol.GetnInvasoriVivi() != 0) {
					bool PlayerColpito = SestaCol.SparaRandomInvasore(XPlayer, OstacoloColpito, viteOst1, viteOst2, viteOst3, viteOst4);
					if (OstacoloColpito == 1) {
						Ost1.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 2) {
						Ost2.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 3) {
						Ost3.DiminuisciViteOstacolo();
					}
					if (OstacoloColpito == 4) {
						Ost4.DiminuisciViteOstacolo();
					}
					OstacoloColpito = 0;
					if (PlayerColpito == true) {
						Schermata.DiminuisciVite();
					}
					trovato = true;
				}
				else {
					randomColonna = 1 + rand() % 5;
				}
			}
		}
		if (Schermata.GetVite() == 0) {
			Schermata.Sconfitta();
		}
		int PuntiPrimaC = PrimaCol.GetPuntiColonna();
		int PuntiSecondaC = SecondaCol.GetPuntiColonna();
		int PuntiTerzaC = TerzaCol.GetPuntiColonna();
		int PuntiQuartaC = QuartaCol.GetPuntiColonna();
		int PuntiQuintaC = QuintaCol.GetPuntiColonna();
		int PuntiSestaC = SestaCol.GetPuntiColonna();
		int PuntiTot = PuntiPrimaC + PuntiSecondaC + PuntiTerzaC + PuntiQuartaC + PuntiQuintaC + PuntiSestaC;
		Schermata.SetPunti(PuntiTot);
		alternaDxSx = !alternaDxSx;
	}
}

