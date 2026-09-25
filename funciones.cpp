//
// Grupo 4
// Integrantes:
// Sebastian Chipana - 20261PRECS01009
// Keith Salas - 20261PRECIA1021
// Vania Padilla - 2023200
// Gabriel Salazar - 20261PRECS01097
//

#include "funciones.h"
#include <cstdlib>
#include <thread>
#include <chrono>

///////////////////////////////////
/// Elementos de configuración de mundo
///////////////////////////////////

const std::string RESET          = "\x1b[0m";
const std::string FONDO_BLANCO   = "\x1b[47m";
const std::string FONDO_ROJO     = "\x1b[41m";
const std::string FONDO_VERDE    = "\x1b[42m";
const std::string FONDO_AMARILLO = "\x1b[43m";
const std::string FONDO_NEGRO    = "\x1b[40m";
const std::string FONDO_PIEL     = "\x1b[107m";
const std::string COL_LIGHTBLUE  = "\x1b[104m";
const std::string COL_LIGHTYELLOW = "\x1b[103m";
const std::string FONDO_MARRON   = "\x1b[43;2;139;69;19m";

std::string colores[9] = {
    FONDO_PIEL, FONDO_ROJO, FONDO_VERDE, FONDO_AMARILLO, FONDO_NEGRO, FONDO_BLANCO,
    COL_LIGHTBLUE, COL_LIGHTYELLOW, FONDO_MARRON };

    
///////////////////////////////////
/// Funciones de configuración del mundo
///////////////////////////////////

void colocar_arbusto(int** mundo, int origenFila, int origenColumna) {
    for (int f = 0; f < ALTO_ARBUSTO; f++) {
        for (int c = 0; c < ANCHO_ARBUSTO; c++) {
            if (arbusto[f][c] == 2) {
                mundo[origenFila + f][origenColumna + c] = 2;
            }
        }
    }
}

void colocar_signo(int** mundo, int origenFila, int origenColumna) {
    for (int f = 0; f < ALTO_SIGNO; f++) {
        for (int c = 0; c < ANCHO_SIGNO; c++) {
            if (signo[f][c] != 0) {
                mundo[origenFila + f][origenColumna + c] = signo[f][c];
            }
        }
    }
}

void colocar_ladrillo(int** mundo, int origenFila, int origenColumna) {
    for (int f = 0; f < ALTO_LADRILLO; f++) {
        for (int c = 0; c < ANCHO_LADRILLO; c++) {
            if (ladrillo[f][c] != 0) {
                mundo[origenFila + f][origenColumna + c] = ladrillo[f][c];
            }
        }
    }
}

///////////////////////////////////
/// Funciones de personajes
///////////////////////////////////

void draw_player(int** mundo, int origenFila, int origenColumna) {
    for (int f = 0; f < ALTO_MARIO; f++) {
        for (int c = 0; c < ANCHO_MARIO; c++) {
            if (mario[f][c] != 0) {
                mundo[origenFila + f][origenColumna + c] = mario[f][c];
            }
        }
    }
}

void draw_whomp(int** mundo, int origenFila, int origenColumna) {
    for (int f = 0; f < ALTO_WHOMP; f++) {
        for (int c = 0; c < ANCHO_WHOMP; c++) {
            if (whomp[f][c] != 0) {
                mundo[origenFila + f][origenColumna + c] = whomp[f][c];
            }
        }
    }
}

///////////////////////////////////
/// Generar mundo
//////////////////////////////////////

int** crear_world(){
    int **mundo = new int*[FILAS];

    for (int fila = 0; fila < FILAS; fila++){
        mundo[fila] = new int[COLUMNAS];
        for (int columna = 0; columna < COLUMNAS; columna++){
            if (fila >= 43){
                mundo[fila][columna] = 1;
            } else{
                mundo[fila][columna] = 0;
            }
        }
    }

    // colocar objetos

    colocar_arbusto(mundo,36,21);
    colocar_arbusto(mundo,36,29);
    colocar_arbusto(mundo,36,37);
    colocar_arbusto(mundo,7,29);
    colocar_arbusto(mundo,36,98);
    colocar_signo(mundo,7,29);
    colocar_ladrillo(mundo,7,73);
    colocar_signo(mundo,7,82);
    colocar_ladrillo(mundo,7,91);
    colocar_signo(mundo,7,100);
    colocar_ladrillo(mundo,7,109);
    draw_player(mundo,27,1);
    draw_whomp(mundo,27,104);

    return mundo;
}

int** crear_world_copia(){
    int **mundo_copia = new int*[FILAS];

    for (int fila = 0; fila < FILAS; fila++){
        mundo_copia[fila] = new int[COLUMNAS];
        for (int columna = 0; columna < COLUMNAS; columna++){
            if (fila >= 43){
                mundo_copia[fila][columna] = 1;
            } else{
                mundo_copia[fila][columna] = 0;
            }
        }
    }

    // colocar objetos

    colocar_arbusto(mundo_copia,36,21);
    colocar_arbusto(mundo_copia,36,29);
    colocar_arbusto(mundo_copia,36,37);
    colocar_arbusto(mundo_copia,7,29);
    colocar_arbusto(mundo_copia,36,98);
    colocar_signo(mundo_copia,7,29);
    colocar_ladrillo(mundo_copia,7,73);
    colocar_signo(mundo_copia,7,82);
    colocar_ladrillo(mundo_copia,7,91);
    colocar_signo(mundo_copia,7,100);
    colocar_ladrillo(mundo_copia,7,109);
    draw_whomp(mundo_copia,27,104);

    return mundo_copia;
}


