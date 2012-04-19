#include "../include/Enemigo.h"
#include "../include/Alien.h"
#include "../include/Definiciones.h"
#include "../include/Disparo.h"

Alien::Alien(int x, int y, char *nombre) : Enemigo(x, y, nombre)
{
	this->puntuacion = 40;
}

int Alien::getPuntuacion()
{
	return this->puntuacion;
}

Alien::~Alien()
{
    clear_bitmap(getImagen());
}
