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

// DEFINICIÓN DE SPRITES
// Se definen los valores de los píxeles para cada elemento visual del juego.
// Los números corresponden a los códigos de color en la función colorANSI().


// Sprite Arbusto
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


// Sprite Signo
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


// Sprite Ladrillo
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


// Sprite Moneda
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

// Sprite Mario
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


// Sprite Goomba
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


// Declaración de funciones del videojuego

///////////////////////////////////////////
/// Funciones de configuración del mundo
///////////////////////////////////////////

// Dibuja un sprite específico dentro de la matriz del mundo en las coordenadas indicadas.
// Recibe 'elemento' como un puntero a constante (const int*) para proteger la matriz original.
void dibujar_elemento(int** mundo, int origenFila, int origenColumna, const int* elemento, int alto, int ancho);

// Asigna memoria dinámica para la matriz del mundo 2D e inicializa el suelo y los elementos estáticos (arbustos, bloques).
int** crear_world();
// Crea una copia del mundo original para poder restaurar los píxeles de Mario al moverse.
int** crear_world_copia();

// Renderiza toda la matriz del mundo en la consola aplicando los colores ANSI. Utiliza doble búfer/limpieza de pantalla.
void draw_world(int **world, int coins);


///////////////////////////////////
/// Funciones para mecanicas del juego
///////////////////////////////////

// Actualiza visualmente un bloque de signo/ladrillo a color negro tras ser golpeado.
void pintar_bloque_negro(int** mundo, int f_impacto, int c_impacto, int** matrizCopia);

// Verifica si Mario colisiona con un bloque de signo (valor 3) al saltar, gestionando la aparición de la moneda.
bool collect_coins(int** mundo, int marioFilaAire, int marioColumnaAire, int** matrizCopia);

// Detecta colisiones entre los bordes de la hitbox de Mario y la hitbox del Goomba para terminar el juego.
bool check_game_over(int marioF, int marioC, int goombaF, int goombaC);


///////////////////////////////////
/// Funciones para el funcionamiento del jugador
///////////////////////////////////

// Limpia los píxeles ocupados por Mario en su posición actual asignándolos a 0 (vacío).
void borra_player(int** mundo, int origenFila, int origenColumna, int** matrizCopia);

// Limpia los píxeles de una moneda recolectada en la matriz del mundo.
void borrar_moneda(int** mundo, int origenFila, int origenColumna);

// Procesa el comando de movimiento del usuario, valida los límites del mapa, actualiza coordenadas y recolección de monedas.
void move_player(int** mundo, int &marioFila, int &marioColumna, std::string option, int &numCoins, int** matrizCopia, int &monedaFila, int &monedaColumna);

bool movimiento_es_valido(int marioColumna, std::string option);

#endif //SUPER_MARIO_BROS_FUNCIONES_H










