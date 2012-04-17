#include "../include/Enemigo.h"
#include "../include/Definiciones.h"

Enemigo::Enemigo(int x, int y, char *nombre) : ElementoGrafico(x, y, nombre)
{

}

Enemigo::~Enemigo()
{
    clear_bitmap(getImagen());
}

void Enemigo::mover(int direccion, bool actualizarY)
{
    int nuevaX = this->getX()+(DESPLAZAMIENTO_ENEMIGO*direccion);
    if (actualizarY)
        this->actualizarPosicion(nuevaX,this->getY()+30);
    else
        this->actualizarPosicion(nuevaX,this->getY());
}