/////////////////////////////////////
/// Dibujar el mundo
//////////////////////////////////////

void draw_world(int **world, int coins){
    std::cout << "\033[2J\033[H";

    std::cout << "\nWelcome to the world of super mario bros xyz\n";

    for (int f = 0; f < FILAS; f++){
        for (int c = 0; c < COLUMNAS; c++){
            int celda = world[f][c];

            std::cout << colores[celda] << "  " << RESET;

        }
        std::cout << "\n";
    }
    std::cout << "\ncoins = " << coins << "\n\n";
}

///////////////////////////////////
/// Funciones de juego
//////////////////////////////////////

// lucky block golpeado se vuelve negro
void pintar_bloque_negro(int** mundo, int f_impacto, int c_impacto, int** matrizCopia) {
    int f_inicio = f_impacto;
    int c_inicio = c_impacto;

    while (f_inicio > 0 && (mundo[f_inicio - 1][c_impacto] == 3 || mundo[f_inicio - 1][c_impacto] == 4)) {
        f_inicio--;
    }
    while (c_inicio > 0 && (mundo[f_impacto][c_inicio - 1] == 3 || mundo[f_impacto][c_inicio - 1] == 4)) {
        c_inicio--;
    }

    for (int f = 0; f < ALTO_SIGNO; f++) {
        for (int c = 0; c < ANCHO_SIGNO; c++) {
            if (f_inicio + f < FILAS && c_inicio + c < COLUMNAS) {
                mundo[f_inicio + f][c_inicio + c] = 4;
                matrizCopia[f_inicio + f][c_inicio + c] = 4;
            }
        }
    }
}

// obtener moneda del lucky coin - ?
bool collect_coins(int** mundo, int marioFilaAire, int marioColumnaAire, int** matrizCopia) {
    //draw_player(mundo, marioFilaAire, marioColumnaAire);

    for (int c = marioColumnaAire; c < marioColumnaAire + ANCHO_MARIO; c++) {
        if (c >= 0 && c < COLUMNAS) {
            for (int f = marioFilaAire; f < marioFilaAire + 4; f++) {
                if (f >= 0 && f < FILAS) {
                    if (mundo[f][c] == 3) {
                        pintar_bloque_negro(mundo, f, c, matrizCopia);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// game over
bool check_game_over(int marioF, int marioC, int goombaF, int goombaC) {
    if (marioF < goombaF + ALTO_WHOMP &&
        marioF + ALTO_MARIO > goombaF &&
        marioC < goombaC + ANCHO_WHOMP &&
        marioC + ANCHO_MARIO > goombaC) {
        return true;
    }
    return false;
}


///////////////////////////////////
/// Funciones de jugador
//////////////////////////////////////

// eliminar jugador - reescribir el mundo original
void borra_player(int** mundo, int origenFila, int origenColumna, int** matrizCopia) {
    for (int f = 0; f < ALTO_MARIO; f++) {
        for (int c = 0; c < ANCHO_MARIO; c++) {
            if (mario[f][c] != 0) {
                mundo[origenFila + f][origenColumna + c] = matrizCopia[origenFila+f][origenColumna+c];
            }
        }
    }
}

void move_player(int** mundo, int &marioFila, int &marioColumna, std::string option, int &numCoins, int** matrizCopia) {

    static int filaDibujoAnterior = marioFila;

    borra_player(mundo, filaDibujoAnterior, marioColumna, matrizCopia);

    int nuevaCol = marioColumna;
    int nuevaFila = marioFila;

    if (option == "right") {
        if (marioColumna + 12 + ANCHO_MARIO <= COLUMNAS) {
            nuevaCol += 12;
        }
    } else if (option == "left") {
        if (marioColumna - 12 >= 0) {
            nuevaCol -= 12;
        }
    } else if (option == "up") {
        int filaAire = marioFila - 16;
        //borra_player(mundo,marioFila,marioColumna,matrizCopia); ////
        if (collect_coins(mundo, filaAire, marioColumna, matrizCopia)) {
            numCoins++;
        }
        //borra_player(mundo, filaAire, marioColumna, matrizCopia);
    } else if (option == "up-right") {
        if (marioColumna + 12 + ANCHO_MARIO <= COLUMNAS) {
            nuevaCol += 12;
        }
        int filaAire = marioFila - 16;
        if (collect_coins(mundo, filaAire, nuevaCol, matrizCopia)) {
            numCoins++;
        }
    } else if (option == "up-left") {
        if (marioColumna - 12 >= 0) {
            nuevaCol -= 12;
        }
        int filaAire = marioFila - 16;
        if (collect_coins(mundo, filaAire, nuevaCol, matrizCopia)) {
            numCoins++;
        }
    }

    marioColumna = nuevaCol;
    marioFila = nuevaFila;

    int filaDibujo = marioFila;
    if (option == "up" || option == "up-right" || option == "up-left") {
        filaDibujo = marioFila - 16;
    }
    filaDibujoAnterior = filaDibujo;
    draw_player(mundo, filaDibujo, marioColumna);
}

bool movimiento_es_valido(int marioColumna, std::string option) {
    if (option == "right" || option == "up-right") {
        return marioColumna + 12 + ANCHO_MARIO <= COLUMNAS;
    }
    if (option == "left" || option == "up-left") {
        return marioColumna - 12 >= 0;
    }
    return true;
}