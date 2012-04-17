#ifndef Juego_h
#define Juego_h

/**
* Clase que representa al jeugo.
*
* Esta clase representa al juego, almacenando diversos atributos,
* como por ejemplo la puntuación, el nivel en el que se encuentra
* el juego, el nombre del jugador, si el juego ha terminado o no, etc...
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
class Juego
{
    public:
        /**
        * Constructor de la clase Juego.
        *
        * Constructor de la clase Juego que se encarga de inicializar
        * la puntuación a 0, el nivel a 1, y terminado como false.
        */
        Juego(int vidas);
        /**
        * Función que devuelve la puntación del juegador.
        *
        * @return Devuelve la puntación del juegador.
        */
        int getPuntuacion();
        /**
        * Función que incrementa la puntuación del juegador.
        *
        * @param incremento Indica la cantidad en la que se
        * va a aumentar la puntuación.
        */
        void incrementarPuntuacion(int incremento);
        /**
        * Función que devuelve el nombre del juegador.
        *
        * @return Devuelve el nombre del jugador.
        */
        char* getNombre();
        /**
        * Función que devuelve el nivel en que se encuentra el jugador.
        *
        * @return Devuelve el nivel en el que se encuentra el jugador.
        */
        int getNivel();
        /**
        * Función que devuelve si el juego a terminado o no.
        *
        * @return Devuelve True si el juego ha terminado y falso en caso contrario.
        */
        bool isTerminado();
        /**
        * Función para establecer si el juego a terminado o no.
        *
        * @param cond True para acabar el juego y False en caso contrario.
        */
        void setTerminado(bool cond);
        /**
        * Función que devuelve las vidas que le quedan al jugador.
        *
        * @return Devuelve las vidas que le quedan al jugador.
        */
        int getVidas();
        /**
        * Función usada para decrementar las vidas cuando
        * el juegador muere.
        *
        * @param vidas Indica las vidas que le quedan al jugador.
        */
        void setVidas(int vidas);
    protected:
    private:
        int puntuacion;
        char* nombre;
        int nivel;
        int vidas;
        bool terminado;
};

#endif // Juego_h
