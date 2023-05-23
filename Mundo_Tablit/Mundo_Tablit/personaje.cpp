#include "personaje.h"
#include<iostream>
using namespace std;

personaje::personaje(string pNombre, int pVida, int pAtack, int pPosicionX, int pPosicionY) {
    Nombre = pNombre;
    Vida = pVida;
    Atack = pAtack;
    PosicionX = pPosicionX;
    PosicionY = pPosicionY;
}//constructor

int personaje::getVida() {
    return Vida;
}

int personaje::getAtack() {
    return Atack;
}

int personaje::getPosicionX() {
    return PosicionX;
}

int personaje::getPosicionY() {
    return PosicionY;
}

void personaje::setNombre(string pNombre) {
    Nombre = pNombre;
}

void personaje::setVida(int pVida) {
    Vida = pVida;
}

void personaje::setAtack(int pAtack) {
    Atack = pAtack;
}

