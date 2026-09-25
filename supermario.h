//
// Grupo 4
// Integrantes:
// Sebastian Chipana - 20261PRECS01009
// Keith Salas - 20261PRECIA1021
// Vania Padilla - 2023200
// Gabriel Salazar - 20261PRECS01097
//

#ifndef SUPERMARIO_H
#define SUPERMARIO_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "colores.h" // Incluye la cabecera personalizada para los códigos ANSI de colores

// Configuraciones del mundo
const int FILAS = 50;
const int COLUMNAS = 120;
const std::string RESET = "\033[0m";

// Dimensiones y declaración de sprites

// Dimensiones del sprite de la moneda
const int ALTO_MONEDA = 7;
const int ANCHO_MONEDA = 7;
extern const int moneda[ALTO_MONEDA][ANCHO_MONEDA];

// Dimensiones del sprite del arbusto
const int ALTO_ARBUSTO = 7;
const int ANCHO_ARBUSTO = 8;
extern const int arbusto[ALTO_ARBUSTO][ANCHO_ARBUSTO];

// Dimensiones del sprite del signo
const int ALTO_SIGNO = 8;
const int ANCHO_SIGNO = 9;
extern const int signo[ALTO_SIGNO][ANCHO_SIGNO];

// Dimensiones del sprite del ladrillo
const int ALTO_LADRILLO = 8;
const int ANCHO_LADRILLO = 9;
extern const int ladrillo[ALTO_LADRILLO][ANCHO_LADRILLO];

// Dimensiones del sprite de mario
const int ALTO_MARIO = 16;
const int ANCHO_MARIO = 12;
extern const int mario[ALTO_MARIO][ANCHO_MARIO];

// Dimensiones del sprite del goomba
const int ALTO_GOOMBA = 16;
const int ANCHO_GOOMBA = 16;
extern const int goomba[ALTO_GOOMBA][ANCHO_GOOMBA];

// Declaración de funciones del videojuego

// Dibuja un sprite específico dentro de la matriz del mundo en las coordenadas indicadas.
// Recibe 'elemento' como un puntero a constante (const int*) para proteger la matriz original.
void dibujar_elemento(int** mundo, int origenFila, int origenColumna, const int* elemento, int alto, int ancho);

// Limpia los píxeles ocupados por Mario en su posición actual asignándolos a 0 (vacío).
void borra_player(int** mundo, int origenFila, int origenColumna);

// Limpia los píxeles de una moneda recolectada en la matriz del mundo.
void borrar_moneda(int** mundo, int origenFila, int origenColumna);

// Asigna memoria dinámica para la matriz del mundo 2D e inicializa el suelo y los elementos estáticos (arbustos, bloques).
int** crear_world();

// Actualiza visualmente un bloque de signo/ladrillo a color negro tras ser golpeado.
void pintar_bloque_negro(int** mundo, int f_impacto, int c_impacto, int &f_bloque, int &c_bloque);

// Verifica si Mario colisiona con un bloque de signo (valor 3) al saltar, gestionando la aparición de la moneda.
bool collect_coins(int** mundo, int marioFilaAire, int marioColumnaAire, int &monedaFila, int &monedaColumna);

// Detecta colisiones entre los bordes de la hitbox de Mario y la hitbox del Goomba para terminar el juego.
bool check_game_over(int marioF, int marioC, int goombaF, int goombaC);

// Procesa el comando de movimiento del usuario, valida los límites del mapa, y actualiza coordenadas y recolección de monedas.
bool move_player(int** mundo, int &marioFila, int &marioColumna, std::string option, int &numCoins, int &monedaFila, int &monedaColumna);

// Renderiza toda la matriz del mundo en la consola aplicando los colores ANSI. Utiliza doble búfer/limpieza de pantalla.
void draw_world(int **world, int coins, int marioF, int marioC, bool esInit = false);

#endif