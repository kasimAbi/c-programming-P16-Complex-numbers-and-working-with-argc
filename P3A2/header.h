#pragma once
#ifndef header_h
#define header_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define GROESSE 20

struct komplexe_Zahl
{
	float realteil;
	float imaginarteil;
};

int konsole_pruefen(int, char *[], komplexe_Zahl* , komplexe_Zahl*);
void addition(komplexe_Zahl*, komplexe_Zahl*, komplexe_Zahl*);
void subtraktion(komplexe_Zahl*, komplexe_Zahl*, komplexe_Zahl*);
void multiplikation(komplexe_Zahl*, komplexe_Zahl*, komplexe_Zahl*);
int division(komplexe_Zahl*, komplexe_Zahl*, komplexe_Zahl*);

int pruefen_ob_zahl(char[GROESSE]);
int pruefen_ob_zeichen(char[GROESSE]);
float pruefen_komma_zahl(char[GROESSE]);
int pruefen_gueltig(char[GROESSE]);

#endif // !header_h
