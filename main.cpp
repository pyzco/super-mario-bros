//
// Grupo 4
// Integrantes:
// Sebastian Chipana - 20261PRECS01009
// Keith Salas - 20261PRECIA1021
// Vania Padilla - 2023200
// Gabriel Salazar - 20261PRECS01097
//

#include <iostream>
#include <string>

// Estas dos librerias fueron usadas debido a que se informo que se ejecutaria en UBUNTU
// sirve para simular sleep de windows.h
#include <chrono> 
#include <thread>

// Incluye todas las matrices constantes y funciones del juego
#include "supermario.h" 

int main(){

    // Variables que controlan la entrada del usuario y la cantidad de monedas recogidas.
    std::string opcion;
    int numCoins = 0;

    // Coordenadas iniciales de Mario en el mapa.
    int marioFila = 27;
    int marioColumna = 1;

    // Coordenadas fijas del enemigo (Goomba).
    int goombaFila = 27;
    int goombaColumna = 104;

    // Coordenadas temporales para saber dónde dibujar la moneda recién recolectada (-1 significa oculta).
    int monedaFila = -1;
    int monedaColumna = -1;

    // Se construye el mapa del nivel reservando memoria dinámica.
    int **mundo = crear_world();

    // Bucle principal que mantiene el juego funcionando.
    while (true){

        // Espera a que el jugador escriba un comando y presione Enter.
        std::cout << "Consola: ";
        std::cin >> opcion;

        // Dibuja el mundo con un mensaje de bienvenida si el comando es "init".
        if (opcion == "init"){

            // Muestra el estado inicial del mapa y activa el texto de bienvenida.
            draw_world(mundo, numCoins, marioFila, marioColumna, true);

            // Si el usuario ingresa un comando de movimiento válido.
        } else if (opcion == "right" || opcion == "left" || opcion == "top" || opcion == "up-right" || opcion == "up-left") {
            
            // Intenta mover al jugador y devuelve true si no chocó con los bordes del mapa.
            bool valid_move = move_player(mundo, marioFila, marioColumna, opcion, numCoins, monedaFila, monedaColumna);
            
            // Dibuja la pantalla para reflejar el primer paso del movimiento.
            draw_world(mundo, numCoins, marioFila, marioColumna, false);

            if (!valid_move) {

                // Si intentó salirse del mapa, avisa que la operación es inválida.
                draw_world(mundo, numCoins, marioFila, marioColumna, false);
                std::cout << "invalid operation\n\n";
            } else {

                // Animación del salto: Si la acción incluye un movimiento hacia arriba.
                if (opcion == "top" || opcion == "up-right" || opcion == "up-left") {

                    // Dibuja a Mario momentáneamente en el aire.
                    draw_world(mundo, numCoins, marioFila - 16, marioColumna, false);

                    // Pausa el juego un tercio de segundo para que el usuario pueda ver el salto.
                    std::this_thread::sleep_for(std::chrono::milliseconds(350));
                }

                // Vuelve a dibujar el mapa con Mario ya en el suelo.
                draw_world(mundo, numCoins, marioFila, marioColumna, false);
            }

            // Revisa si las posiciones de Mario y el enemigo se cruzaron (colisión).
            if (check_game_over(marioFila, marioColumna, goombaFila, goombaColumna)) {
                draw_world(mundo, numCoins, marioFila, marioColumna, false);

                // Imprime el mensaje final
                std::cout << "game over\n";

                // Limpia la consola y espera a que el usuario presione una tecla para cerrar
                std::cin.ignore(10000, '\n');
                std::cin.get();

                // Libera todas las filas de la memoria dinámica para evitar fugas de memoria
                for (int i = 0; i < FILAS; i++){
                    delete[] mundo[i];
                }

                // Libera la matriz principal
                delete[] mundo;

                return 0;
            }
        }
    }    
}