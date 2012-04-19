#ifndef ALIEN_H_
#define ALIEN_H_

#include "ElementoGrafico.h"
#include "Enemigo.h"

/**
* Clase que representa al enemigo de tipo Alien.
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
class Alien : public Enemigo
{
    public:
        /**
        * Constructor de la clase Alien.
        *
        * @param x Indica la posición x del Alien.
        * @param y Indica la posición y del Alien.
        * @param nombre Indica el nombre de la imagen que se va a utilizar para representar al Alien.
        */
        Alien(int x, int y, char *nombre);
        /**
         * Función que devuelve la puntuación que se obtiene al matar a un Alien.
         *
         * @return Devuelve un entero indicando la puntuación por matar al tipo de enemigo Alien.
         */
        int getPuntuacion();
        /**
        * Destructor de la clase Alien.
        * Destructor de la clase Alien que elimina la imagen asociada al Alien.
        */
        virtual ~Alien();
    protected:
    private:
        int puntuacion;
};

#endif /* ALIEN_H_ */
