#include"header.h"

// argc ist die anzahl der sachen die mitgegeben werden und argv[] ist halt der array (als string) wo die werte drinne sind.
int main(int argc, char *argv[])
{
	int wahl = 5, fehler = 0;
	char eingabe[GROESSE];
	komplexe_Zahl zahlen1, zahlen2, ergebnis;
	
	fehler = konsole_pruefen(argc, argv, &zahlen1, &zahlen2);

	if (fehler == 0)
	{
		// argv[0] ist immer der pfad darum immer überspringen. heißt der array beginnt von 1.
		if (strcmp(argv[3], "+") == 0)
		{
			// bei +
			wahl = 1;
		}
		if (strcmp(argv[3], "-") == 0)
		{
			// bei -
			wahl = 2;
		}
		if (strcmp(argv[3], "*") == 0)
		{
			// bei *
			wahl = 3;
		}
		if (strcmp(argv[3], "/") == 0)
		{
			// bei /
			wahl = 4;
		}
		// wählt wahl
		switch (wahl)
		{
		case 1:
			// funktionsaufruf für addition
			addition(&zahlen1, &zahlen2, &ergebnis);
			printf("ergebnis realteil:\t%.2f\nergebnis imaginaerteil:\t%.2f\n", ergebnis.realteil, ergebnis.imaginarteil);
			break;
		case 2:
			// funktionsaufruf für -
			subtraktion(&zahlen1, &zahlen2, &ergebnis);
			printf("ergebnis realteil:\t%.2f\nergebnis imaginaerteil:\t%.2f\n", ergebnis.realteil, ergebnis.imaginarteil);
			break;
		case 3:
			// funktionsaufruf für *
			multiplikation(&zahlen1, &zahlen2, &ergebnis);
			printf("ergebnis realteil:\t%.2f\nergebnis imaginaerteil:\t%.2f\n", ergebnis.realteil, ergebnis.imaginarteil);
			break;
		case 4:
			// funktionsaufruf für /
			fehler = division(&zahlen1, &zahlen2, &ergebnis);
			if (fehler != 1)
			{
				printf("ergebnis realteil:\t%.4f\nergebnis imaginaerteil:\t%.4f\n", ergebnis.realteil, ergebnis.imaginarteil);
			}
			else
			{
				printf("Nenner darf nciht 0 sein.\n");
			}
			break;
		case 5:
			printf("programm wird beendet.\n");
			break;
		default:
			printf("fehler!!!\n\n");
		}
		getchar();
		system("cls");
	}
	return 0;
}