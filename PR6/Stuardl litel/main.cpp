#include <iostream>
#include "barquitoRC.h"

using namespace std;

void jugarCarrera(BarquitosRC& barquito) {
    cout << "¡Comienza la carrera del barco " << barquito.getNombre() << "!" << endl;

    // Se juegan 5 turnos
    for (int i = 1; i <= 5; i++) {
        cout << "Turno " << i << ": " << endl;

        // Se lanza el dado
        int puntosDado = rand() % 6 + 1;
        cout << "El dado ha dado " << puntosDado << " puntos." << endl;

        // Se aumenta la velocidad
        int velocidadAnterior = barquito.getVelocidad();
        barquito.setVelocidad(velocidadAnterior + puntosDado);

        // Se pregunta si se quiere usar nitro
        char respuesta;
        cout << "¿Quieres usar nitro? (S/N) ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            barquito.usarNitro();
            cout << "¡Nitro activado! Velocidad actual: " << barquito.getVelocidad() << endl;
        }

        // Se calcula la distancia recorrida
        barquito.calcularDistanciaRecorrida();
        cout << "Distancia recorrida: " << barquito.getDistanciaRecorrida() << endl;

        cout << endl;
    }

    cout << "¡Fin de la carrera del barco " << barquito.getNombre() << "!" << endl;
}

int main() {
    srand(time(NULL));

    // Se inicializan los barcos
    BarquitosRC miBarquito("Mi barco");
    BarquitosRC badEgg("BAD_EGG");

    // Se juega la carrera para cada barco
    jugarCarrera(miBarquito);
    jugarCarrera(badEgg);

    // Se determina el ganador
    int distanciaRecorridaMiBarco = miBarquito.getDistanciaRecorrida();
    int distanciaRecorridaBadEgg = badEgg.getDistanciaRecorrida();

    if (distanciaRecorridaMiBarco > distanciaRecorridaBadEgg) {
        cout << "¡El ganador es " << miBarquito.getNombre() << "!" << endl;
    }
    else if (distanciaRecorridaMiBarco < distanciaRecorridaBadEgg) {
        cout << "¡El ganador es " << badEgg.getNombre() << "!" << endl;
    }
    else {
        cout << "¡Empate!" << endl;
    }

    return 0;
}
