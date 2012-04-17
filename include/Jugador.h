#ifndef Jugador_h
#define Jugador_h
#include "ElementoGrafico.h"
#include "Disparo.h"
#include "Definiciones.h"

/**
* Clase que representa al jugador.
*
* Esta clase representa al jugador humano y hereda
* de la clase ElementoGrafico.
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
class Jugador: public ElementoGrafico
{
    public:
        /**
        * Constructor de la clase que inicializa al jugador.
        *
        * @param x Indica la posición x del jugador.
        * @param y Indica la posición y del jugador.
        * @param nombre Indica el nombre del fichero imagen que va a ser asociado al jugador.
        */
        Jugador(int x, int y, char *nombre);
        /**
        * Función para mover el jugador a la derecha.
        *
        * @param despX Indica cuanto debe desplazarse en el eje X.
        */
        void moverDerecha(int despX);
        /**
        * Función para mover el jugador a la izquierda.
        *
        * @param despY Indica cuanto debe desplazarse en el eje Y.
        */
        void moverIzquierda(int despX);
        /**
        * Función para disparar.
        */
        void disparar();
        Disparo *disparo[MAX_DISPAROS];
        int disparos;
        //virtual ~Jugador();
    protected:
    private:
};

#endif // Jugador_h
