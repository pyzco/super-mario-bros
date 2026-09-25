//
// Grupo 4
// Integrantes:
// Sebastian Chipana - 20261PRECS01009
// Keith Salas - 20261PRECIA1021
// Vania Padilla - 2023200
// Gabriel Salazar - 20261PRECS01097
//

#include "funciones.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>

// Desde la terminal (para que se compilen los archivos juntos)
// g++ main.cpp funciones.cpp -o main
// ./main

int main(){

    std::string opcion;
    int numCoins = 0;
    int marioFila = 27;
    int marioColumna = 1;

    int whompFila = 27;
    int whompColumna = 104;

    int **mundo = crear_world();
    int **mundoCopia = crear_world_copia();
    do
    {
        std::cout << "Consola: ";
        std::cin >> opcion;
        if (!std::cin) return 0;
    } while(opcion != "init" && opcion !="exit");
    if (opcion == "init")
        draw_world(mundo, numCoins);
    else
    {
        for (int i = 0; i < FILAS; i++)
            {
                delete[] mundo[i];
                delete[] mundoCopia[i];
            }
        delete[] mundo;
        delete[] mundoCopia;
        return 0;
    }
    while (true)
    {
        std::cout << "Consola: ";
        std::cin >> opcion;
        if (!std::cin) break;
        if (opcion == "right" || opcion == "left" || opcion == "up" || opcion == "up-right" || opcion == "up-left")
        {
            if (!movimiento_es_valido(marioColumna, opcion))
            {
            std::cout << "invalid operation - fuera de los limites del mundo\n";
            continue;
            }
            move_player(mundo, marioFila, marioColumna, opcion, numCoins, mundoCopia);
            draw_world(mundo, numCoins);
            if (opcion == "up" || opcion == "up-right" || opcion == "up-left")
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(350));
                move_player(mundo, marioFila, marioColumna, "envrdestonosirvedenada", numCoins, mundoCopia);
                draw_world(mundo, numCoins);
            }
            if (check_game_over(marioFila, marioColumna, whompFila, whompColumna))
            {
                std::cout << "game over\n";

                for (int i = 0; i < FILAS; i++)
                {
                    delete[] mundo[i];
                    delete[] mundoCopia[i];
                }
                delete[] mundo;
                delete[] mundoCopia;

                break;
            }
        }
        else if (opcion == "exit")
        {
            std::cout<<"game over\n";
            break;
        }
        else
        {
            std::cout<<"invalid operation - comando no reconocido\n";
        }
    }
    for (int i = 0; i < FILAS; i++)
    {
        delete[] mundo[i];
        delete[] mundoCopia[i];
    }
    delete[] mundo;
    delete[] mundoCopia;
    return 0;
}