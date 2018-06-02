#include <stdio.h>
//random
#include <time.h>
#include <stdlib.h>

#define MIN_DADO 1
#define MAX_DADO 6
#define CANT_DADOS 5
#define JUEGOS_DADOS 11

//JUEGOS
#define NUM_1 0
#define NUM_2 1
#define NUM_3 2
#define NUM_4 3
#define NUM_5 4
#define NUM_6 5
#define E 6
#define F 7
#define P 8
#define G 9
#define GG 10



//Estructuras
struct datos_juego{
	int tablaPuntajes[JUEGOS_DADOS];
	int posiblesJuegos[JUEGOS_DADOS];
};

//GLOBALES
struct datos_juego *datos;
int dados[CANT_DADOS];

int tirarDado(){
	//se obtiene un numero entre 1 y 6
	   // should only be called once
	return (rand()%6)+1;
}

void juegosPosibles(){
	int contadorNros[MAX_DADO]; //arreglos que cuentan cuantos apariciones de cada numero hay.
	
	for(int i=0; i<CANT_DADOS;i++)
		contadorNros[i]=0;

	//cuento las apariciones de cada uno de los nros entre los 5 dados.
	for(int i=0; i<CANT_DADOS;i++){
		int valorDado= dados[i];
		contadorNros[valorDado-1]++;
	}

	//busco GENERALA
	int pos=0;
	while(pos<MAX_DADO)
		if(contadorNros[pos]==5){
			datos->posiblesJuegos[G]=50;
			break;
		}
		else pos++;

	if(pos==MAX_DADO)
		datos->posiblesJuegos[G]=0;

	//busco POKER
	pos=0;
	while(pos<MAX_DADO)
		if(contadorNros[pos]>=4){
			datos->posiblesJuegos[P]=40;
			break;
		}
		else pos++;
	if(pos==MAX_DADO)
		datos->posiblesJuegos[P]=0;

	//busco Full
	pos=0;
	int hayTres=0;
	int hayDos=0;
	while(pos<MAX_DADO){
		if(contadorNros[pos]==2)
			hayDos=1;
		if(contadorNros[pos]==3)
			hayTres=1;
		pos++;
	}
	if(hayDos && hayTres)
		datos->posiblesJuegos[F]=30;
	else
		datos->posiblesJuegos[F]=0;

	//busco ESCALERA
	int cantSeguidos=0;
	for(int i=0; i<MAX_DADO; i++){
		if(contadorNros[i]>0){
			cantSeguidos++;
			if(cantSeguidos==5)
				break;
		}

		else cantSeguidos=0;
	}
	if(cantSeguidos==5)
		datos->posiblesJuegos[E]=20;
	else 
		datos->posiblesJuegos[E]=0;

	//busco Juegos de Nros (1,2,3,4,5,6)
	for(int i=0; i<MAX_DADO; i++){
		datos->posiblesJuegos[i]=contadorNros[i]*(i+1);
	}
}


int main(){
	//inicializo el struct datos_juegos
	datos= (struct datos_juego*) malloc(sizeof(struct datos_juego));

	//genero la semilla para obtener los dados segun la hora.
	srand(time(NULL));
	int valor;
	//genero 5 nros al azar y asigno a los dados
	for(int i=1; i<=CANT_DADOS; i++){
		valor= tirarDado();
		dados[i-1]=valor;
	}

    //muestro por pantalla los dados obtenidos.
	for(int i=1; i<=CANT_DADOS; i++){
		printf("tire el %d° dado: %d\n",i,dados[i-1]);
	}

	printf("\n");
	//CHEQUEAMOS LOS JUEGOS QUE SE PUEDEN FORMAR:
//	dados[0]=1;
//	dados[1]=1;
//	dados[2]=1;
//	dados[3]=1;
//	dados[4]=1;
	juegosPosibles();
	for(int i=0; i<JUEGOS_DADOS; i++)
		printf("Para %d: %d\n", (i+1), datos->posiblesJuegos[i]);



	return 1;
}
