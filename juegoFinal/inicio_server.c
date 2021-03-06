#include "inicio.h"
#include <string.h>
#include <stdio.h>

#define MAX_JUGADORES_MESA 4
#define TAMANO_IP 20

short lugaresDisponiblesMesa=0;
char ipJugadores[MAX_JUGADORES_MESA][TAMANO_IP];
short cantJugadoresMesa;
short idMesa;
int mesaLlena=0;

datosMesa *
crear_mesa_1_svc(datosPartida *argp, struct svc_req *rqstp)
{
	static datosMesa  result;

	cantJugadoresMesa= argp->cantJugadores;

	//creamos la mesa asignandole un valor unico.
	idMesa=1;
	mesaLlena=0;
	//indicamos que quedan lugares disponibles.
	lugaresDisponiblesMesa= cantJugadoresMesa-1; //el que creo la mesa ya tiene un lugar ocupado.
	sprintf(ipJugadores[0], "%s", argp->ipCreador);

	result.idMesa= idMesa;
	result.cantJugadores= cantJugadoresMesa;
	result.idJugador=0;

	printf("El jugador %s(%d) creo la mesa %d\n", ipJugadores[0], 0, idMesa);
	return &result;
}

datosMesa *
unirse_partida_1_svc(datosJugador *argp, struct svc_req *rqstp)
{
	static datosMesa  result;

	if(lugaresDisponiblesMesa>0){
		result.idMesa=idMesa;
		result.cantJugadores=cantJugadoresMesa;
		short idJugadorActual = cantJugadoresMesa - lugaresDisponiblesMesa; 
		result.idJugador= idJugadorActual;	//valores entre 0 y 3.
		lugaresDisponiblesMesa--;
		sprintf(ipJugadores[idJugadorActual], "%s" , argp->ipJugador);

		printf("Se unio jugador %s(%d) a la mesa %d\n", ipJugadores[idJugadorActual], idJugadorActual, idMesa);
		
		//controlo si se lleanron todos los luagares..
		if(lugaresDisponiblesMesa==0){
			//almaceno las IPs en un archivo
			FILE *f;
			f= fopen("jugadoresIPs.txt", "w");
			for(int i=0; i<cantJugadoresMesa; i++){
				fprintf(f,"%s\n", ipJugadores[i]);
			}
			fclose(f);
			//HABILITO FLAG PARA ARRANCAR RPC_JUGADAS..
			mesaLlena=1;
		}
	}
	//no hay mesas disponibles para meterse..
	else{
		result.idMesa=-1;
		result.cantJugadores=0;
		result.idJugador=-1;

		printf("Error, no hay mesas disponibles\n");
	}
	return &result;
}

int noQuedanLugares(){
	return mesaLlena;
}
