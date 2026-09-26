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

    
//////////////////////////////////////////
/// Funciones de configuración del mundo
//////////////////////////////////////////


// Transfiere un sprite a la matriz del mundo gestionando la memoria contigua.
void dibujar_elemento(int** mundo, int origenFila, int origenColumna, const int* elemento, int alto, int ancho) {
    for (int f = 0; f < alto; f++) {
        for (int c = 0; c < ancho; c++) {

            // Se calcula el índice 1D equivalente para leer la matriz del sprite de forma segura.
            int pixel = elemento[(f * ancho) + c];

            // Solo sobreescribe el mundo si el píxel no es "transparente" (0).
            if (pixel != 0) {
                mundo[origenFila + f][origenColumna + c] = pixel; 
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


//////////////////////////////////////
/// Generar mundo
//////////////////////////////////////

// Inicializa el mapa del juego asignando memoria dinámica y colocando los elementos estáticos.
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

    // Inserción de elementos del mundo (arbustos) en las coordenadas del suelo.
    dibujar_elemento(mundo, 36, 21, &arbusto[0][0], ALTO_ARBUSTO, ANCHO_ARBUSTO);
    dibujar_elemento(mundo, 36, 29, &arbusto[0][0], ALTO_ARBUSTO, ANCHO_ARBUSTO);
    dibujar_elemento(mundo, 36, 37, &arbusto[0][0], ALTO_ARBUSTO, ANCHO_ARBUSTO);
    dibujar_elemento(mundo, 36, 98, &arbusto[0][0], ALTO_ARBUSTO, ANCHO_ARBUSTO);
    
    // Inserción de bloques interactivos (signos) y estáticos (ladrillos) en el aire.
    dibujar_elemento(mundo, 7, 29, &signo[0][0], ALTO_SIGNO, ANCHO_SIGNO);
    dibujar_elemento(mundo, 7, 82, &signo[0][0], ALTO_SIGNO, ANCHO_SIGNO);
    dibujar_elemento(mundo, 7, 100, &signo[0][0], ALTO_SIGNO, ANCHO_SIGNO);
    dibujar_elemento(mundo, 7, 73, &ladrillo[0][0], ALTO_LADRILLO, ANCHO_LADRILLO);
    dibujar_elemento(mundo, 7, 91, &ladrillo[0][0], ALTO_LADRILLO, ANCHO_LADRILLO);
    dibujar_elemento(mundo, 7, 109, &ladrillo[0][0], ALTO_LADRILLO, ANCHO_LADRILLO);
    
    // Posicionamiento inicial del enemigo (Goomba).
    dibujar_elemento(mundo, 27, 104, &goomba[0][0], ALTO_GOOMBA, ANCHO_GOOMBA);
    dibujar_elemento(mundo, 27, 1, &mario[0][0], ALTO_MARIO, ANCHO_MARIO);
    
    // Retorna el puntero doble al mapa inicializado.
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

    dibujar_elemento(mundo_copia, 36, 21, &arbusto[0][0], ALTO_ARBUSTO, ANCHO_ARBUSTO);
    dibujar_elemento(mundo_copia, 36, 29, &arbusto[0][0], ALTO_ARBUSTO, ANCHO_ARBUSTO);
    dibujar_elemento(mundo_copia, 36, 37, &arbusto[0][0], ALTO_ARBUSTO, ANCHO_ARBUSTO);
    dibujar_elemento(mundo_copia, 36, 98, &arbusto[0][0], ALTO_ARBUSTO, ANCHO_ARBUSTO);
    
    dibujar_elemento(mundo_copia, 7, 29, &signo[0][0], ALTO_SIGNO, ANCHO_SIGNO);
    dibujar_elemento(mundo_copia, 7, 82, &signo[0][0], ALTO_SIGNO, ANCHO_SIGNO);
    dibujar_elemento(mundo_copia, 7, 100, &signo[0][0], ALTO_SIGNO, ANCHO_SIGNO);
    dibujar_elemento(mundo_copia, 7, 73, &ladrillo[0][0], ALTO_LADRILLO, ANCHO_LADRILLO);
    dibujar_elemento(mundo_copia, 7, 91, &ladrillo[0][0], ALTO_LADRILLO, ANCHO_LADRILLO);
    dibujar_elemento(mundo_copia, 7, 109, &ladrillo[0][0], ALTO_LADRILLO, ANCHO_LADRILLO);
    
    dibujar_elemento(mundo_copia, 27, 104, &goomba[0][0], ALTO_GOOMBA, ANCHO_GOOMBA);
    
    return mundo_copia;
}


//////////////////////////////////////
/// Dibujar el mundo
//////////////////////////////////////

// Función encargada del dibujo en terminal. Dibuja el estado actual de la memoria en la pantalla.
void draw_world(int **world, int coins){

    // Código de escape ANSI para borrar la terminal completa y mover el cursor a [0,0] (evita parpadeos).
    std::cout << "\033[2J\033[H";

    // Armamos el mapa completo en un solo texto y lo imprimimos de una vez para que no hallan parpadeos.
    std::string lienzo = "";


    for (int f = 0; f < FILAS; f++){
        for (int c = 0; c < COLUMNAS; c++){
            int celda = world[f][c];

            lienzo += colores[celda] + "  " + RESET;

        }
        lienzo += "\n";
    }
    std::cout << lienzo;
    std::cout << "\ncoins = " << coins << "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(350));
}

//////////////////////////////////////
/// Funciones para las mecanicas de juego
//////////////////////////////////////

// lucky block golpeado se vuelve negro
void pintar_bloque_negro(int** mundo, int f_impacto, int c_impacto, int** matrizCopia, int &f_bloque, int &c_bloque) {
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
    // Retorna las coordenadas de origen a través de referencias para generar la moneda justo encima.
    f_bloque = f_inicio;
    c_bloque = c_inicio;
}

// obtener moneda del lucky coin - ?
bool collect_coins(int** mundo, int marioFilaAire, int marioColumnaAire, int** matrizCopia, int &monedaFila, int &monedaColumna) {

    for (int c = marioColumnaAire; c < marioColumnaAire + ANCHO_MARIO; c++) {
        if (c >= 0 && c < COLUMNAS) {
            for (int f = marioFilaAire; f < marioFilaAire + 4; f++) {
                if (f >= 0 && f < FILAS) {
                    if (mundo[f][c] == 3) {
                        int f_bloque, c_bloque;
                        pintar_bloque_negro(mundo, f, c, matrizCopia, f_bloque, c_bloque);
                        monedaFila = f_bloque - ALTO_MONEDA;
                        monedaColumna = c_bloque + 1;
                        
                        // Aparece visualmente la moneda.
                        dibujar_elemento(mundo, monedaFila, monedaColumna, &moneda[0][0], ALTO_MONEDA, ANCHO_MONEDA);
                        
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Limpia una moneda recolectada del mapa reemplazando sus píxeles por vacío (0).
void borrar_moneda(int** mundo, int origenFila, int origenColumna) {
    for (int f = 0; f < ALTO_MONEDA; f++) {
        for (int c = 0; c < ANCHO_MONEDA; c++) {
            if (moneda[f][c] != 0) {
                mundo[origenFila + f][origenColumna + c] = 0; 
            }
        }
    }
}

// game over
bool check_game_over(int marioF, int marioC, int goombaF, int goombaC) {
    if (marioF < goombaF + ALTO_GOOMBA &&
        marioF + ALTO_MARIO > goombaF&&
        marioC < goombaC + ANCHO_GOOMBA &&
        marioC + ANCHO_MARIO > goombaC) {
        return true;
    }
    return false;
}


//////////////////////////////////////
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

    bool monedaDibujada = false;
    int monedaFila, monedaColumna;

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
        if (collect_coins(mundo, filaAire, marioColumna, matrizCopia, monedaFila, monedaColumna)) {
            numCoins++;
            monedaDibujada = true;
        }
        //borra_player(mundo, filaAire, marioColumna, matrizCopia);
    } else if (option == "up-right") {
        if (marioColumna + 12 + ANCHO_MARIO <= COLUMNAS) {
            nuevaCol += 12;
        }
        int filaAire = marioFila - 16;
        if (collect_coins(mundo, filaAire, nuevaCol, matrizCopia, monedaFila, monedaColumna)) {
            numCoins++;
            monedaDibujada = true;
        }
    } else if (option == "up-left") {
        if (marioColumna - 12 >= 0) {
            nuevaCol -= 12;
        }
        int filaAire = marioFila - 16;
        if (collect_coins(mundo, filaAire, nuevaCol, matrizCopia, monedaFila, monedaColumna)) {
            numCoins++;
            monedaDibujada = true;
        }
    }

    marioColumna = nuevaCol;
    marioFila = nuevaFila;

    int filaDibujo = marioFila;
    if (option == "up" || option == "up-right" || option == "up-left") {
        filaDibujo = marioFila - 16;
        if (monedaDibujada) {
            dibujar_elemento(mundo, monedaFila, monedaColumna, &moneda[0][0], ALTO_MONEDA, ANCHO_MONEDA);
        }
    }
    filaDibujoAnterior = filaDibujo;
    dibujar_elemento(mundo, filaDibujo, marioColumna, &mario[0][0], ALTO_MARIO, ANCHO_MARIO);

    borrar_moneda(mundo, monedaFila, monedaColumna);

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