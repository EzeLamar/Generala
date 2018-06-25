/*
 * Terminar de sacar los UDP jeje
 * 
 */

#include "DinamicaG.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
jugada_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		struct dados tirar_dados_1_arg;
		struct dados actualizar_dados_1_arg;
		struct informacionMesa actualizar_tabla_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case TIRAR_DADOS:
		_xdr_argument = (xdrproc_t) xdr_dados;
		_xdr_result = (xdrproc_t) xdr_posDados;
		local = (char *(*)(char *, struct svc_req *)) tirar_dados_1_svc;
		break;

	case ACTUALIZAR_DADOS:
		_xdr_argument = (xdrproc_t) xdr_dados;
		_xdr_result = (xdrproc_t) xdr_short;
		local = (char *(*)(char *, struct svc_req *)) actualizar_dados_1_svc;
		break;

	case ACTUALIZAR_TABLA:
		_xdr_argument = (xdrproc_t) xdr_informacionMesa;
		_xdr_result = (xdrproc_t) xdr_short;
		local = (char *(*)(char *, struct svc_req *)) actualizar_tabla_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	if(argc!=3){
		printf("Usage: ServerMesa ID_MESA ID_JUGADOR\n");
		exit(1);
	}
	AlIniciar(atoi(argv[1]),atoi(argv[2]));
	register SVCXPRT *transp;

	pmap_unset (JUGADA, PRIMERA);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, JUGADA, PRIMERA, jugada_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (JUGADA, PRIMERA, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, JUGADA, PRIMERA, jugada_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (JUGADA, PRIMERA, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
