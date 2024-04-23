#include"header.h"
// argc ist anzahl der werte die mitgegeben werden, argv sind die werte als string gespeichert 
int konsole_pruefen(int argc, char *argv[], komplexe_Zahl *zahlen1, komplexe_Zahl *zahlen2)
{
	// initialisierungen
	int ok = 0, index = 0;
	int fehler = 0;
	if (argc != 6)
	{
		// wenn argc nciht genug werte hat
		fehler++;
	}
	else
	{
		// ansonsten ist alles richtig und er überprüft die einzelnen werte
		for (index = 1; index < argc; index++)
		{
			// wenn + - / * überprüft werden sollen braucht er das nciht weil er das in der main shcon amcht
			if (index == 3)
			{
				;
			}
			else
			{
				// wenn der string ungültig ist
				if (pruefen_gueltig(argv[index]) == 0)
				{
					fehler++;
				}
			}
		}
	}
	if (fehler == 0)
	{
		// alle zahlen werden umgewandelt und in die jeweiligen struktur sachen zzurückgegeben
		zahlen1->realteil = atof(argv[1]);
		zahlen1->imaginarteil = atof(argv[2]);
		zahlen2->realteil = atof(argv[4]);
		zahlen2->imaginarteil = atof(argv[5]);
		// ok = 0 ist für richtig
		ok = 0;
	}
	else
	{
		// ok = 1 ist für falsch. also fehelr ist passiert
		ok = 1;
	}
	return ok;
}
// addition formeln
void addition(komplexe_Zahl *zahlen1, komplexe_Zahl *zahlen2, komplexe_Zahl *ergebnis)
{
	// 1.te re + 2.te re und 1.te im + 2.te im
	ergebnis->realteil = zahlen1->realteil + zahlen2->realteil;
	ergebnis->imaginarteil = zahlen1->imaginarteil + zahlen2->imaginarteil;
}
// minus
void subtraktion(komplexe_Zahl *zahlen1, komplexe_Zahl *zahlen2, komplexe_Zahl *ergebnis)
{
	// erste. re - 2.te re und erste. im - 2.te im
	ergebnis->realteil = zahlen1->realteil - zahlen2->realteil;
	ergebnis->imaginarteil = zahlen1->imaginarteil - zahlen2->imaginarteil;
}
// multiplikation
void multiplikation(komplexe_Zahl *zahlen1, komplexe_Zahl *zahlen2, komplexe_Zahl *ergebnis)
{
	// erste. re * 2.te re und das + erste im + 2.te im und das alles * -1
	ergebnis->realteil = zahlen1->realteil * zahlen2->realteil + ((zahlen1->imaginarteil * zahlen2->imaginarteil) * (-1));
	// erste re * 2.im im und das + erste. im * 2.te re
	ergebnis->imaginarteil = zahlen1->realteil * zahlen2->imaginarteil + (zahlen1->imaginarteil * zahlen2->realteil);
}
// division
int division(komplexe_Zahl *zahlen1, komplexe_Zahl *zahlen2, komplexe_Zahl *ergebnis)
{
	int fehler = 0;
	float nenner = 0.0;
	// überprüft ob nenner 0 ist weil durch 0 nciht teilbar ist
	nenner = zahlen2->realteil * zahlen2->realteil + (zahlen2->imaginarteil * zahlen2->imaginarteil);
	if (nenner != 0.0)
	{
		// formel für realteil bei division= (1.te re * 2.te re + (1.te im * 2.te im)) alles durch nenner.
		ergebnis->realteil = (zahlen1->realteil * zahlen2->realteil + (zahlen1->imaginarteil * zahlen2->imaginarteil)) / nenner;
		// formel für imaginärteil bei division= ((1.te re * 2.te im * -1) - (1.te im * 2.te re * -1)) / nenner.
		ergebnis->imaginarteil = ((zahlen2->imaginarteil * zahlen1->realteil) * (-1) - ((zahlen1->imaginarteil * zahlen2->realteil) * (-1))) / nenner;
		// fehler =0 setzen für true
		fehler = 0;
	}
	else
	{
		// ansonten gibt 1 zurück. wenn falsch
		fehler = 1;
	}
	return fehler;
}