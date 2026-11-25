# Sistemas Informáticos industriales - Prácticas

Repositorio personal de prácticas de la asignatura de 4º año Sistemas
infórmaticos industriales, curos 2026-2027

Autor: David San Román González
Mátricula: 57665

## Descripción del proyecto

En este repositorio se va a realizar el desarrollo progresivo de un juego
 de tenis

## Práctica uno: Entorno de desarrollo bajo Linux

Configuración del entorno (Git, CMake, Make) y primera modificación del código:

 movimiento de raquetas y pelotas

## Práctica dos: Comunicación mediante tuberías con nombre (FIFO)

Se añade un nuevo programa, el logger, que se comunica con el juego mediante una FIFO:

- El logger crea la FIFO, la abre en modo lectura e imprime por pantalla los mensajes que recibe.
- El juego abre la FIFO en modo escritura y envía un mensaje cada vez que un jugador marca un punto.
- Cuando un jugador llega a 3 puntos, el juego termina y el logger se cierra automáticamente.

Para ejecutarlo hay que lanzar primero el logger y después el juego, en dos terminales:

    ./logger
    ./tenis


## Práctica tres: Comunicación mediante archivo proyectado en memoria

Se añade un nuevo programa en donde hay un bot que controla automáticamente la raqueta del jugador 1:

- El juego crea un fichero proyectado en memoria con mmap, que tendrá la posición de la pelota, la de la raqueta y la acción a realizar.
- El bot abre ese mismo fichero, compara la posición de la pelota con la de la raqueta y decide si subir, bajar o no hacer nada.
- El juego lee la acción del bot en cada instante y mueve la raqueta.

Para ejecutarlo hay que lanzar en este orden, en tres terminales:

    ./logger
    ./tenis
    ./bot
