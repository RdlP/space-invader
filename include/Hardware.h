#ifndef Hardware_h
#define Hardware_h
#include <vector>
#include <string>
using namespace std;
#include "ElementoGrafico.h"
#include <allegro.h>

/**
* Clase paara la abstracción de la memoria de video.
*
* Clase usada para abstraer al programador de manejar
* la memoria de video para cargar imagenes y demás tareas.
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
class Hardware
{
    public:
        /**
        * Constructor usado para inicializar la clase Hardware
        *
        * @param anchoPantalla indica el ancho de la pantalla.
        * @param altoPantalla indica el alto de la pantalla.
        */
        Hardware(int anchoPantalla, int altoPantalla);
        //bool comprobarTecla();
        /**
        * Función para saber si una determinada tecla ha sido pulsada.
        *
        * @return Devuelve True si la tecla codigo ha sido pulsada, False en caso contrario.
        */
        bool comprobarTecla(int codigo);
        /**
        * Espera a que una tecla sea pulsada.
        *
        * @return El codigo de la tecla pulsada.
        */
        int esperarTecla();
        //void vaciarBufferTeclado();
        /**
        * Función para saber si una tecla ha sido pulsada.
        *
        * @return Devuelve True si una tecla ha sido pulsada, fFlse en caso contrario.
        */
        bool algunaTeclaPulsada();
        /**
        * Función para borrar la pantalla oculta.
        */
        void borrarOculta();
        /**
        * Función para dibujar en la pantalla oculta un ElementoGrafico.
        *
        * @param e ElementoGrafico que se va a dibujar.
        */
        void dibujarOculta(ElementoGrafico e);
        /**
        * Función para visualizar en pantalla la pantalla oculta.
        */
        void visualizarOculta();
        /**
        * Función para pausar el programa.
        *
        * @param ms milisegundos que se va a pausar el programa.
        */
        void pausa (long ms);
        //virtual ~Hardware();
    private:
        int anchoPantalla;
        int altoPantalla;
        BITMAP *pantallaOculta;
        int maxX;
        int maxY;
        int colores;
        int teclaPulsada;
        int posXRaton;
        int posYRaton;
        BITMAP pantallaVisible;
        BITMAP fondo;
};

#endif // Hardware_h
