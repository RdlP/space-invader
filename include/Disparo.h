#ifndef Disparo_h
#define Disparo_h
#include "ElementoGrafico.h"

/**
* Clase que representa al disparo del jugador.
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
class Disparo : public ElementoGrafico
{
    public:
        /**
        * Constructor de la clase Disparo.
        *
        * @param x Indica la posición x del disparo.
        * @param y Indica la posición y del disparo.
        * @param nombre Indica el nombre de la imagen que se va a utilizar para representar al disparo.
        */
        Disparo(int x, int y, char *nombre);
        /**
        * Destructor de la clase Disparo.
        * Destructor de la clase Disparo que elimina la imagen asociada al disparo.
        */
        virtual ~Disparo();
    protected:
    private:
};

#endif // Disparo_h
