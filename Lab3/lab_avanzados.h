#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void generarMatriz(int cantCiudades, int ciudades[], int lineas);
int * backTracking(int i,int * camino, int ** matriz, int cantCiudades, int * visitados, int * resultado);
bool validar(int * visitados, int cantCiudades);
int calcularCamino(int * camino, int ** matriz, int cantCiudades);
int * agregarCamino(int k,int * camino, int cantCiudades);
int * eliminarCamino(int k, int * camino, int cantCiudades);
void escribir_archivo(int * solucion, int cantCiudades);
void printCurrent(int * camino, int costo, int estado,int cantCiudades);
void liberarMemoria(int ** matriz, int cantCiudades);