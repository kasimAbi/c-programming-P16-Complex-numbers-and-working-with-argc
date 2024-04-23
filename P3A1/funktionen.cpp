#include"header.h"
// zahlen eingeben
void eingeben(komplexe_Zahl *zahl, int wahl)
{
	char eingabe[GROESSE];
	int ok = 0;
	while (ok == 0)
	{
		printf("realteil:\t");
		fgets(eingabe, GROESSE, stdin);
		// überprüfen ob die zahl kein buchstabe oder so ist
		ok = pruefen_gueltig(eingabe);
		if (ok == 1 || ok == 2)
		{
			ok = 0;
			zahl->realteil = atof(eingabe);
			while (ok == 0)
			{
				printf("imaginaerteil:\t");
				fgets(eingabe, GROESSE, stdin);
				ok = pruefen_gueltig(eingabe);
				if (ok == 1 || ok == 2)
				{
					zahl->imaginarteil = atof(eingabe);
				}
			}
		}
	}
}
void addition(komplexe_Zahl *zahlen1, komplexe_Zahl *zahlen2, komplexe_Zahl *ergebnis)
{
	ergebnis->realteil = zahlen1->realteil + zahlen2->realteil;
	ergebnis->imaginarteil = zahlen1->imaginarteil + zahlen2->imaginarteil;
}
void subtraktion(komplexe_Zahl *zahlen1, komplexe_Zahl *zahlen2, komplexe_Zahl *ergebnis)
{
	ergebnis->realteil = zahlen1->realteil - zahlen2->realteil;
	ergebnis->imaginarteil = zahlen1->imaginarteil - zahlen2->imaginarteil;
}
void multiplikation(komplexe_Zahl *zahlen1, komplexe_Zahl *zahlen2, komplexe_Zahl *ergebnis)
{
	ergebnis->realteil = zahlen1->realteil * zahlen2->realteil + ((zahlen1->imaginarteil * zahlen2->imaginarteil) * (-1));
	ergebnis->imaginarteil = zahlen1->realteil * zahlen2->imaginarteil + (zahlen1->imaginarteil * zahlen2->realteil);
}
int division(komplexe_Zahl *zahlen1, komplexe_Zahl *zahlen2, komplexe_Zahl *ergebnis)
{
	int fehler = 0;
	float nenner = 0.0;
	nenner = zahlen2->realteil * zahlen2->realteil + (zahlen2->imaginarteil * zahlen2->imaginarteil);
	if (nenner != 0.0)
	{
		ergebnis->realteil = (zahlen1->realteil * zahlen2->realteil + (zahlen1->imaginarteil * zahlen2->imaginarteil)) / nenner;
		ergebnis->imaginarteil = ((zahlen2->imaginarteil * zahlen1->realteil) * (-1) - ((zahlen1->imaginarteil * zahlen2->realteil) * (-1))) / nenner;
		fehler = 0;
	}
	else
	{
		fehler = 1;
	}
	return fehler;
}