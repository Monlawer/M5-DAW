#include<iostream>
#include "BarquitosRC.h"
#include <cstdlib>
#include <ctime>

BarquitosRC::BarquitosRC(std::string pNombre) {
    nombre = pNombre;
    velocidad = 0;
    distanciaRecorrida = 0;
    nitro = 1; // nitro empieza en 1 al comenzar la carrera
}

std::string BarquitosRC::getNombre() {
    return nombre;
}

int BarquitosRC::getVelocidad() {
    return velocidad;
}

int BarquitosRC::getDistanciaRecorrida() {
    return distanciaRecorrida;
}

int BarquitosRC::getNitro() {
    return nitro;
}

void BarquitosRC::setNombre(std::string pNombre) {
    nombre = pNombre;
}

void BarquitosRC::setVelocidad(int pVelocidad) {
    velocidad = pVelocidad;
}

void BarquitosRC::setDistanciaRecorrida(int pDistanciaRecorrida) {
    distanciaRecorrida = pDistanciaRecorrida;
}

void BarquitosRC::setNitro(int pNitro) {
    nitro = pNitro;
}

void BarquitosRC::calcularDistanciaRecorrida() {
    distanciaRecorrida += velocidad * 100; // la distancia recorrida se calcula con la velocidad del turno anterior
}

void BarquitosRC::usarNitro() {
    if (nitro > 0) {
        nitro--; // se gasta el nitro al usarlo
        int numAleatorio = rand() % 2; // genera un número aleatorio entre 0 y 1
        if (numAleatorio == 0) {
            velocidad = velocidad / 2; // si sale 0, la velocidad se divide por la mitad
        }
        else {
            velocidad = velocidad * 2; // si sale 1, la velocidad se multiplica por dos
        }
    }
}

void BarquitosRC::lanzarDado() {
    int puntos = rand() % 6 + 1; // genera un número aleatorio entre 1 y 6
    velocidad += puntos; // se añade el número obtenido a la velocidad
}