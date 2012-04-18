#ifndef Enemigo_h
#define Enemigo_h
#include "ElementoGrafico.h"
#include "Disparo.h"

/**
* Clase que representa a los enemigos.
*
* Esta clase representa a los enemigos controlados
* por la CPU y hereda de la clase ElementoGrafico.
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
class Enemigo: public ElementoGrafico
{
    public:
        /**
        * Constructor de la clase que inicializa a los enemigos.
        *
        * @param x Indica la posición x de los enemigos.
        * @param y Indica la posición y de los enemigos.
        * @param nombre Indica el nombre del fichero imagen que va a ser asociado a los enemigos.
        */
        Enemigo(int x, int y, char *nombre);
        /**
        * Función para el movimiento de los Enemigos.
        *
        * Función usada para el movimiento de los enemigos
        *
        * @param direccion Indica la dirección en la que se deben mover los enemigos.
        * @param actualizarY Indica si se debe actualizar la posición Y de los enemigos.
        */
        void mover(int direccion, bool actualizarY);
        /**
         * Función de disparo de los enemigos.
         */
        Disparo* disparar();
        /**
        * Destructor de la clase.
        *
        * Destructor de la clase Enemigo, se encarga de eleminar la imagen asociada al enemigo.
        */
        virtual ~Enemigo();
    protected:
    private:
};

#endif // Enemigo_h
