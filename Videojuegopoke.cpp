#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>


using namespace std;


//Atributos del enemigo
int enemyHP = 600;
string enemyName = "Reshiram";
bool enemyIsAlive = true;
//int enemyDamage;


//Atributos del enemigo2  
int enemyHP2 = 600;
string enemyNamee = "Kyurem";
bool enemyIsAlivee = true;
//int enemyDamage2;


//Atributos de héroe
string heroName;
int heroDamage;
int heroHP = 200;
bool heroIsAlive = true;


void iniciarpartida() { //////////////////////////////////////////////////////////////////////////////////////
    cout << "Alerta, dos legendarios " << enemyName << " y " << enemyNamee << " acaban de aparecer!!! y ambos tienen " << enemyHP << " y " << enemyHP2 << " PS\n";
    cout << "Ha que Pokemon eliges?\n";
    cin >> heroName;
    cout << "El nombre del Pokemon es (--" << heroName << "--) \n";


    cout << "Escoge a que enemigo atacar! \n";
}
int option = 0;
void SLECTenemy() { ////////////////////////////////////////////////////////////////////////////////////////////
    if (enemyIsAlive && enemyIsAlivee) {
        cout << " (--1--) " << enemyName << " (--2--) " << enemyNamee << "\n";
        //cin >> option;
    }
    if (!enemyIsAlive && enemyIsAlivee) {
        cout << "Vamossss solo queda el " << enemyIsAlivee << "(--2--) \n";
        //cin >> option;
    }
    if (enemyIsAlive && !enemyIsAlivee) {
        cout << "Animoooo solo queda el " << enemyIsAlive << "(--1--) \n";
        //cin >> option;
    }
    cin >> option;
}

int enemyAttack(int damage) {
    int points;


    return heroHP - damage;
}

int enemyAttack2(int damage2) {
    int points;


    return heroHP - damage2;
}

bool checkheroIsAlive() {
    if (heroHP <= 0) {
        cout << "Tu Pokemon se ha debilitado, acude a un centro pokemon\n";
        heroHP = 0;
        return false;
        //enemyIsAlive = false;
    }
    
}
int main() {

    PlaySound(TEXT("pok.wav"), NULL, SND_LOOP | SND_ASYNC);

    srand(time(NULL));

    iniciarpartida();

    while (heroHP && (enemyIsAlivee || enemyIsAlive)) {
        //enemyDamage = 15 + rand() % 100;
        //enemyDamage2 = 15 + rand() % 100;

        SLECTenemy();

        switch (option)
        {
        case 1:
            if (enemyIsAlive)
            {
                cout << "Cuanto dayo quieres hacer a " << enemyName << " ?\n";
                cin >> heroDamage;
                enemyHP = enemyHP - heroDamage;
                if (enemyHP <= 0)
                {
                    cout << "El  " << enemyName << ", se ha debilitado, bien echo!!!\n";
                    enemyIsAlive = false;
                }
                else
                {
                    cout << "Al legendario " << enemyName << " le quedan " << enemyHP << " PS\n";
                }
                break;
            }
            else
            {
                cout << "El legendario se ha protegido \n";
            }
            break;
        case 2:
            if (enemyIsAlivee)
            {
                cout << "Cuanto dayo quieres hacer a " << enemyNamee << " ?\n";
                cin >> heroDamage;
                enemyHP2 = enemyHP2 - heroDamage;
                if (enemyHP2 <= 0)
                {
                    cout << "Critico!!! y debilitado!!! " << enemyNamee << "\n";
                    enemyIsAlivee = false;
                }
                else
                {
                    cout << "Al legendario " << enemyNamee << " le quedan " << enemyHP2 << " PS\n";
                }
                break;
            }
            else
            {
                cout << "El rival ha evitado tu ataque, y se sube la velocidad \n";
            }
            break;
        default: cout << "Cuidado entrenador!!! esto es un combate doble entre tu pokemon y los legendarios (--1--) y (--2--), esta vez has perdido un turno... \n";

        }


         if (enemyIsAlive) {
            heroHP = enemyAttack(15 + rand() % 16);
            cout << "El enemigo " << enemyName << " te ha atacado y te quedan " << heroHP << " puntos de vida\n";
        }

        checkheroIsAlive();



        if (enemyIsAlive) {
            heroHP = enemyAttack2(15 + rand() % 16);
            cout << "El enemigo " << enemyNamee << " te ha atacado y te quedan " << heroHP << " puntos de vida\n";
        }

        checkheroIsAlive();
    }

}
