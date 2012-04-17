#include "../include/Disparo.h"

Disparo::Disparo(int x, int y, char *nombre) : ElementoGrafico(x, y, nombre)
{

}

Disparo::~Disparo()
{
    clear_bitmap(getImagen());
}
