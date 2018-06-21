/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "DinamicaG.h"


void
jugada_1(char *host)
{
	CLIENT *clnt;
	posDados  *result_1;
	struct dados  tirar_dados_1_arg;
	short  *result_2;
	struct dados  actualizar_dados_1_arg;
	short  *result_3;
	struct informacionMesa  actualizar_tabla_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, JUGADA, PRIMERA, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	//SETEO LOS CAMPOS DEL STRUCT A ENVIAR
	for(short i=0; i<5;i++){
		tirar_dados_1_arg.dados[i]=i+1;
	}
	tirar_dados_1_arg.idJugador=1;
	tirar_dados_1_arg.idMesa=1;

	result_1 = tirar_dados_1(&tirar_dados_1_arg, clnt);
	if (result_1 == (posDados *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	//SETEO LOS CAMPOS DEL STRUCT A ENVIAR
	for(short i=0; i<5;i++){
		actualizar_dados_1_arg.dados[i]=i+1;
	}
	actualizar_dados_1_arg.idJugador=1;
	actualizar_dados_1_arg.idMesa=1;
	result_2 = actualizar_dados_1(&actualizar_dados_1_arg, clnt);
	if (result_2 == (short *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = actualizar_tabla_1(&actualizar_tabla_1_arg, clnt);
	if (result_3 == (short *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	jugada_1 (host);
exit (0);
}