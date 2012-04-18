#ifndef PULPO_H_
#define PULPO_H_

#include "ElementoGrafico.h"
#include "Enemigo.h"

/**
* Clase que representa al enemigo de tipo Pulpo.
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
class Pulpo : public Enemigo
{
    public:
        /**
        * Constructor de la clase Pulpo.
        *
        * @param x Indica la posición x del Pulpo.
        * @param y Indica la posición y del Pulpo.
        * @param nombre Indica el nombre de la imagen que se va a utilizar para representar al Pulpo.
        */
        Pulpo(int x, int y, char *nombre);
        /**
        * Destructor de la clase Pulpo.
        * Destructor de la clase Pulpo que elimina la imagen asociada al Pulpo.
        */
        virtual ~Pulpo();
    protected:
    private:
};

#endif /* PULPO_H_ */
