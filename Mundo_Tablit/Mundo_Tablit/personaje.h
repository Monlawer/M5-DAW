#pragma once
#include<iostream>
using namespace std;


class personaje
{
private:
	string Nombre;
	int Vida;
	int Atack;
	int PosicionX;
	int PosicionY;

public:
	personaje( string pNombre, int pVida, int pAtack, int pPosicionX, int pPosicionY);

	int getVida();
	int getAtack();
	int getPosicioX;
	int getPosicioY;

	int getAtack();

	int getPosicionX();

	int getPosicionY();

	void setNombre(string pNombre);
	void setVida(int pVida);
	void setAtack(int pAtack);

	class BossFinal : public personaje {
	private:
		int AtaqueDefinitivo;

	public:
		BossFinal(string pNombre, int pVida, int pPosicionX, int pPosicionY, int pAtaqueDefinitivo);

		int getAtaqueDefinitivo();
		void setAtaqueDefinitivo(int pAtaqueDefinitivo);
	};
};

