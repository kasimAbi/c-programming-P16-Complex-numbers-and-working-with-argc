#include"header.h"
// main
int main(void) 
{
	int wahl = 0, fehler = 0;
	char eingabe[GROESSE];
	komplexe_Zahl zahlen1, zahlen2, ergebnis;

	while (wahl != 5)
	{
		// zahlen eingeben
		printf("waehlen:\n (1) addition.\n (2) subtraktion.\n (3) multiplikation.\n (4) division.\n (5) programm beenden.\nwahl:\t");
		fgets(eingabe, GROESSE, stdin);
		wahl = pruefen_ob_zahl(eingabe);
		// überprüfen ob die zahl im gültigen bereich liegt damit man die werte eingibt
		if (wahl > 0 && wahl <= 4)
		{
			printf("\ngeben sie die ersten beiden zahlen ein:\n");
			eingeben(&zahlen1, wahl);
			printf("\ngeben sie die naechsten beiden zahlen ein:\n");
			eingeben(&zahlen2, wahl);
			printf("\n");
		}
		// wahl wählen
		switch (wahl)
		{
		case 1:
			addition(&zahlen1, &zahlen2, &ergebnis);
			printf("ergebnis realteil:\t%.2f\nergebnis imaginaerteil:\t%.2f\n", ergebnis.realteil, ergebnis.imaginarteil);
			break;
		case 2:
			subtraktion(&zahlen1, &zahlen2, &ergebnis);
			printf("ergebnis realteil:\t%.2f\nergebnis imaginaerteil:\t%.2f\n", ergebnis.realteil, ergebnis.imaginarteil);
			break;
		case 3:
			multiplikation(&zahlen1, &zahlen2, &ergebnis);
			printf("ergebnis realteil:\t%.2f\nergebnis imaginaerteil:\t%.2f\n", ergebnis.realteil, ergebnis.imaginarteil);
			break;
		case 4:
			fehler = division(&zahlen1, &zahlen2, &ergebnis);
			if (fehler != 1)
			{
				printf("ergebnis realteil:\t%.4f\nergebnis imaginaerteil:\t%.4f\n", ergebnis.realteil, ergebnis.imaginarteil);
			}
			else
			{
				printf("Nenner darf nciht 0 sein.\n");		// fehlermeldung
			}
			break;
		case 5:
			printf("programm wird beendet.\n");
			break;
		default:
			// ungütlige wahl
			printf("fehler!!!\n\n");
		}
		// programm zum stehen bringen
		fgets(eingabe, GROESSE, stdin);
		system("cls");
	}

	return 0;
}