//
// Grupo 4
// Integrantes:
// Sebastian Chipana - 20261PRECS01009
// Keith Salas - 20261PRECIA1021
// Vania Padilla - 2023200
// Gabriel Salazar - 20261PRECS01097
//

#include "colores.h"

// Recibe un número entero y retorna un string con el código ANSI correspondiente
std::string colorANSI(int color)
{
    switch (color)
    {
        case 0: return "\033[107m"; // Fondo / Piel (Blanco brillante o piel según prefieras)
        case 1: return "\033[41m";   // Rojo (Para el piso y la ropa de Mario)
        case 2: return "\033[42m";   // Verde (Para los arbustos)
        case 3: return "\033[43m";   // Amarillo (Para los bloques de interrogación)
        case 4: return "\033[40m";   // Negro (Para contornos y bloques negros)
        case 5: return "\033[47m";   // Blanco (Para detalles de Mario)
        case 6: return "\033[104m";  // Azul claro (Para el overol de Mario)
        case 7: return "\033[103m";  // Amarillo claro (Para los botones de Mario)
        case 8: return "\033[43m";  // Marrón (Para el Goomba / Whomp)
        default: return "\033[107m"; // Color por defecto ante un número no registrado
    }
}