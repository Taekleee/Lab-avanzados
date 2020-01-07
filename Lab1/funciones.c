#include "lab_avanzados.h"

/*ENTRADA: número base y exponente, para calcular la cantidad de combinaciones que serán generadas
  SALIDA: Potencia calculada
*/
int potencia(int base, int exponente){
	int valor = 1;
	while(exponente >1){
		valor = base*valor;
		exponente --;
	}
	return valor;
}
/********************FUNCIÓN PRINCIPAL DEL PROGRAMA********************/
/* ENTRADA: Cantidad = número de inversiones que serán ingresadas
			cantInicial = Dinero con el que cuenta la empresa para comprar inversiones
			cadena[] = lista estática que contiene los valores de las inversiones, los cuales serán ocupados para generar las combinaciones
			utilidad[] = Lista con la utilidad asociada a cada una de las inversiones, los índices de cadena y utilidad se relacionana
	SALIDA: Se escribe un archivo con los valores de la combinación que cuenta con la mayor utilidad con respecto a la cantidad inicial
	DESCRIPCIÓN: Se generan las combinaciones en base a una descomposición binaria. Si la utilidad de la combinación es mayor a la almacenada con 
				 con anterioridad y el costo de esas inversiones no supera al inicial, se almacena como nueva combinación. Cuando terminan las combinaciones
				 se ingresa la mejor a un archivo y el programa termina.
*/

void bruteForce(int cantidad, int cantInicial,int cadena[],int utilidad[]){
	int nodos = cantidad;
	cantidad = potencia(2,cantidad+1)-1 ;
	int combinacion, capitalUsado, aux, modulo,valor, capital;
	int utilMaxima = 0;
	int util = 0;	
	combinacion = 0; capitalUsado = 0;
	int combinaciones[cantidad]; int i; int iteracion = 0;
	while(cantidad>1 || iteracion < 2){
		i = 0;
		while(i < cantidad){
		    combinaciones[i] = 0;
		    i++;
		}
		aux = cantidad; valor = 0; capital = 0; util = 0;
		if(iteracion == 0){
			printCurrent(combinaciones,nodos,util,capital);
			iteracion++;
		}
		if(iteracion == 1){
			combinaciones[0] = cadena[0];
			util = utilidad[valor];
			capital = cadena[valor];
			i=0;
		if(capital <= cantInicial && util > utilMaxima){
			combinacion = 1;
			utilMaxima = util;
			capitalUsado = capital;
	}
			printCurrent(combinaciones,nodos,util,capital);
			aux = cantidad; valor = 0; capital = 0; util = 0;

		}
		iteracion = iteracion + 10;
	//*****************************	
		while(aux > 1 && iteracion>=2){
			modulo = aux%2;
			if(modulo == 1){
				util = util + utilidad[valor];
				capital = capital + cadena[valor];
				combinaciones[valor] = cadena[valor];
			}
			valor++;
			aux = aux/2;
			if(aux == 1){
				util = util + utilidad[valor];
				capital = capital + cadena[valor];
				combinaciones[valor] = cadena[valor];
				valor++;
			}
	}
	printCurrent(combinaciones,nodos,util,capital);
	//*****************************	
	if(capital <= cantInicial && util > utilMaxima){
		combinacion = cantidad;
		utilMaxima = util;
		capitalUsado = capital;
	}
	cantidad--;
	}
	escribir_archivo(capitalUsado,utilMaxima,combinacion,cadena);
}

/* ENTRADA: cadena[] = con las inversiones que forman la combinación
			cantidad = elementos que tiene la combinación (para imprimir por pantalla)
			utilidad = valor total  de la utilidad de la combinación
			capital = valor total del capital de la combinación
	SALIDA: Se muestra por pantalla la combinación que se genera en ese momento
*/
void printCurrent(int cadena [], int cantidad, int utilidad, int capital){
	#ifdef DEBUG
	int i = 0;
	printf("Combinación: ");
	while(i < cantidad){
		if(cadena[i]!=0){
		 printf("%i ",cadena[i] );
		}
		 i++;
		}
		printf("\n");
		printf("Utilidad: %i \nCapital: %i\n", utilidad,capital);
	printf("Enter para continuar...\n");
	while(getchar()!= '\n');
	#endif
}
/* ENTRADA: capital_usado = valor total del capital de la combinación
			utilidad_usada = valor total de la utilidad de la combinación
			aux = valor numérico que tiene la combinación
			cadena[] = variables que tiene la combinación
	SALIDA: archivo de nombre "salida.txt", que contien el capital usado, la utilidad generada y las combinaciones
*/
void escribir_archivo(int capital_usado, int utilidad_usada, int aux,int cadena[]){
	int valor = 0;
	int modulo;
	FILE* archivo2=fopen("salida.txt","w");
	fprintf(archivo2, "%i %i\n", capital_usado,utilidad_usada);
	if(aux == 1) fprintf(archivo2, "%i\n",cadena[0] );
	while(aux > 1 ){
		modulo = aux%2;
		if(modulo == 1){
			fprintf(archivo2, "%i\n", cadena[valor]);
				}
			valor++;
			aux = aux/2;
			if(aux == 1){
				fprintf(archivo2, "%i\n", cadena[valor]);
				valor++;
				}
	}
	fclose(archivo2);
	printf("EL PROGRAMA HA FINALIZADO CON ÉXITO\n");
}