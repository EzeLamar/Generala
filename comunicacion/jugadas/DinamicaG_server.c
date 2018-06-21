/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "DinamicaG.h"
#define MAX_JUEGOS 11
#define MAX_JUGADORES_MESA 4

short tablaPuntajes[MAX_JUGADORES_MESA][MAX_JUEGOS];
short idJugador;
short idMesa;

void mostrarDados(short* dados){
	printf("[");
	for(int i=0; i<5; i++){
		printf("%d,",dados[i]);
	}
	printf("]\n");
}

posDados *
tirar_dados_1_svc(struct dados *argp, struct svc_req *rqstp)
{
	static posDados  result;

	//recibo los dados aleatorios del servidorMesas,
	//verifico si son para mi
	if(idMesa==argp->idMesa){
		//verifico que los dados son para este jugador
		if(idJugador==argp->idJugador){
			//muestro los dados recibidos por pantalla..
			printf("tirarDados:\n");
			mostrarDados(argp->dados);
		}
		else{
			printf("Error! el msje es para otro jugador.\n");
		}
	}
	else{
		printf("Error! el msje es para otra mesa.\n");
	}

	

	return &result;
}

short *
actualizar_dados_1_svc(struct dados *argp, struct svc_req *rqstp)
{
	static short  result;
	printf("actualizarDados:\n");
	mostrarDados(argp->dados);

	return &result;
}

short *
actualizar_tabla_1_svc(struct informacionMesa *argp, struct svc_req *rqstp)
{
	static short  result;

	/*
	 * insert server code here
	 */

	return &result;
}

void AlIniciar(short idMesaRecibida, short idJugadorRecibido){
	printf("arranque!\n");
	//inicializo el idJugador y idMesa
	idMesa=idMesaRecibida;
	idJugador= idJugadorRecibido;

	//incializo los valores de todos los puntajes en -1 (representa que no se anoto nada todav)
	for(int jug=0; jug<MAX_JUGADORES_MESA; jug++)
		for(int p=0; p<MAX_JUEGOS; p++)
			tablaPuntajes[jug][p]=-1;
	printf("..termine de cargar los puntajes iniciales\n");
}