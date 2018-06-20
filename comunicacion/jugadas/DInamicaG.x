struct informacionMesa{
	short idJugador; 
	short idMesa; 
	short puntajeJugada;
	char tipoJugada;
	
};

struct dados{
	short dados[5];
	short idJugador;
	short idMesa; 
};

struct posDados{
	short pos[5]; 
	char tipoJugada; 
	
};

program JUGADA{
	version PRIMERA {
		posDados TIRAR_DADOS( struct dados )=1;
		short ACTUALIZAR_DADOS( struct dados )=2;
		short ACTUALIZAR_TABLA(struct informacionMesa )=3;
	}=1;
}=0x30000008;
