#include <allegro.h>
#include "include/Hardware.h"
#include "include/Definiciones.h"
#include "include/ElementoGrafico.h"
#include "include/Juego.h"
#include "include/Jugador.h"
#include "include/Enemigo.h"
#include "include/Disparo.h"
#include "include/Alien.h"
#include "include/Pulpo.h"
#include <stdlib.h>
#include <time.h>
#include "iostream"
#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <math.h>
#include <string>

Hardware *hardware;
Juego *juego;
Jugador *jugador;
Enemigo *enemigo[5][10];
int enemigos = 50;
int direccion;
bool actualizarY = false;
volatile long fps = 0;
int oldkeys[KEY_MAX];
Disparo *disparosEnemigos[MAX_DISPAROS];

/**
 * Realiza los disparos de los enemigos.
 *
 * Recorre todos los enemigos y se genera un número aleatorio
 * si ese número coindice con el número de enemigos que hay
 * actualmente en la pantalla multiplicado por 20 entonces
 * el enemigo [i][j] disparará.
 */

void disparosDeEnemigos()
{
	int num;
	for (int i = 0; i < 5; i++)
	    {
	        for (int j = 0; j < 10; j++)
	        {
	        	num=rand()%(enemigos*20); //Numero aleatorio entre 0 y 500
	        	if ((num == i*j) and (enemigo[i][j] != NULL))
	        	{
	        		int k = 0;
	        		//Esto se hace para buscar sitio a los nuevos disparos
	        		while (disparosEnemigos[k] != NULL) k++;
	        		disparosEnemigos[k] = enemigo[i][j]->disparar();
	        	}
	        }
	    }
}

/**
 * Carga los distintos elementos en sus respectivas posiciones,
 * sin llegar a visualizarlos, aquí no se llama a la función
 * dibuja.
 */

void cargarElementos()
{
	char imagenJugador[23]="./resource/jugador.bmp";
	char imagenAlien[23]="./resource/enemigo.bmp";
	char imagenPulpo[24]="./resource/enemigo1.bmp";
    jugador = new Jugador(ANCHO_PANTALLA/2,ALTO_PANTALLA-75, imagenJugador);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
        	if (i%2 == 0)
        		enemigo[i][j] = new Pulpo(j*70, i*70, imagenPulpo);
        	else
        		enemigo[i][j] = new Alien(j*70, i*70, imagenAlien);
        }
    }
    direccion = 1;
}

/**
 * Muestra la puntuación y las vidas del juegador en la parte inferior
 * izquierda de la pantalla.
 */

void mostrarInformacion()
{
    textprintf_ex(screen, font, 5, ALTO_PANTALLA-20, makecol(255,255,255), 1, "Vidas: %d Puntuación: %d", juego->getVidas(), juego->getPuntuacion());
}

/**
 * Ddibuja los distintos elementos en la pantalla.
 *
 * Lo primero que hace es borrar la pantalla oculta (la pantallaOculta
 * es una técnica de doble buffer que evita el parpadeo en la pantalla).
 *
 * A continuación dibuja en la pantalla oculta al jugador, a todos los
 * enemigos, todos los disparos del juegador y todos los disparos
 * de los enemigos y por último visualiza estos elementos en la
 * pantalla visible.
 */

void dibujar()
{
    hardware->borrarOculta();
    hardware->dibujarOculta(*jugador);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (enemigo[i][j] != NULL)
            {
                hardware->dibujarOculta(*enemigo[i][j]);
            }
        }
    }
    for (int i = 0; i < MAX_DISPAROS; i++)
    {
        if (jugador->disparo[i] != NULL)
        {
            hardware->dibujarOculta(*jugador->disparo[i]);
        }
    }
    for (int i = 0; i < MAX_DISPAROS; i++)
    {
    	if (disparosEnemigos[i] != NULL)
    	{
			hardware->dibujarOculta(*disparosEnemigos[i]);
    	}
    }
    hardware->visualizarOculta();
}

