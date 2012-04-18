#include "../include/Enemigo.h"
#include "../include/Pulpo.h"
#include "../include/Definiciones.h"
#include "../include/Disparo.h"

Pulpo::Pulpo(int x, int y, char *nombre) : Enemigo(x, y, nombre)
{

}

Pulpo::~Pulpo()
{
    clear_bitmap(getImagen());
}
