#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

const int NUM_CARTAS = 52;
int baraja[NUM_CARTAS] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                            2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                            2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                            2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };

int carta_jugador = 0;
int carta_casa = 0;
int indice_carta = 0;

void iniciarpartida1() {
    cout << "Bienvenido al casino, hoy te enfentaras al Croupiere MAC 2003, mucho animo Sr.Windows XP" << endl;
}

void normas() {
    cout << "Necesitas repasar las normas del BlackJack?: ";
    string sino;
    cin >> sino;

    if (sino == "si") {
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Las normas son Todas las cartas del 2 al 10 tienen el mismo valor que su número  " << endl;
        cout << "El AS puede valer un 1 o puede valer un 11. Depende de ti como jugador o de la banca si tiene el AS" << endl;
        cout << "Las figuras J, Q y K tienen todas un valor de 10." << endl;
        cout << "El jugador gana cuando: " << endl;
        cout << "alcanza un 21 y el croupier no empata a 21 o se pasa de 21" << endl;
        cout << "Alcanza menos de 21 pero la banca se pasa de 21" << endl;
        cout << "El jugador empata cuando:" << endl;
        cout << "Alcanza un 21 y el croupier alcanza tambien 21" << endl;
        cout << "El jugador pierde cuando: " << endl;
        cout << "Se pasa de 21" << endl;
        cout << "Tiene una puntuación menor a 21, pero la banca tiene una puntuación mayor, sin pasarse de 21." << endl;
        cout << "Como se juega: " << endl;
        cout << "El croupier reparte dos cartas al jugador y reparte una para el." << endl;
        cout << "Es posible que el jugador alcance 21 en esa misma ronda con una combinación de AS (con valor de 11) y un 10 o una figura." << endl;
        cout << "Por lo que pasaría automáticamente al turno de la banca para tratar de al menos empatar." << endl;
        cout << "El jugador, si tiene menos de 21 puntos, puede pedir nuevas cartas al croupier, hasta que decida plantarse, llegue o se pase de 21. " << endl;
        cout << "Si el jugador se pasa de 21, el croupier gana automáticamente. Si el jugador se queda a menos de 21 y se rinde." << endl;
        cout << "Llega el turno del croupier, que tiene que al menos mejorar la puntuación del jugador, sin pasarse de 21." << endl;
        cout << "Si la mejora sin pasarse gana el croupier. Si se pasa de 21, pierde el croupier." << endl;
        cout << "Si el jugador alcanza los 21 puntos. Llega el turno del croupier, que tiene que intentar llegar a 21 obligatoriamente" << endl;
        cout << "Si llega a 21, el jugador y el croupier empatan. Si se pasa de 21, el croupier pierde." << endl;

    }
    else if (sino == "no") {
        cout << "Perfecto, entiendo que tienes un buen bagaje en este tipo de juegos, DEMUESTRAMELO!!!";
    }

}

void inicializar_baraja() {
    for (int i = 0; i < NUM_CARTAS; i++) {
        baraja[i] = (i % 13) + 2; // Genera valores del 2 al 14 (11 para el AS)
    }
}

void barajar() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = NUM_CARTAS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = baraja[i];
        baraja[i] = baraja[j];
        baraja[j] = temp;
    }
}


void pedir_cartas() {
    for (int i = 0; i < 2; i++) {
        carta_jugador += baraja[indice_carta];
        indice_carta++;
    }

    // Si al jugador le toca el ASS, preguntar si quiere que valga 1 o 11
    if (carta_jugador == 22) {
        cout << "Tienes un ASS, ¿quieres que valga 1 o 11?" << endl;
        int valor_ass;
        cin >> valor_ass;
        if (valor_ass == 1) {
            carta_jugador = 12;
        }
        else {
            carta_jugador = 21;
        }
    }
}


void preguntar_valor_AS(int& carta) {
    int opcion = 0;
    while (opcion != 1 && opcion != 11) {
        cout << "Tienes un AS! Quieres que valga 1 o 11? ";
        cin >> opcion;
    }
    carta += opcion;
}

void Turno_Jugador() {
    char respuesta;
    do {
        cout << "Tus cartas suman " << carta_jugador << endl;
        cout << "Quieres otra carta? (s/n): ";
        cin >> respuesta;
        if (respuesta == 's') {
            carta_jugador += baraja[indice_carta];
            indice_carta++;
        }
    } while (respuesta == 's' && carta_jugador < 21);
}

void Turno_Maquina() {
    while (carta_casa < 17) {
        carta_casa += baraja[indice_carta];
        indice_carta++;
    }
}


void determinar_ganador() {
    if (carta_jugador > 21) {
        cout << "Ha ganado MAC. Windows XP ha superado 21." << endl;
    }
    else if (carta_casa > 21) {
        cout << "Ha ganado Windows XP. La MAC ha superado 21." << endl;
    }
    else if (carta_jugador == carta_casa) {
        cout << "Ha habido un empate." << endl;
    }
    else if (carta_jugador > carta_casa) {
        cout << "Ha ganado el poder de WINDOWS XP." << endl;
    }
    else {
        cout << "Ha ganado MAC, se ha quedado más cerca de 21." << endl;
    }
}


int main() {
    iniciarpartida1();
    normas();
    inicializar_baraja();
    barajar();
    pedir_cartas();
    Turno_Jugador();
    Turno_Maquina();
    determinar_ganador();
    return 0;
}