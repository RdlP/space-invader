#include "../include/Enemigo.h"
#include "../include/Alien.h"
#include "../include/Definiciones.h"
#include "../include/Disparo.h"

Alien::Alien(int x, int y, char *nombre) : Enemigo(x, y, nombre)
{

}

Alien::~Alien()
{
    clear_bitmap(getImagen());
}
