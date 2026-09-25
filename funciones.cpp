//
// Grupo 4
// Integrantes:
// Sebastian Chipana - 20261PRECS01009
// Keith Salas - 20261PRECIA1021
// Vania Padilla - 2023200
// Gabriel Salazar - 20261PRECS01097
//

#include "supermario.h"

// DEFINICIÓN DE SPRITES
// Se definen los valores de los píxeles para cada elemento visual del juego.
// Los números corresponden a los códigos de color en la función colorANSI().

// sprite moneda
const int moneda[ALTO_MONEDA][ANCHO_MONEDA] = {
    {0, 0, 3, 3, 3, 0, 0},
    {0, 3, 3, 4, 3, 3, 0},
    {3, 3, 3, 4, 3, 3, 3},
    {3, 3, 3, 4, 3, 3, 3},
    {3, 3, 3, 4, 3, 3, 3},
    {0, 3, 3, 4, 3, 3, 0},
    {0, 0, 3, 3, 3, 0, 0}
};

// sprite arbusto
const int arbusto[ALTO_ARBUSTO][ANCHO_ARBUSTO] = {
    {0, 0, 0, 2, 2, 0, 0, 0},
    {0, 0, 2, 2, 2, 2, 0, 0},
    {0, 2, 2, 2, 2, 2, 2, 0},
    {2, 2, 2, 2, 2, 2, 2, 2}, 
    {2, 2, 2, 2, 2, 2, 2, 2}, 
    {2, 2, 2, 2, 2, 2, 2, 2},
    {2, 2, 2, 2, 2, 2, 2, 2}
};

// sprite signo
const int signo[ALTO_SIGNO][ANCHO_SIGNO] = {
    {3, 3, 3, 3, 3, 3, 3, 3, 3},
    {3, 3, 3, 4, 4, 4, 3, 3, 3},
    {3, 3, 4, 3, 3, 3, 4, 3, 3},
    {3, 3, 3, 3, 3, 4, 4, 3, 3},
    {3, 3, 3, 3, 4, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3, 3, 3, 3},
    {3, 3, 3, 3, 4, 3, 3, 3, 3},
    {3, 3, 3, 3, 3, 3, 3, 3, 3}
};

//sprite ladrillo
const int ladrillo[ALTO_LADRILLO][ANCHO_LADRILLO] = {
    {1, 1, 1, 1, 4, 1, 1, 1, 1},
    {1, 1, 1, 1, 4, 1, 1, 1, 1},
    {4, 4, 4, 4, 4, 4, 4, 4, 4},
    {1, 1, 4, 1, 1, 1, 4, 1, 1},
    {1, 1, 4, 1, 1, 1, 4, 1, 1},
    {4, 4, 4, 4, 4, 4, 4, 4, 4},
    {1, 1, 1, 1, 4, 1, 1, 1, 1},
    {1, 1, 1, 1, 4, 1, 1, 1, 1}
};

