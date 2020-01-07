#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab_avanzados.h"
int main(){
	/*
	Se abre el archivo y se llama a la función bruteForce
	NO ES NECESARIO LIBERAR MEMORIA, DEBIDO A QUE SE HACE USO DE UN ARREGLO ESTÁTICO, QUE SOLO ALMACENA
	LA MEJOR COMBINACIÓN
	*/
	char cadena1[500];
	char dato[32];
	char dato2[32];
	int cont = 0;
	int cantidad, cantInicial;
	FILE* archivo;
		printf("Ingrese el nombre del archivo: \n");
		scanf("%s",cadena1);
		archivo=fopen(cadena1,"r");
	if(archivo==NULL){ /*Si el archivo no abre, el programa termina*/
		printf("Fallo la apertura del archivo");
	}
	fgets(cadena1,200,archivo);
	sscanf(cadena1,"%s%s",dato,dato2);
	cantInicial = atoi(dato);
	fgets(cadena1,200,archivo);
	sscanf(cadena1,"%s%s",dato,dato2);
	cantidad = atoi(dato);
	int cadena[cantidad];
	int utilidad[cantidad];

	while (!feof(archivo)){ 		
				fgets(cadena1,200,archivo);
				sscanf(cadena1,"%s%s",dato,dato2);
				cadena[cont] = atoi(dato);
				utilidad[cont] = atoi(dato2);
				cont++;
			}
		fclose (archivo);


	bruteForce(cantidad,cantInicial,cadena,utilidad);



	return 0;
}