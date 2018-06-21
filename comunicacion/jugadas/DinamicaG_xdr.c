/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "DinamicaG.h"

bool_t
xdr_informacionMesa (XDR *xdrs, informacionMesa *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_short (xdrs, &objp->idJugador))
				 return FALSE;
			 if (!xdr_short (xdrs, &objp->idMesa))
				 return FALSE;
			 if (!xdr_short (xdrs, &objp->puntajeJugada))
				 return FALSE;

		} else {
		IXDR_PUT_SHORT(buf, objp->idJugador);
		IXDR_PUT_SHORT(buf, objp->idMesa);
		IXDR_PUT_SHORT(buf, objp->puntajeJugada);
		}
		 if (!xdr_char (xdrs, &objp->tipoJugada))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_short (xdrs, &objp->idJugador))
				 return FALSE;
			 if (!xdr_short (xdrs, &objp->idMesa))
				 return FALSE;
			 if (!xdr_short (xdrs, &objp->puntajeJugada))
				 return FALSE;

		} else {
		objp->idJugador = IXDR_GET_SHORT(buf);
		objp->idMesa = IXDR_GET_SHORT(buf);
		objp->puntajeJugada = IXDR_GET_SHORT(buf);
		}
		 if (!xdr_char (xdrs, &objp->tipoJugada))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_short (xdrs, &objp->idJugador))
		 return FALSE;
	 if (!xdr_short (xdrs, &objp->idMesa))
		 return FALSE;
	 if (!xdr_short (xdrs, &objp->puntajeJugada))
		 return FALSE;
	 if (!xdr_char (xdrs, &objp->tipoJugada))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_dados (XDR *xdrs, dados *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (2 +  5 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->dados, 5,
				sizeof (short), (xdrproc_t) xdr_short))
				 return FALSE;
			 if (!xdr_short (xdrs, &objp->idJugador))
				 return FALSE;
			 if (!xdr_short (xdrs, &objp->idMesa))
				 return FALSE;
		} else {
			{
				register short *genp;

				for (i = 0, genp = objp->dados;
					i < 5; ++i) {
					IXDR_PUT_SHORT(buf, *genp++);
				}
			}
			IXDR_PUT_SHORT(buf, objp->idJugador);
			IXDR_PUT_SHORT(buf, objp->idMesa);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (2 +  5 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->dados, 5,
				sizeof (short), (xdrproc_t) xdr_short))
				 return FALSE;
			 if (!xdr_short (xdrs, &objp->idJugador))
				 return FALSE;
			 if (!xdr_short (xdrs, &objp->idMesa))
				 return FALSE;
		} else {
			{
				register short *genp;

				for (i = 0, genp = objp->dados;
					i < 5; ++i) {
					*genp++ = IXDR_GET_SHORT(buf);
				}
			}
			objp->idJugador = IXDR_GET_SHORT(buf);
			objp->idMesa = IXDR_GET_SHORT(buf);
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->dados, 5,
		sizeof (short), (xdrproc_t) xdr_short))
		 return FALSE;
	 if (!xdr_short (xdrs, &objp->idJugador))
		 return FALSE;
	 if (!xdr_short (xdrs, &objp->idMesa))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_posDados (XDR *xdrs, posDados *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, ( 5 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->pos, 5,
				sizeof (short), (xdrproc_t) xdr_short))
				 return FALSE;

		} else {
		{
			register short *genp;

			for (i = 0, genp = objp->pos;
				i < 5; ++i) {
				IXDR_PUT_SHORT(buf, *genp++);
			}
		}
		}
		 if (!xdr_char (xdrs, &objp->tipoJugada))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, ( 5 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->pos, 5,
				sizeof (short), (xdrproc_t) xdr_short))
				 return FALSE;

		} else {
		{
			register short *genp;

			for (i = 0, genp = objp->pos;
				i < 5; ++i) {
				*genp++ = IXDR_GET_SHORT(buf);
			}
		}
		}
		 if (!xdr_char (xdrs, &objp->tipoJugada))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->pos, 5,
		sizeof (short), (xdrproc_t) xdr_short))
		 return FALSE;
	 if (!xdr_char (xdrs, &objp->tipoJugada))
		 return FALSE;
	return TRUE;
}