// sprite mario
const int mario[ALTO_MARIO][ANCHO_MARIO] = {
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

// sprite goomba
const int goomba[ALTO_GOOMBA][ANCHO_GOOMBA] = {
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

// IMPLEMENTACIÓN DE LA LÓGICA DEL JUEGO

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

// Limpia el rastro de Mario en el mapa reemplazando sus píxeles no transparentes por vacío (0).
void borra_player(int** mundo, int origenFila, int origenColumna) {
    for (int f = 0; f < ALTO_MARIO; f++) {
        for (int c = 0; c < ANCHO_MARIO; c++) {
            if (mario[f][c] != 0) {
                mundo[origenFila + f][origenColumna + c] = 0; 
            }
        }
    }
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

// Inicializa el mapa del juego asignando memoria dinámica y colocando los elementos estáticos.
int** crear_world(){
    // Reserva de memoria dinámica para la matriz 2D del mundo.
    int **mundo = new int*[FILAS];
    for (int fila = 0; fila < FILAS; fila++){
        mundo[fila] = new int[COLUMNAS];
        for (int columna = 0; columna < COLUMNAS; columna++){

            // Genera el piso sólido a partir de la fila 43.
            if (fila >= 43){
                mundo[fila][columna] = 1;
            } else{
                // El resto es cielo (vacío)
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

    // Retorna el puntero doble al mapa inicializado.
    return mundo;
}

// Función que rastrea los bordes de un bloque golpeado y lo repinta de negro.
void pintar_bloque_negro(int** mundo, int f_impacto, int c_impacto, int &f_bloque, int &c_bloque) {
    int f_inicio = f_impacto;
    int c_inicio = c_impacto;

    // Busca iterativamente el píxel superior izquierdo del bloque iterando hacia arriba y a la izquierda.
    while (f_inicio > 0 && (mundo[f_inicio - 1][c_impacto] == 3 || mundo[f_inicio - 1][c_impacto] == 4)) {
        f_inicio--;
    }
    while (c_inicio > 0 && (mundo[f_impacto][c_inicio - 1] == 3 || mundo[f_impacto][c_inicio - 1] == 4)) {
        c_inicio--;
    }

    // Sobreescribe el área exacta del bloque de signo con el código de color 4 (negro).
    for (int f = 0; f < ALTO_SIGNO; f++) {
        for (int c = 0; c < ANCHO_SIGNO; c++) {
            if (f_inicio + f < FILAS && c_inicio + c < COLUMNAS) {
                mundo[f_inicio + f][c_inicio + c] = 4;
            }
        }
    }

    // Retorna las coordenadas de origen a través de referencias para generar la moneda justo encima.
    f_bloque = f_inicio;
    c_bloque = c_inicio;
}

// Sistema de detección de colisiones verticales (saltos) para interactuar con los bloques de signo.
bool collect_coins(int** mundo, int marioFilaAire, int marioColumnaAire, int &monedaFila, int &monedaColumna) {

    // Escanea el área por encima de Mario (hitbox superior) en busca del color 3 (bloque amarillo).
    for (int c = marioColumnaAire; c < marioColumnaAire + ANCHO_MARIO; c++) {
        if (c >= 0 && c < COLUMNAS) {
            for (int f = marioFilaAire; f < marioFilaAire + 4; f++) {
                if (f >= 0 && f < FILAS) {
                    if (mundo[f][c] == 3) {
                        int f_bloque, c_bloque;

                        // Si hay impacto, se oscurece el bloque y se calcula la posición de spawn de la moneda.
                        pintar_bloque_negro(mundo, f, c, f_bloque, c_bloque);
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

// Función de detección de colisiones entre Mario y los enemigos.
bool check_game_over(int marioF, int marioC, int goombaF, int goombaC) {
    // Si los límites rectangulares de ambos personajes se superponen en X y en Y, es Game Over.
    if (marioF < goombaF + ALTO_GOOMBA &&
        marioF + ALTO_MARIO > goombaF &&
        marioC < goombaC + ANCHO_GOOMBA &&
        marioC + ANCHO_MARIO > goombaC) {
        return true;
    }
    return false;
}

// Manejo de estados para gestionar la física y restricciones de movimiento del jugador.
bool move_player(int** mundo, int &marioFila, int &marioColumna, std::string option, int &numCoins, int &monedaFila, int &monedaColumna){
    
    // Si había una moneda visible en el turno anterior, la desaparece.
    if (monedaFila != -1 && monedaColumna != -1) {
        borrar_moneda(mundo, monedaFila, monedaColumna);
        monedaFila = -1;
        monedaColumna = -1;
    }

    int nuevaCol = marioColumna;
    int nuevaFila = marioFila;

    // variable usada para determinar si el movimiento está dentro del mapa.
    bool valid = true;

    // Evaluación del input del usuario y validación de límites.
    if (option == "right") {

        // Mueve a la derecha si no excede el límite del mapa.
        if (marioColumna + 12 + ANCHO_MARIO <= COLUMNAS) {
            nuevaCol += 12;
        } else {
            valid = false;
        }
    } else if (option == "left") {

        // Mueve a la izquierda si no choca con el borde inicial.
        if (marioColumna - 12 >= 0) {
            nuevaCol -= 12;
        } else {
            valid = false;
        }
    } else if (option == "top") {
        // Salto estático: Mario asciende temporalmente 16 píxeles para probar colisión.
        int filaAire = marioFila - 16;
        if (collect_coins(mundo, filaAire, marioColumna, monedaFila, monedaColumna)) {
            numCoins++;
        }
    } else if (option == "up-right") {

        // Salto hacia la derecha verificando el límite y colisión de monedas.
        if (marioColumna + 12 + ANCHO_MARIO <= COLUMNAS) {
            nuevaCol += 12;
            int filaAire = marioFila - 16;
            if (collect_coins(mundo, filaAire, nuevaCol, monedaFila, monedaColumna)) {
                numCoins++;
            }
        } else {
            valid = false;
        }
    } else if (option == "up-left") {

        // Salto hacia la izquierda verificando el límite y colisión de monedas.
        if (marioColumna - 12 >= 0) {
            nuevaCol -= 12;
            int filaAire = marioFila - 16;
            if (collect_coins(mundo, filaAire, nuevaCol, monedaFila, monedaColumna)) {
                numCoins++;
            }
        } else {
            valid = false;
        }
    }

    // Actualiza la posición oficial de Mario sobrescribiéndola con el movimiento ya validado.    
    marioColumna = nuevaCol;
    marioFila = nuevaFila;
    
    return valid;
}

// Función encargada del dibujo en terminal. Dibuja el estado actual de la memoria en la pantalla.
void draw_world(int **world, int coins, int marioF, int marioC, bool esInit){

    // Código de escape ANSI para borrar la terminal completa y mover el cursor a [0,0] (evita parpadeos).
    std::cout << "\033[2J\033[H";

    // Armamos el mapa completo en un solo texto y lo imprimimos de una vez para que no hallan parpadeos.
    std::string lienzo = "";
    
    // Doble bucle para recorrer la matriz 2D del mundo pixel por pixel.
    for (int f = 0; f < FILAS; f++){
        for (int c = 0; c < COLUMNAS; c++){
            int celda = world[f][c];

            // Superposición dinámica: Dibuja a Mario en tiempo real si el iterador pasa sobre sus coordenadas.
            if (f >= marioF && f < marioF + ALTO_MARIO && c >= marioC && c < marioC + ANCHO_MARIO) {
                int pixel_mario = mario[f - marioF][c - marioC];
                if (pixel_mario != 0) {
                    celda = pixel_mario;
                }
            }

            // Concatena el código ANSI del color correspondiente y resetea el color.
            lienzo += colorANSI(celda) + "  " + RESET;
        }
        lienzo += "\n";
    }

    // Imprime todo el bloque visual de un solo golpe.
    std::cout << lienzo;

    if (esInit) {
        
        // Mensaje de bienvenida al usuario.
        std::cout << "\nWelcome to the world of super mario bros xyz\n";
    }

    // Indicador de monedas para el jugador.
    std::cout << "\ncoins: " << coins << "\n\n";
}