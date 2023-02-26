#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    // Inicializar la semilla aleatoria
    srand(time(0));

    // Baraja del juego
    const int NUM_CARTAS = 52;
    int baraja[NUM_CARTAS] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,   // As
                                2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,   // As
                                2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,   // As
                                2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 }; // As

    // Pedir el nombre del jugador
    string nombre_jugador;
    cout << "Bienvenido al juego de Blackjack! Cual es tu nombre?" << endl;
    cin >> nombre_jugador;
    cout << "Hola " << nombre_jugador << ", vamos a comenzar!" << endl;

    // Repartir las cartas
    int carta_jugador = baraja[rand() % NUM_CARTAS];
    int carta_casa = baraja[rand() % NUM_CARTAS];

    cout << "Tus cartas: " << carta_jugador;
    cout << ", " << baraja[rand() % NUM_CARTAS] << endl;
    cout << "Carta de la casa: " << carta_casa << ", ?" << endl;

    // Pedir al jugador que pida cartas adicionales
    char opcion;
    cout << "Quieres otra carta? (s/n)" << endl;
    cin >> opcion;

    while (opcion == 's') {
        carta_jugador += baraja[rand() % NUM_CARTAS];
        cout << "Tus cartas: " << carta_jugador << endl;

        if (carta_jugador > 21) {
            cout << "Te pasaste de 21! Perdiste!" << endl;
            return 0;
        }

        cout << "Quieres otra carta? (s/n)" << endl;
        cin >> opcion;
    }

    // Si el jugador se plantó, la casa toma cartas hasta llegar a 17
    while (carta_casa < 17) {
        carta_casa += baraja[rand() % NUM_CARTAS];
    }

    cout << "Carta de la casa: " << carta_casa << endl;

    // Determinar el ganador
    if (carta_casa > 21) {
        cout << "La casa se pasó de 21! Ganaste!" << endl;
    }
    else if (carta_casa > carta_jugador) {
        cout << "La casa tiene una carta mayor! Perdiste!" << endl;
    }
    else if (carta_jugador > carta_casa) {
        cout << "Tienes una carta mayor! Ganaste!" << endl;
    }
    else {
        cout << "Empate!" << endl;
    }

    return 0;
}
