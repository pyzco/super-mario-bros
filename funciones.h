//
// Grupo 4
// Integrantes:
// Sebastian Chipana - 20261PRECS01009
// Keith Salas - 20261PRECIA1021
// Vania Padilla - 2023200
// Gabriel Salazar - 20261PRECS01097
//

#ifndef SUPER_MARIO_BROS_FUNCIONES_H
#define SUPER_MARIO_BROS_FUNCIONES_H

#include <iostream>
#include <string>


///////////////////////////////////
/// Settings
///////////////////////////////////

inline const int FILAS = 50;
inline const int COLUMNAS = 120;

extern const std::string RESET;
extern const std::string FONDO_BLANCO;
extern const std::string FONDO_ROJO;
extern const std::string FONDO_VERDE;
extern const std::string FONDO_AMARILLO;
extern const std::string FONDO_NEGRO;
extern const std::string FONDO_PIEL;
extern const std::string COL_LIGHTBLUE;
extern const std::string COL_LIGHTYELLOW;
extern const std::string FONDO_MARRON;

extern std::string colores[9];

///////////////////////////////////
/// Elementos del mundo
///////////////////////////////////

const int ALTO_ARBUSTO = 7;
const int ANCHO_ARBUSTO = 8;

inline int arbusto[ALTO_ARBUSTO][ANCHO_ARBUSTO] = {
    {0, 0, 0, 2, 2, 0, 0, 0},
    {0, 0, 2, 2, 2, 2, 0, 0},
    {0, 2, 2, 2, 2, 2, 2, 0},
    {2, 2, 2, 2, 2, 2, 2, 2},
    {2, 2, 2, 2, 2, 2, 2, 2},
    {2, 2, 2, 2, 2, 2, 2, 2},
    {2, 2, 2, 2, 2, 2, 2, 2}
};

const int ALTO_SIGNO = 8;
const int ANCHO_SIGNO = 9;

inline int signo[ALTO_SIGNO][ANCHO_SIGNO] = {
    {3, 3, 3, 3, 3, 3, 3, 3, 3},
    {3, 3, 3, 4, 4, 4, 3, 3, 3},
    {3, 3, 4, 3, 3, 3, 4, 3, 3},
    {3, 3, 3, 3, 3, 4, 4, 3, 3},
    {3, 3, 3, 3, 4, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 4, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3, 3, 3, 3}
};

const int ALTO_LADRILLO = 8;
const int ANCHO_LADRILLO = 9;

inline int ladrillo[ALTO_LADRILLO][ANCHO_LADRILLO] = {
    {1, 1, 1, 1, 4, 1, 1, 1, 1},
    {1, 1, 1, 1, 4, 1, 1, 1, 1},
    {4, 4, 4, 4, 4, 4, 4, 4, 4},
    {1, 1, 4, 1, 1, 1, 4, 1, 1},
    {1, 1, 4, 1, 1, 1, 4, 1, 1},
    {4, 4, 4, 4, 4, 4, 4, 4, 4},
    {1, 1, 1, 1, 4, 1, 1, 1, 1},
    {1, 1, 1, 1, 4, 1, 1, 1, 1}
};

const int ALTO_MONEDA = 7;
const int ANCHO_MONEDA = 7;

const int moneda[ALTO_MONEDA][ANCHO_MONEDA] = {
    {0, 0, 3, 3, 3, 0, 0},
    {0, 3, 3, 4, 3, 3, 0},
    {3, 3, 3, 4, 3, 3, 3},
    {3, 3, 3, 4, 3, 3, 3},
    {3, 3, 3, 4, 3, 3, 3},
    {0, 3, 3, 4, 3, 3, 0},
    {0, 0, 3, 3, 3, 0, 0}
};

//////////////////////////////////////
/// Personajes
//////////////////////////////////////

const int ALTO_MARIO = 16;
const int ANCHO_MARIO = 12;