/**
 * Captura las teclas del teclado.
 *
 * Función empleada para capturar las teclas del teclado.
 *
 * - Si se pulsa ESCAPE entonces se sale del juego.
 * - Si se pulsa la tecla IZQUIERDA se llama a la función moverIzquierda
 * de la clase jugador, para que el jugador se desplace a la izquierda.
 * - Si se pulsa la tecla DERECHA se llama a la función moverDerecha
 * de la clase jugador, para que el jugador se desplace a la derecha.
 * - Si se pulsala tecla ESPACIO se llama a la función disparar
 * de la clase jugador para que dispare.
 */

void capturaTeclado()
{
    if (hardware->comprobarTecla(KEY_ESC))
        juego->setTerminado(true);
    if (hardware->comprobarTecla(KEY_LEFT))
        jugador->moverIzquierda(DESPLAZAMIENTO_IZQUIERDA);
    if (hardware->comprobarTecla(KEY_RIGHT))
        jugador->moverDerecha(DESPLAZAMIENTO_DERECHA);
    //Esto se hace para que se tenga que soltar la tecla
    //para disparar otra vez, lo que hace es comprobar si
    //la tecla ha sido presionada y posteriormente soltada
    //Por último actualiza el estado de todas las teclas.
    if (key[KEY_SPACE] && !oldkeys[KEY_SPACE])
        jugador->disparar();
    for (int i = 0 ; i < KEY_MAX ; ++i)
        oldkeys[i] = key[i];
}

/**
 * Actualiza los disparos, tanto del juegador, como de los enemigos.
 *
 * Función empleada para actualizar la posición de los disparos
 * tanto del juegador como de los enemigos.
 *
 * Lo primero que hace es recorrer todos los disparos del jugador
 * que se encuentren en la pantalla (!=NULL) y actualiza su
 * posición, si los disparos han salido por la parte superior de
 * la pantalla entonces los pone a NULL, borra el objeto y resta
 * 1 al número de disparos que ha efectuado el juegador.
 *
 * A continuación hace lo mismo con los disparos de los enemigos,
 * con la diferencia que no comprueba si el disparo se ha salido
 * por la parte superior de la pantalla, sin que hace la comprobación
 * con la parte inferior de la pantalla.
 */

void actualizarDisparos()
{
	//Actualizar los disparos del jugador
    for (int i = 0; i < MAX_DISPAROS; i++)
    {
        if (jugador->disparo[i] != NULL)
        {
            jugador->disparo[i]->actualizarPosicion(jugador->disparo[i]->getX(), jugador->disparo[i]->getY()-VELOCIDAD_DISPARO);
            if (jugador->disparo[i]->getY() < 0)
            {
                jugador->disparo[i] = NULL;
                delete jugador->disparo[i];
                jugador->disparos--;

            }
        }
    }
    //Actualizar los disparos de los enemigos
    for (int i = 0; i < MAX_DISPAROS; i++)
        {
            if (disparosEnemigos[i] != NULL)
            {
                disparosEnemigos[i]->actualizarPosicion(disparosEnemigos[i]->getX(), disparosEnemigos[i]->getY()+VELOCIDAD_DISPARO);
                if (disparosEnemigos[i]->getY() > ALTO_PANTALLA)
                {
                    disparosEnemigos[i] = NULL;
                    delete disparosEnemigos[i];
                }
            }
        }
}

/**
 * Devuelve el último enemigo por la derecha.
 *
 * Función auxiliar usada por moverEnemigos que devuelve el
 * último enemigo por la derecha.
 *
 * @return Devuelve el último enemigo por la derecha si quedan
 * enemigos y NULL en caso contrario.
 */

Enemigo* ultimoEnemigoDerecha()
{
    if (enemigos != 0)
    {
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 4; j >= 0; j--)
            {
                if (enemigo[j][i] != NULL)
                    return enemigo[j][i];
            }
        }
    }
    return NULL;
}

/**
 * Devuelve el último enemigo por la izquierda.
 *
 * Función auxiliar usada por moverEnemigos que devuelve el
 * último enemigo por la izquierda.
 *
 * @return Devuelve el último enemigo por la izquierda si quedan
 * enemigos y NULL en caso contrario.
 */

