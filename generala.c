#include <stdio.h>
#include <stdlib.h>
//random
#include <time.h>
#include <stdlib.h>

#define MIN_DADO 1
#define MAX_DADO 6
#define CANT_DADOS 5
#define JUEGOS_DADOS 11
#define MAX_TIROS 3

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
int nroTiro=1;

int tirarDado(){
	//se obtiene un numero entre 1 y 6
	   // should only be called once
	return (rand()%6)+1;
}

void mostrarDados(){
	for(int i=1; i<=CANT_DADOS; i++){
		printf("%d° dado: %d\n",i,dados[i-1]);
	}
	printf("----------\n");
}

void mostrarJuegosPosibles(){
	int valorPosible;
	printf("Posibles Juegos:\n");
	for(int i=0; i<MAX_DADO; i++){
		valorPosible= datos->posiblesJuegos[i];
		if(valorPosible>0)
			printf("%d: %d\n", (i+1), valorPosible);
	}
	valorPosible= datos->posiblesJuegos[E];
	if(valorPosible>0)
		printf("E: %d\n", valorPosible);

	valorPosible= datos->posiblesJuegos[F];
	if(valorPosible>0)
		printf("F: %d\n", valorPosible);

	valorPosible= datos->posiblesJuegos[P];
	if(valorPosible>0)
		printf("P: %d\n", valorPosible);

	valorPosible= datos->posiblesJuegos[G];
	if(valorPosible>0)
		printf("G: %d\n", valorPosible);

	valorPosible= datos->posiblesJuegos[GG];
	if(valorPosible>0)
		printf("GG: %d\n", valorPosible);

	printf("--------------\n");
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
	//PRIMER TURNO:
	//tiro todos los dados al azar..
	for(int i=1; i<=CANT_DADOS; i++){
		dados[i-1]=tirarDado();
	}

	
//	dados[0]=1;
//	dados[1]=1;
//	dados[2]=1;
//	dados[3]=1;
//	dados[4]=1;
	while(nroTiro<=MAX_TIROS){
		printf("TIRO NRO: %d\n", nroTiro);
		//muestro por pantalla los dados obtenidos.
		mostrarDados();
		//CHEQUEAMOS LOS JUEGOS QUE SE PUEDEN FORMAR:
		juegosPosibles();
		mostrarJuegosPosibles();

		//EL CLIENTE ELIGE SI ANOTAR O VOLVER A TIRAR (DADOS ESPECIFICOS)
		int opcionValida=0;
		char opcion;
		while(!opcionValida){
			printf("¿Desea anotar [a] o volver a tirar [t]?\n");
			scanf(" %c",&opcion);
			if(opcion=='a'||opcion=='t')
				opcionValida=1;
			if(nroTiro==MAX_TIROS && opcion=='t'){
				printf("Ya no tiene mas tiros!\n");
				opcionValida=0;
			}
		}
		
		//si ingreso ANOTAR:
		if(opcion=='a'){
			char charJuego;
			int nroJuego;
			int seAnoto=0;
			while(!seAnoto){
				printf("ingrese el juego a anotar:\n");
				scanf(" %c",&charJuego);
				//casteo de char a entero
				nroJuego= atoi(&charJuego);
				printf("el nro es: %d\n", nroJuego);
				//chequear si el juego a anotar es valido:
				if(datos->tablaPuntajes[nroJuego]==0 && datos->posiblesJuegos[nroJuego]>0){
					datos->tablaPuntajes[nroJuego]=datos->posiblesJuegos[nroJuego];
					printf("se agrego correctamente el juego a la tabla de puntajes.\n");
					seAnoto=1;
				}
				else printf("Error! no puede anotar dicho juego.\n");
			}
			
			nroTiro=MAX_TIROS+1;	//consumo todos mis tiros.
		}

		//si ingreso VOLVER A TIRAR:
		if(opcion=='t'){
			printf("ingrese la cantidad a volver a tirar\n");
			int cantidad=0;
			scanf(" %d",&cantidad);
			int dadoNro;
			printf("ingrese las posiciones (1-5):\n");
			for(int i=0; i<cantidad;i++){
				scanf(" %d",&dadoNro);
				dados[dadoNro-1]=tirarDado();
			}
			nroTiro++;
		}
	}
	return 1;
}