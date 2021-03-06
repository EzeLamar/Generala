/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _DINAMICAG_H_RPCGEN
#define _DINAMICAG_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct informacionMesa {
	short idJugador;
	short idMesa;
	short puntajeJugada;
	char tipoJugada;
};
typedef struct informacionMesa informacionMesa;

struct dados {
	short dados[5];
	short idJugador;
	short idMesa;
};
typedef struct dados dados;

struct posDados {
	short pos[5];
	char tipoJugada;
};
typedef struct posDados posDados;

#define JUGADA 0x30000008
#define PRIMERA 1

#if defined(__STDC__) || defined(__cplusplus)
#define TIRAR_DADOS 1
extern void AlIniciar(short idMesa, short idJugador);
extern  posDados * tirar_dados_1(struct dados *, CLIENT *);
extern  posDados * tirar_dados_1_svc(struct dados *, struct svc_req *);
#define ACTUALIZAR_DADOS 2
extern  short * actualizar_dados_1(struct dados *, CLIENT *);
extern  short * actualizar_dados_1_svc(struct dados *, struct svc_req *);
#define ACTUALIZAR_TABLA 3
extern  short * actualizar_tabla_1(struct informacionMesa *, CLIENT *);
extern  short * actualizar_tabla_1_svc(struct informacionMesa *, struct svc_req *);
extern int jugada_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define TIRAR_DADOS 1
extern  posDados * tirar_dados_1();
extern  posDados * tirar_dados_1_svc();
#define ACTUALIZAR_DADOS 2
extern  short * actualizar_dados_1();
extern  short * actualizar_dados_1_svc();
#define ACTUALIZAR_TABLA 3
extern  short * actualizar_tabla_1();
extern  short * actualizar_tabla_1_svc();
extern int jugada_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_informacionMesa (XDR *, informacionMesa*);
extern  bool_t xdr_dados (XDR *, dados*);
extern  bool_t xdr_posDados (XDR *, posDados*);

#else /* K&R C */
extern bool_t xdr_informacionMesa ();
extern bool_t xdr_dados ();
extern bool_t xdr_posDados ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_DINAMICAG_H_RPCGEN */
