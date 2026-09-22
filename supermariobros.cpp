///////////////////////////////////
/// Librerias
///////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>

///////////////////////////////////
/// Settings
///////////////////////////////////

const int FILAS = 50;
const int COLUMNAS = 120;

const std::string RESET          = "\033[0m";
const std::string FONDO_BLANCO   = "\033[47m";
const std::string FONDO_ROJO     = "\033[41m";
const std::string FONDO_VERDE    = "\033[42m";
const std::string FONDO_AMARILLO = "\033[43m";
const std::string FONDO_NEGRO    = "\033[40m";
const std::string FONDO_PIEL     = "\033[107m";
const std::string COL_LIGHTBLUE  = "\033[104m";
const std::string COL_LIGHTYELLOW = "\033[103m";
const std::string FONDO_MARRON   = "\033[43;2;139;69;19m";


std::string colores[9] = {
    FONDO_PIEL, FONDO_ROJO, FONDO_VERDE, FONDO_AMARILLO, FONDO_NEGRO, FONDO_BLANCO,
    COL_LIGHTBLUE, COL_LIGHTYELLOW, FONDO_MARRON };


///////////////////////////////////
/// Elementos del mundo
///////////////////////////////////

const int ALTO_ARBUSTO = 7;
const int ANCHO_ARBUSTO = 8;

int arbusto[ALTO_ARBUSTO][ANCHO_ARBUSTO] = {
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

int signo[ALTO_SIGNO][ANCHO_SIGNO] = {
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

int ladrillo[ALTO_LADRILLO][ANCHO_LADRILLO] = {
    {1, 1, 1, 1, 4, 1, 1, 1, 1},
    {1, 1, 1, 1, 4, 1, 1, 1, 1},
    {4, 4, 4, 4, 4, 4, 4, 4, 4},
    {1, 1, 4, 1, 1, 1, 4, 1, 1},
    {1, 1, 4, 1, 1, 1, 4, 1, 1},
    {4, 4, 4, 4, 4, 4, 4, 4, 4},
    {1, 1, 1, 1, 4, 1, 1, 1, 1},
    {1, 1, 1, 1, 4, 1, 1, 1, 1}
};

///////////////////////////////////
/// Funciones de mundo - Configuración
///////////////////////////////////

/*
void colocarObjeto(int** mundo, int origenFila, int origenColumna, int objeto[], int alto, int ancho) {
    for (int f = 0; f < alto; f++) {
        for (int c = 0; c < ancho; c++) {
            if (objeto[f][c] == 2) {
                mundo[origenFila + f][origenColumna + c] = 2;
            }
        }
    }
}
*/

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

//////////////////////////////////////
/// Player skins
//////////////////////////////////////

const int ALTO_MARIO = 16;
const int ANCHO_MARIO = 12;

int mario[ALTO_MARIO][ANCHO_MARIO] = {
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
/// Whomp
//////////////////////////////////////

const int ALTO_WHOMP = 16;
const int ANCHO_WHOMP = 16;

int whomp[ALTO_WHOMP][ANCHO_WHOMP] = {
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
    system("cls");

    std::cout << "\nWelcome to the world of super mario bros xyz\n";

    for (int f = 0; f < FILAS; f++){
        for (int c = 0; c < COLUMNAS; c++){
            int celda = world[f][c];

            std::cout << colores[celda] << "  " << RESET;

        }
        std::cout << "\n";
    }
    std::cout << "\ncoins: " << coins << "\n\n";
}

///////////////////////////////////
/// Funciones de juego
//////////////////////////////////////

// lucky block golpeado se vuelve negro
void pintar_bloque_negro(int** mundo, int f_impacto, int c_impacto) {
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
            }
        }
    }
}

// obtener moneda del lucky coin - ?
bool collect_coins(int** mundo, int marioFilaAire, int marioColumnaAire) {
    //draw_player(mundo, marioFilaAire, marioColumnaAire);

    for (int c = marioColumnaAire; c < marioColumnaAire + ANCHO_MARIO; c++) {
        if (c >= 0 && c < COLUMNAS) {
            for (int f = marioFilaAire; f < marioFilaAire + 4; f++) {
                if (f >= 0 && f < FILAS) {
                    if (mundo[f][c] == 3) {
                        pintar_bloque_negro(mundo, f, c);
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
        if (collect_coins(mundo, filaAire, marioColumna)) {
            numCoins++;
        }
        //borra_player(mundo, filaAire, marioColumna, matrizCopia);
    } else if (option == "up-right") {
        if (marioColumna + 12 + ANCHO_MARIO <= COLUMNAS) {
            nuevaCol += 12;
        }
        int filaAire = marioFila - 16;
        if (collect_coins(mundo, filaAire, nuevaCol)) {
            numCoins++;
        }
    } else if (option == "up-left") {
        if (marioColumna - 12 >= 0) {
            nuevaCol -= 12;
        }
        int filaAire = marioFila - 16;
        if (collect_coins(mundo, filaAire, nuevaCol)) {
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


int main(){

    std::string opcion;
    int numCoins = 0;
    int marioFila = 27;
    int marioColumna = 1;

    int whompFila = 27;
    int whompColumna = 104;

    int **mundo = crear_world();
    int **mundoCopia = crear_world_copia();

    while (true){
        std::cout << "Consola: ";
        std::cin >> opcion;

        if (opcion == "init"){
            draw_world(mundo, numCoins);
        } else if (opcion == "right" || opcion == "left" || opcion == "up" || opcion == "up-right" || opcion == "up-left") {
            move_player(mundo, marioFila, marioColumna, opcion, numCoins, mundoCopia);
            draw_world(mundo, numCoins);
            if (opcion == "up" || opcion == "up-right" || opcion == "up-left") {
                std::this_thread::sleep_for(std::chrono::milliseconds(400));
                move_player(mundo, marioFila, marioColumna, "envrdestonosirvedenada", numCoins, mundoCopia);
                draw_world(mundo, numCoins);
            }
            if (check_game_over(marioFila, marioColumna, whompFila, whompColumna)) {
                std::cout << "game over\n";

                for (int i = 0; i < FILAS; i++){
                    delete[] mundo[i];
                }
                delete[] mundo;

                while (true) {}
            }
        }
    }

    return 0;
}