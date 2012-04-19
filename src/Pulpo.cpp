#include "../include/Enemigo.h"
#include "../include/Pulpo.h"
#include "../include/Definiciones.h"
#include "../include/Disparo.h"

Pulpo::Pulpo(int x, int y, char *nombre) : Enemigo(x, y, nombre)
{
	this->puntuacion = 20;
}

int Pulpo::getPuntuacion()
{
	return this->puntuacion;
}

Pulpo::~Pulpo()
{
    clear_bitmap(getImagen());
}
