#include "lab_avanzados.h"
int main(){
	/*
	Se abre el archivo y se llama a la función bruteForce
	*/
	char cadena1[500];
	char dato[32];
	char dato2[32];
	char dato3[32];
	int lineas = 0;
	int cont = 0;
	int cantidad, cantCiudades;
	FILE* archivo;
	printf("Ingrese el nombre del archivo: \n");
	scanf("%s",cadena1);
	archivo=fopen(cadena1,"r");
	if(archivo==NULL){ /*Si el archivo no abre, el programa termina*/
		printf("Fallo la apertura del archivo");
	}
	fgets(cadena1,200,archivo);
	cantCiudades = atoi(cadena1);
	while (!feof(archivo)){ 		
				fgets(cadena1,200,archivo);
				sscanf(cadena1,"%s%s%s",dato,dato2,dato3);
				lineas ++;
			}
	int ciudades[(lineas-1)*3];

	rewind(archivo);
	fgets(cadena1,200,archivo);
	sscanf(cadena1,"%s%s%s",dato,dato2,dato3);
	while (!feof(archivo)){ 		
				fgets(cadena1,200,archivo);
				sscanf(cadena1,"%s%s%s",dato,dato2,dato3);
				ciudades[cont] = atoi(dato);
				ciudades[cont+1] = atoi(dato2);
				ciudades[cont+2] = atoi(dato3);
				cont = cont+3;
			}
		fclose (archivo);
		//Se llama a la función generar matriz

	generarMatriz(cantCiudades,ciudades, lineas);


	return 0;
}