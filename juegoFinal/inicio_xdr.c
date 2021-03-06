/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "inicio.h"

bool_t
xdr_datosPartida (XDR *xdrs, datosPartida *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->ipCreador, 20,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_short (xdrs, &objp->cantJugadores))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_datosJugador (XDR *xdrs, datosJugador *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->ipJugador, 20,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_datosMesa (XDR *xdrs, datosMesa *objp)
{
	register int32_t *buf;

	 if (!xdr_short (xdrs, &objp->idMesa))
		 return FALSE;
	 if (!xdr_short (xdrs, &objp->cantJugadores))
		 return FALSE;
	 if (!xdr_short (xdrs, &objp->idJugador))
		 return FALSE;
	return TRUE;
}
