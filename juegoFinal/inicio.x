struct datosPartida {
    char ipCreador[20];
    short cantJugadores;
};

struct datosJugador {
    char ipJugador[20];
};

struct datosMesa {
    short idMesa;
    short cantJugadores;
    short idJugador;
};

program PARTIDA {
    version PRIMER {
        datosMesa CREAR_MESA( datosPartida )= 1;
        datosMesa UNIRSE_PARTIDA( datosJugador )= 2;
    }=1;
}=0x20000008;
