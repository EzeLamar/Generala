#include <stdio.h>
//random
#include <time.h>
#include <stdlib.h>

#define MIN_DADO 1
#define MAX_DADO 6


int tirarDado(){
	//se obtiene un numero entre 1 y 6
	   // should only be called once
	return rand()%7;
}


int main(){
	int dados[5];
	//genero la semilla para obtener los dados segun la hora.
	srand(time(NULL));
	int valor;
	//genero 5 nros al azar y asigno a los dados
	for(int i=MIN_DADO; i<MAX_DADO; i++){
		valor= tirarDado();
		dados[i-1]=valor;
	}

    //muestro por pantalla los dados obtenidos.
	for(int i=MIN_DADO; i<MAX_DADO; i++){
		printf("tire el %d° dado: %d\n",i,dados[i-1]);
	}

	return 1;
}
