#include<iostream>
using namespace std;
class BarquitosRC { //Me creo la clase BarquitosRC
private: // Atributos privados, porque solo se pueden acceder desde la clase. NO los puedes modificar si no cumples el objetivo de la clase.
    std::string nombre;
    int velocidad;
    int distanciaRecorrida;
    int nitro;

public: //Estos Metodos publicos, son la parte de la classe que se puede modificar en el trascurso del codigo. //Atributos son variables y metoods son funciones

    // constructor Crea e inicializa la classe BarquitosRC que es un objeto. en este caso inicializa Nombre que es un atributo.
    BarquitosRC(std::string pNombre);

    // getters Son atributopublicos que sirven para modificar Atributos privados, pero sin necesidad de acceder a ellos directamente.
    std::string getNombre();
    int getVelocidad();
    int getDistanciaRecorrida();
    int getNitro();

    // setters Son métodos públicos que permiten modificar el valor de un atributo privado de una clase. 
    void setNombre(std::string pNombre);
    void setVelocidad(int pVelocidad);
    void setDistanciaRecorrida(int pDistanciaRecorrida);
    void setNitro(int pNitro);
    /*los getters se utilizan para acceder a la información de una clase,
     mientras que los setters se utilizan para modificar la información de una clase.*/
    
    // otros métodos
    void calcularDistanciaRecorrida();
    void usarNitro();
};