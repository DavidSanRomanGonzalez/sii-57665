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
