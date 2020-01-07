#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int potencia(int base, int exponente);
void bruteForce(int cantidad, int cantInicial,int cadena[],int utilidad[]);
void escribir_archivo(int capital_usado, int utilidad_usada, int aux,int cadena[]);
void printCurrent(int cadena [], int cantidad, int utilidad, int capital);