#include "../include/Hardware.h"
#include "iostream"
#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include "../include/ElementoGrafico.h"
#include <math.h>
#include <string>

#include <allegro.h>

Hardware::Hardware(int anchoPantalla, int altoPantalla)
{
    cout << "Inicializando Allegro..." << endl;
    allegro_init();
    cout << "Inicializando el teclado..." << endl;
    install_keyboard();
    cout << "Inicializando el temporizador..." << endl;
    install_timer();
    this->anchoPantalla = anchoPantalla;
    this->altoPantalla = altoPantalla;

    set_color_depth(32);
    if (set_gfx_mode(GFX_SAFE, anchoPantalla, altoPantalla, 0, 0) != 0) {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Incapaz de entrar a modo grafico\n%s\n", allegro_error);
        exit( 1 );
    }

    pantallaOculta = create_bitmap(anchoPantalla, altoPantalla);
}

bool Hardware::comprobarTecla(int codigo)
{
    return key[codigo];
}

int Hardware::esperarTecla()
{
    return readkey() >> 8;
}

bool Hardware::algunaTeclaPulsada()
{
    return keypressed;
}

void Hardware::borrarOculta()
{
    clear_bitmap(pantallaOculta);
}

void Hardware::dibujarOculta(ElementoGrafico e)
{
    draw_sprite( pantallaOculta, e.getImagen(), e.getX(), e.getY() );
}

void Hardware::visualizarOculta()
{
    // Sincronizo con el barrido para evitar parpadeos
    // y vuelco la pantalla oculta
    vsync();
    blit(pantallaOculta, screen, 0, 0, 0, 0,
      anchoPantalla, altoPantalla);
}

void Hardware::pausa(long ms)
{
    rest(ms);
}
