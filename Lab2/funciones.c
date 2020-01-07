#include "lab_avanzados.h"
#define extern costoMejorCamino
int costoMejorCamino = 100000;
/* Entrada: 1) cantidad de ciudades que deben ser visitadas
            2) Lista que contiene los costos de ir de una ciudad a otra
            3) Cantidad de líneas que tiene el archivo de entrada

   Descripción: Se genera la matriz de adyacencia en base a la cantidad de ciudades que tiene el problema
   				y se llama a la función backtracking. Además se genera una lista que permite saber que ciudades
   				fueron visitadas (0 indica que no fueron visitadas y 1 que si)
   	Salida: La salida corresponde a un archivo de salida con el camino óptimo.
*/ 
void generarMatriz(int cantCiudades, int ciudades[], int lineas){
	int cantElementos = cantCiudades*3;
	int i = 0;
	int costo = 1000000;
	int j = 0;
	int **matrizAdyacencia; 
	matrizAdyacencia = (int **)malloc (cantCiudades*sizeof(int *));
	for (i=0;i<cantCiudades;i++)
		matrizAdyacencia[i] = (int *) malloc (cantCiudades*sizeof(int));
//Se llena la diagonal con -1
	while(j < cantCiudades){
		matrizAdyacencia[j][j] = -1;
		j++;
	}
//Visitados contiene la lista de caminos que fueron visitados
	int * visitados = (int *) malloc (cantCiudades*sizeof(int));
	int * camino = (int *) malloc (cantCiudades*sizeof(int));
	int * resultado = (int *) malloc (cantCiudades*sizeof(int));
	lineas--;
	j = 0;
	while(j<cantCiudades){
		visitados[j] = -1;
		camino[j] = -1;
		resultado[j] = -1;
		j = j+1;
	}i= 0;
//La matriz de adyacencia contiene los costos que tiene visitar cada uno de los caminos
//con la diagonal con -1	
	while(i<=lineas*3){
		matrizAdyacencia[ciudades[i]-1][ciudades[i+1]-1] = ciudades[i+2];
		matrizAdyacencia[ciudades[i+1]-1][ciudades[i]-1] = ciudades[i+2];
		i = i+3;		
}
	i = 0;	j = 0;
	for (int i = 0; i < cantCiudades; ++i){
		camino[0] = i;
		resultado = backTracking(i,camino,matrizAdyacencia,cantCiudades,visitados,resultado);
	}
	escribir_archivo(resultado, cantCiudades);
	//SE LIBERA LA MEMORIA
	free(visitados);
	free(camino);
	free(resultado);
	liberarMemoria(matrizAdyacencia,cantCiudades);

}
/* Entrada: La función backtracking recibe la matriz con los datos, la cantidad de ciudades, listas con los nodos
			visitados, el orden de los caminos y una variable para almacenar el resultado final.
   Descripción: La función recursiva  genera los caminos posibles y calcula su costo asociado, en caso de que al generar un camino este sobrepase el costo
   				del anterior, se descarta (se poda la rama) y se continúa con el resto. 
   Salida: La función retorna el camino que genera el menor costo.
*/
int * backTracking(int i,int * camino, int ** matriz, int cantCiudades, int * visitados, int * resultado){
		if(validar(camino,cantCiudades)){
			int costo = calcularCamino(camino,matriz,cantCiudades);
			if(costo < costoMejorCamino){
				costoMejorCamino = costo;
				for (int i = 0; i < cantCiudades; i++)
					resultado[i] = camino[i];
			 	return resultado;
			}
			else{
				return resultado;
			}
		}
		else{
			visitados[i] = 1;
			for(int k = 0; k < cantCiudades; k++){
				if(visitados[k] == -1){
					camino = agregarCamino(k,camino,cantCiudades);
					int costo2 = calcularCamino(camino,matriz,cantCiudades);
					if(costo2 < costoMejorCamino){
						printCurrent(camino,costo2,1,cantCiudades);
						resultado = backTracking(k,camino,matriz,cantCiudades,visitados,resultado);
					}
					else{
						printCurrent(camino,costo2,0,cantCiudades);
					}
					camino = eliminarCamino(k,camino,cantCiudades);
				}
			}
			visitados[i] = -1;
		}
		return resultado;
	}

/* Entrada: ingresa una lista con los nodos que fueron visitados y la cantidad de ciudades
   Salida: Entrega True o false (Si se visitaron todos los nodos o no)
*/
bool validar(int * visitados, int cantCiudades){
	int i = 0;
	while(i<cantCiudades){
		if(visitados[i]==-1){
			return false;
		}

		i++;
	}
	return true;
}
/* Entrada: lista con el camino, matriz con los costos y cantidad de ciudades
   Descripción: Se calcula el costo asociado al camino ingresado.
   Salida: Costo del camino.
*/
int calcularCamino(int * camino, int ** matriz, int cantCiudades){
	cantCiudades--;
	int costo = 0;
	for (int i = 0; i < cantCiudades ; i++){
		if(camino[i] != -1 && camino[i+1]!=-1){
			costo = costo + matriz[camino[i]][camino[i+1]];
		}
	}
	return costo;
}

/* Entrada: nodo que se desea agregar, camino recorrido y cantidad de ciudades
   Descripción: Se agrega el nodo al final del camino
   Salida: camino con el nuevo nodo
*/
int * agregarCamino(int k,int * camino, int cantCiudades){
	for(int i = 0; i < cantCiudades; i++){
		if(camino[i] == -1){
			camino[i] = k;
			return camino;
		}
	}
	return camino;
}
int * eliminarCamino(int k, int * camino, int cantCiudades){
	for(int i = 0; i < cantCiudades; i++){
		if(camino[i] == k){
			camino[i] = -1;
			return camino;
		}
	}
	return camino;
}

/* Escribir archivo escribe la solución en un archivo llamado "salida.txt", junto con su costo asociado*/
void escribir_archivo(int * solucion, int cantCiudades){
	FILE* archivo=fopen("salida.txt","w");
	fprintf(archivo, "%i\n", costoMejorCamino+2);
	fprintf(archivo, "0 -");
	for (int i = 0; i < cantCiudades; i++){
		fprintf(archivo, " %i -", solucion[i]+1);
	}
	fprintf(archivo, " 0");		
	fclose(archivo);
	printf("EL PROGRAMA HA FINALIZADO CON ÉXITO\n");
}

/* PrintCurrent entrega el camino que se ha recorrido, su costo asociado y si la solución es descartada por
sobrepasar el costo del camino anterior  
*/
void printCurrent(int * camino, int costo, int estado, int cantCiudades){
	#ifdef DEBUG
	printf("Camino: ");
	for (int l = 0; l < cantCiudades; l++){
		if(camino[l]!= -1)
			printf(" %i ",camino[l]+1);
				}
		printf("\n");
		printf("Costo: %i\n",costo );
		if(estado == 0) printf("DESCARTAR SOLUCIÓN \n");
	printf("Enter para continuar...\n");
	while(getchar()!= '\n');
	#endif
}

void liberarMemoria(int ** matriz, int cantCiudades){

	for (int i = 0; i < cantCiudades; i++)
	{
		free(matriz[i]);
	}
	free(matriz);
}


