#include <allegro.h>
#include "include/Hardware.h"
#include "include/Definiciones.h"
#include "include/ElementoGrafico.h"
#include "include/Juego.h"
#include "include/Jugador.h"
#include "include/Enemigo.h"
#include "include/Disparo.h"
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

void disparosDeEnemigos()
{
	int num;
	for (int i = 0; i < 5; i++)
	    {
	        for (int j = 0; j < 10; j++)
	        {
	        	num=rand()%801; //Numero aleatorio entre 0 y 500
	        	if ((num == i*j) and (enemigo[i][j] != NULL))
	        	{
	        		int k = 0;
	        		while (disparosEnemigos[k] != NULL) k++;
	        		disparosEnemigos[k] = enemigo[i][j]->disparar();
	        	}
	        }
	    }
}

void cargarElementos()
{
	char imagenJugador[23]="./resource/jugador.bmp";
	char imagenEnemigo[23]="./resource/enemigo.bmp";
    jugador = new Jugador(ANCHO_PANTALLA/2,ALTO_PANTALLA-75, imagenJugador);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            enemigo[i][j] = new Enemigo(j*70, i*70, imagenEnemigo);
        }
    }
    direccion = 1;
}

void mostrarInformacion()
{
    textprintf_ex(screen, font, 5, ALTO_PANTALLA-20, makecol(255,255,255), 1, "Vidas: %d Puntuación: %d", juego->getVidas(), juego->getPuntuacion());
}

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

void capturaTeclado()
{
    if (hardware->comprobarTecla(KEY_ESC))
        juego->setTerminado(true);
    if (hardware->comprobarTecla(KEY_LEFT))
        jugador->moverIzquierda(DESPLAZAMIENTO_IZQUIERDA);
    if (hardware->comprobarTecla(KEY_RIGHT))
        jugador->moverDerecha(DESPLAZAMIENTO_DERECHA);
    if (key[KEY_SPACE] && !oldkeys[KEY_SPACE])
        jugador->disparar();
    for (int i = 0 ; i < KEY_MAX ; ++i)
        oldkeys[i] = key[i];
}

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
                    //jugador->disparos--;
                }
            }
        }
}

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

                                enemigo[j][k]->eliminarGrafico(enemigo[j][k]->getImagen());
                                jugador->disparo[i]->eliminarGrafico(jugador->disparo[i]->getImagen());
                                enemigo[j][k] = NULL;
                                jugador->disparo[i] = NULL;
                                delete jugador->disparo[i];
                                delete enemigo[j][k];
                                jugador->disparos--;
                                juego->incrementarPuntuacion(20);
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

void IncFps() { fps++; }

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
    //std::cout << "HAS ACABADO EL JUEGO\n";
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
