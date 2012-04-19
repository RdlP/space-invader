/**
* @mainpage Sobre Space Invader
* @section intro_sec Introducción
*
* Este mini-proyecto ha salido de una noche de aburrimiento entre estudio y estudio.
* La idea es recrear el mítico juego space invader sobre las librerias gráficas
* Allegro 4.2 (http://alleg.sourceforge.net/) y usando  el lenguaje de programación C++,
* haciendo uso de la programación orientada a objetos.
*
* @section notas_sec NOTAS
*
* Este proyecto está desarrollado para ser ejecutado tanto en sistemas Linux como en Windows,
* pero se hará referencia en todo momento a comandos y herramientas de Linux y no de Windows.
* No se asegura el correcto funcionamiento del juego en Windows ni en Linux, al menos en las
* fases iniciales del desarrollo. Otras notas a tener en cuenta:
*
* - Realizado con Linux Mint Lisa 12
* - Compilador g++ 4.6.1
* - Generador de documentación: Doxygen 1.7.4
* - IDE empleado: Eclipse 3.7.0
* - Versión de las librerías Allegro usadas: 4.2
* - Sistema de Control de Versiones usado: GIT
*
* <b>La documentación puede no reflejar fielmente el desarrollo real del proyecto, puesto
* que la documentación no se genera en cada cambio menor del proyecto, sino que se genera
* cuando haya cambios importante en el mismo</b>
*
* @section pre_sec Pasos preliminares a la compilación
*
* Para poder compilar el proyecto antes debes instalar el código de la librería Allegro mediante
* el siguiente comando: apt-get install liballegro4.2-dev (para sistemas basados en Debian)
*
* @section comp_sec Compilación
*
* Para compilar el proyecto debes ejecutar el siguiente comando en la carpeta raiz del proyecto:
* - ./Makefile.sh
*
* @section eje_sec Ejecución
*
* Para ejecutarlo hay que ejecutar el archivo <b>space_indaver</b>
*
* @section teclas_sec Teclas de Juego
*
* - Teclas de dirección izquierda/derecha para moverse hacia los lados
* - Espacio para disparar (un máximo de 5 disparos a la vez)
* - Escape para salir del juego
*
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
*
* @version 0.1.1
*
* @author Ángel Luis Perales Gómez
*
* @date Abril de 2012
*
* @todo Más variedad de enemigos <b>HECHO</b>
* @todo Más variedad de disparos
* @todo Que los enemigos puedan atacar <b>HECHO</b>
* @todo Mostrar la puntuación en la pantalla del juego <b>HECHO</b>
* @todo Mostrar el nivel en el que se encuentra en la pantalla del juego
* @todo Añadir sonido al juego
*
* @bug Solucionar la comprobación de desplazamiento vertical de los enemigos. Actualmente
* se comprueba con el enemigo[4][9] y el enemigo[4][0] pero ¿qué pasa si ese enemigo
* ha sido eliminado (puesto a NULL)? <b>CORREGIDO</b>
* @bug Solucionar problemas con los disparos. ¿Por qué en ciertas ocasiones no puede disparar más?
* <b>CORREGIDO</b> (Los disparos que salían fuera de la pantalla getY()<0 no se eliminaban y si desaparecian
* todos los disparos por el final de la pantalla no se podía disparar más)
* @bug Solucionar diversos errores con la velocidad de juego. Por ejemplo pulsas una vez espacio y
* sin embargo te detecta que has pulsado más de una vez, realizando más de un disparo a la vez <b>CORREGIDO</b>
*
*/

#define ALTO_PANTALLA 600
#define ANCHO_PANTALLA 800
#define DESPLAZAMIENTO_IZQUIERDA 8
#define DESPLAZAMIENTO_DERECHA 8
#define DESPLAZAMIENTO_ENEMIGO 1
#define VELOCIDAD_DISPARO 5
#define VELOCIDAD_JUEGO 30
#define MAX_DISPAROS 1000
