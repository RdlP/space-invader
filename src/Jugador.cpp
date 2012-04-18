#include "../include/Jugador.h"
#include "../include/Definiciones.h"
#include "../include/Disparo.h"
#include "../include/Hardware.h"
#include "iostream"
#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <math.h>
#include <string>

Jugador::Jugador(int x, int y, char *nombre) : ElementoGrafico(x, y, nombre)
{
    disparos = 0;
    for (int i = 0; i < MAX_DISPAROS; i++)
    {
        disparo[i] = NULL;
    }
}

void Jugador::moverDerecha(int despX)
{
    int nuevaX = getX()+despX;
    if (nuevaX < ANCHO_PANTALLA - getImagen()->w)
        actualizarPosicion(nuevaX,getY());
}

void Jugador::moverIzquierda(int despX)
{
    int nuevaX = getX()-despX;
    if (nuevaX > 0)
        actualizarPosicion(getX()-despX,getY());
}

void Jugador::disparar()
{
    if (disparos != MAX_DISPAROS)
    {
        disparos++;
        int i = 0;
        while (disparo[i] != NULL) { i++; }
        disparo[i] = new Disparo(getX()+getImagen()->w/2, getY(), "./resource/disparo.bmp");
    }
}

