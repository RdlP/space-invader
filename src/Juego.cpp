#include "../include/Juego.h"

Juego::Juego(int vidas)
{
    this->terminado = false;
    this->nivel = 1;
    this->puntuacion = 0;
    this->vidas = vidas;
}

int Juego::getPuntuacion()
{
    return this->puntuacion;
}

void Juego::incrementarPuntuacion(int incremento)
{
    this->puntuacion = this->puntuacion + incremento;
}

int Juego::getNivel()
{
    return this->nivel;
}

char* Juego::getNombre()
{
    return this->nombre;
}

bool Juego::isTerminado()
{
    return terminado;
}

void Juego::setTerminado(bool cond)
{
    this->terminado = cond;
}

int Juego::getVidas()
{
    return this->vidas;
}

void Juego::setVidas(int vidas)
{
    this->vidas = vidas;
}