Enemigo* ultimoEnemigoIzquierda()
{
    if (enemigos != 0)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (enemigo[j][i] != NULL)
                    return enemigo[j][i];
            }
        }
    }
    return NULL;
}

/*
 * Mueve a los enemigos.
 *
 * Lo que hace es recorrer todos los enemigos que estén presentes
 * en la pantalla (!=NULL) y llama a la función mover, pasandole la
 * dirección y un booleano que indica si hay que actualizar la coordenada
 * Y, de la clase Enemigo.
 *
 * A continuación lo que hace es comprobar si el último enemigo de la derecha
 * ha llegado al final de la pantalla por la derecha, si lo ha hecho, se pone
 * a True actualiuzarY y se cambia la dirección.
 *
 * La siguiente comprobación es idéntica pero para el caso de que el último
 * enemigo de la izquierda llegue al final de la pantalla por la izquierda.
 *
 * Si no se da ningún caso se pone a False actualizarY de manera que no se
 * debe actualizar la posición Y de los enemigos.
 */

void moverEnemigos()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (enemigo[i][j] != NULL)
            {
                enemigo[i][j]->mover(direccion, actualizarY);
            }
        }
    }
    if (ultimoEnemigoDerecha() != NULL or ultimoEnemigoIzquierda() != NULL)
    {
        if (ultimoEnemigoDerecha()->getX() > (ANCHO_PANTALLA - ultimoEnemigoDerecha()->getImagen()->w))
        {
            actualizarY = true;
            direccion = -1;
        }
        else if (ultimoEnemigoIzquierda()->getX() < 0)
        {
            actualizarY = true;
            direccion = 1;
        }
        else
        {
            actualizarY = false;
        }
    }
}

/**
 * Comprueba si se ha producido una colisión.
 *
 * Esta función recorre todos los disparos que estén en la
 * pantalla (!=NULL) y comprueba si se ha chocado con alguno
 * de los enemigos.
 *
 * En el caso de que se haya producido una colisión lo que hace
 * es incrementar la puntuación del juegador, elimina la imagen
 * asociada al enemigos, elimina la imagen asociada al disparo,
 * pone a NULL el enemigo y el disparo, borra los objetos enemigo
 * y disparo, reduce en uno los disparos y los enemigos y comprueba
 * si enemigo = 0, en el caso de que sea cierto se acaba el juego.
 *
 * En siguiente if lo que hace es comprobar si se ha producido
 * alguna colisión de los disparos de los enemigos con el
 * propio jugador. Si se ha producido una colisión y al jugador
 * le quedan 0 vidas entonces se acaba el juego, sino, se le
 * resta una vida al jugador y se vuelven a cargar los elementos
 * en la pantalla.
 */

void comprobarColisiones()
{
    for (int i = 0; i < MAX_DISPAROS; i++)
    {
        if (jugador->disparo[i] != NULL)
        {
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 10; k++)
                {
                    if ((enemigo[j][k] != NULL) && (jugador->disparo[i] != NULL))
                    {
                        if (jugador->disparo[i]->colisionCon(*enemigo[j][k]))
                        {
                        	juego->incrementarPuntuacion(enemigo[j][k]->getPuntuacion());
                        	enemigo[j][k]->eliminarGrafico(enemigo[j][k]->getImagen());
                            jugador->disparo[i]->eliminarGrafico(jugador->disparo[i]->getImagen());
                            enemigo[j][k] = NULL;
                            jugador->disparo[i] = NULL;
                            delete jugador->disparo[i];
                            delete enemigo[j][k];
                            jugador->disparos--;
                            enemigos--;
                            if (enemigos == 0)
                            	juego->setTerminado(true);
                        }
                    }
                }
            }
        }
        if (disparosEnemigos[i] != NULL)
        {
        	if (disparosEnemigos[i]->colisionCon(*jugador))
        	{
        		if(juego->getVidas() == 0)
        			juego->setTerminado(true);
        		else
        		{
					juego->setVidas(juego->getVidas()-1);
					enemigos = 50;
        		}
        		cargarElementos();
        	}
        }
    }
}

