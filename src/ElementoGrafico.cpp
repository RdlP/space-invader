#include "../include/ElementoGrafico.h"
#include "iostream"
#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <math.h>
#include <string>

ElementoGrafico::ElementoGrafico(int x, int y, char *nombre)
{
    this->x = x;
    this->y = y;
    std::cout << "Cargando: " << nombre << std::endl;
    this->imagen = load_bmp(nombre, NULL);
    if (!imagen) {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("No se ha podido abrir la imagen\n");
        exit( 1 );
    }
    this->ancho = this->imagen->w;
    this->alto = this->imagen->h;
}

void ElementoGrafico::actualizarPosicion(int x, int y)
{
    this->x = x;
    this->y = y;
}

BITMAP* ElementoGrafico::getImagen()
{
    return this->imagen;
}

int ElementoGrafico::getX()
{
    return this->x;
}

int ElementoGrafico::getY()
{
    return this->y;
}

int ElementoGrafico::getAncho()
{
    return this->ancho;
}

int ElementoGrafico::getAlto()
{
    return this->alto;
}

bool ElementoGrafico::colisionCon(ElementoGrafico e)
{
    if (&e == NULL)
        return false;
    else
        return colisionCon(e.x, e.y, e.ancho, e.alto);
}

bool ElementoGrafico::colisionCon(int x, int y, int ancho, int alto)
{
    if ((this->x+this->ancho > x) && (this->y+this->alto > y)
        && (x+ancho > this->x) && (y+alto > this->y))
        return true;
    else
        return false;
}

void ElementoGrafico::eliminarGrafico(BITMAP* imagen)
{
    clear_bitmap(imagen);
    actualizarPosicion(0,0);
}


