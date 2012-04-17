#ifndef ELEMENTOGRAFICO_H
#define ELEMENTOGRAFICO_H
#include <allegro.h>

/**
* Clase que representa a un ElementoGráfico.
*
* Clase usada para respresentar los distintos ElementosGraficos
* que van a aparecer en el juego.
*
* @author Ángel Luis Perales Gómez
* @version 0.1.1
* @section LICENCIA
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details at
* http://www.gnu.org/copyleft/gpl.html
*/

class ElementoGrafico
{
    public:
        /**
        * Constructor para iniciañizar ElementoGrafico.
        *
        * @param x Indica la posición x en la que se va a colocar el ElementoGrafico.
        * @param y Indica la posición y en la que se va a colocar el ElementoGrafico.
        * @param nombre Indica el nombre del fichero que se va a cargar como imagen del ElementoGrafico.
        */
        ElementoGrafico(int x, int y, char *nombre);
        /**
        * Actualiza la posición del ElementoGrafico.
        *
        * @param x Indica la nueva posición x del ElementoGrafico-
        * @param y Indica la nueva posición y del ElementoGrafico.
        */
        void actualizarPosicion(int x, int y);
        //void crearDesdeFichero(char *nombre);
        /**
        * Función que devuelve la imagen del ElementoGrafico.
        *
        * @return Devuelve un puntero a la imagen del ElementoGrafico.
        */
        BITMAP* getImagen();
        /**
        * Función que devuelve la posición x.
        *
        * @return Devuelve la posición x del ElementoGrafico.
        */
        int getX();
        /**
        * Función que devuelve la posición y.
        *
        * @return Devuelve la posición y del ElementoGrafico.
        */
        int getY();
        /**
        * Función que devuelve el ancho.
        *
        * @return Devuelve el ancho del ElementoGrafico.
        */
        int getAncho();
        /**
        * Función que devuelve el alto.
        *
        * @return Devuelve el alto del ElementoGrafico.
        */
        int getAlto();
        /**
        * Función que comprueba colusiones.
        *
        * Función que calcula si un ElementoGrafico colisiona con otro
        * ElementoGrafico pasado por parámetro.
        *
        * @param e ElementoGrafico con el que se comprueban las colisiones.
        * @return Devuelve True si hay colisión, False en caso contrario.
        */
        bool colisionCon(ElementoGrafico e);
        /**
        * Función que comprueba colisiones.
        *
        * Funcíon que calcula si un ElementoGrafico colisiona con
        * otro ElementoGrafico.
        *
        * @param x Posición x del ElementoGrafico.
        * @param y Posición y del ElementoGrafico.
        * @param ancho Ancho del ElementoGrafico.
        * @param alto Alto del ElementoGrafico.
        * @return Devuelve True si hay colisión, False en caso contrario.
        */
        bool colisionCon (int x, int y, int ancho, int alto);
        /**
        * Función para eliminar el gráfico de un ElementoGrafico.
        *
        * @param imagen Imagen que se va a eliminar.
        */
        void eliminarGrafico(BITMAP* imagen);

        //virtual ~ElementoGrafico();
    protected:
    private:
        BITMAP *imagen;
        int ancho, alto;
        int anchoOrig, altoOrig;
        int colorTransp;
        int x, y;
};

#endif // ELEMENTOGRAFICO_H