/**
 * Comprueba si el juego ha terminado.
 *
 * Función que recorre todos los enemigos que sigan vivos (!=NULL)
 * y comrpueba si los enemigos te han alcanzado. Si te han alcanzado
 * entonces si te quedan 0 vidas se acabó el juego sino, te quita una
 * vida y vuelve a cargar todos los elementos del juego
 */

void comprobarFinJuego()
{
     for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (enemigo[i][j] != NULL)
            {
                if (enemigo[i][j]->getY() >= jugador->getY()-(jugador->getImagen()->h+15))
                {
                    if(juego->getVidas() == 0)
                        juego->setTerminado(true);
                    else
                    {
                        juego->setVidas(juego->getVidas()-1);
                        enemigos = 50;
                    }
                    cargarElementos();
                }
            }
        }
    }
}

/**
 * Incrementa el contador fps para la velocidad del juego.
 */

void IncFps() { fps++; }

/**
 * Función principal donde se lleva a cabo se encuentra el bucle del juego.
 * Aquí se inicializa el generador de números aleatorios, para el algoritmo
 * de los disparos de los enemigos.
 *
 * Se crean los objetos Hardware (para manejo de la memoria de video),
 * juego (que guarda la puntuación, las vidas, y demás).
 *
 * Se cargan los elementos iniciales del juego con la función cargarElementos().
 *
 * A continuación ya empieza el bucle principal que se ejecutará mientras el juego
 * no acabe. Dentro del bucle se protege la variable fps y la función IncFps, que sirven
 * para controlar el FPS y a continuación se incia un temporizador.
 *
 * Lo siguiente que se hace es capturar las teclas del teclado, luego hace que los
 * enemigos disparen, a continuación mueve a los enemigos, actualiza todos los disparos
 * y comprueba las colisiones.
 *
 * A continuación actualiza las posiciones de todos los objetos en pantalla mediante la
 * función dibuja().
 *
 * Por último muestra información del juego como las vidas que quedan o la puntuación y
 * comprueba si el juego ha terminado, si ha terminado sale del bucle y sino sigue en él.
 *
 * Fuera el bucle ya borra la pantalla y el buffer de teclado y comprueba por que se ha
 * terminado el juego. Si quedaban 0 enemigos significa que has ganado, sino significa
 * que te han matado a ti y por tanto has perdido.
 */

int main(){
	srand(time(NULL));
    hardware = new Hardware(ANCHO_PANTALLA,ALTO_PANTALLA);
    textout_ex(screen, font, "Programado por Ángel Luis.Pulse cualquier tecla",ANCHO_PANTALLA/2-170, ALTO_PANTALLA/2, makecol(150,150,255), 1);
    hardware->esperarTecla();
    juego = new Juego(3);
    cargarElementos();
    while (!juego->isTerminado())
    {
        LOCK_VARIABLE( fps );
        LOCK_FUNCTION( IncFps );
        install_int_ex( IncFps, BPS_TO_TIMER(15) );
        capturaTeclado();
        disparosDeEnemigos();
        moverEnemigos();
        actualizarDisparos();
        comprobarColisiones();
        dibujar();
        mostrarInformacion();
        //hardware->pausa(VELOCIDAD_JUEGO);
        comprobarFinJuego();
    }
    clear_bitmap(screen);
    clear_keybuf();
    if (enemigos != 0)
    {
        textout_ex(screen, font, "Te han matado :( Juego terminado. Pulsa cualquier tecla para salir",ANCHO_PANTALLA/2-230, ALTO_PANTALLA/2, makecol(150,150,255), 1);
        hardware->esperarTecla();
    }
    else
    {
        textprintf_ex(screen, font, ANCHO_PANTALLA/2-250, ALTO_PANTALLA/2, makecol(255,255,255), 1, "Felicidades, mataste a todos! :) Tienes una puntuación de %d.", juego->getPuntuacion());
        //textout(screen, font, "Felicidades, mataste a todos! :) Tienes una puntuación de. Pulsa cualquier tecla para salir",ANCHO_PANTALLA/2-230, ALTO_PANTALLA/2, makecol(150,150,255));
        hardware->esperarTecla();
    }
    return 0;
}
//Esta linea indica que termina el programa de Allegro siempre debe ir en el main.
END_OF_MAIN();