inline int mario[ALTO_MARIO][ANCHO_MARIO] = {
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 4, 4, 4, 5, 5, 4, 5, 0, 0, 0},
    {0, 4, 5, 4, 5, 5, 5, 4, 5, 5, 5, 0},
    {0, 4, 5, 4, 4, 5, 5, 5, 4, 5, 5, 5},
    {0, 4, 4, 5, 5, 5, 5, 4, 4, 4, 4, 0},
    {0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, 0},
    {0, 0, 1, 1, 6, 1, 1, 6, 1, 1, 0, 0},
    {0, 1, 1, 1, 6, 1, 1, 6, 1, 1, 1, 0},
    {1, 1, 1, 1, 6, 6, 6, 6, 1, 1, 1, 1},
    {5, 5, 1, 6, 7, 6, 6, 7, 1, 1, 5, 5},
    {5, 5, 5, 6, 6, 6, 6, 6, 5, 5, 5, 5},
    {5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5},
    {0, 0, 6, 6, 6, 0, 0, 6, 6, 6, 0, 0},
    {0, 0, 4, 4, 0, 0, 0, 0, 4, 4, 0, 0},
    {0, 4, 4, 4, 0, 0, 0, 0, 4, 4, 4, 0}
};


const int ALTO_GOOMBA = 16;
const int ANCHO_GOOMBA = 16;

inline int goomba[ALTO_GOOMBA][ANCHO_GOOMBA] = {
    {0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 0},
    {0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0},
    {0, 0, 8, 4, 4, 8, 8, 8, 8, 8, 8, 4, 4, 8, 0, 0},
    {0, 8, 8, 8, 5, 4, 8, 8, 8, 8, 4, 5, 8, 8, 8, 0},
    {0, 8, 8, 8, 5, 4, 4, 4, 4, 4, 4, 5, 8, 8, 8, 0},
    {8, 8, 8, 8, 5, 4, 5, 8, 8, 5, 4, 5, 8, 8, 8, 8},
    {8, 8, 8, 8, 5, 5, 5, 8, 8, 5, 5, 5, 8, 8, 8, 8},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
    {0, 8, 8, 8, 8, 5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 0},
    {0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0},
    {0, 0, 0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 0, 0, 0},
    {0, 0, 4, 4, 4, 4, 5, 5, 5, 5, 4, 4, 4, 4, 0, 0},
    {0, 0, 4, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 0, 0},
    {0, 0, 0, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 0, 0, 0}
};


///////////////////////////////////
/// Funciones de configurción del mundo
///////////////////////////////////

void colocar_arbusto(int** mundo, int origenFila, int origenColumna);

void colocar_signo(int** mundo, int origenFila, int origenColumna);

void colocar_ladrillo(int** mundo, int origenFila, int origenColumna);


///////////////////////////////////
/// Funciones de configuración de personajes
///////////////////////////////////

void draw_player(int** mundo, int origenFila, int origenColumna);

void draw_whomp(int** mundo, int origenFila, int origenColumna);


///////////////////////////////////
/// Funciones para generar el mundo
///////////////////////////////////

int** crear_world();
int** crear_world_copia();

void draw_world(int **world, int coins);


///////////////////////////////////
/// Funciones para mecanicas del juego
///////////////////////////////////

void pintar_bloque_negro(int** mundo, int f_impacto, int c_impacto, int** matrizCopia);

bool collect_coins(int** mundo, int marioFilaAire, int marioColumnaAire, int** matrizCopia);

bool check_game_over(int marioF, int marioC, int goombaF, int goombaC);


///////////////////////////////////
/// Funciones para el funcionamiento del jugador
///////////////////////////////////

void borra_player(int** mundo, int origenFila, int origenColumna, int** matrizCopia);

void move_player(int** mundo, int &marioFila, int &marioColumna, std::string option, int &numCoins, int** matrizCopia);

bool movimiento_es_valido(int marioColumna, std::string option);

#endif //SUPER_MARIO_BROS_FUNCIONES_H










